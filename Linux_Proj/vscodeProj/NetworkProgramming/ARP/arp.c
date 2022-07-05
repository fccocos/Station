/**
 * @file arp.c
 * @author gunfire (gunfirefc70@163.com)
 * @brief arp地址解析协议的实现
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * 预备知识 
 * 
 ***************************************************************************************************************************************************************************
 * arp协议格式
 * 
 * |<----------以太网帧头--------->|<----------------------------------------ARP请求或应答------------------------------------------------------------------------------->|
 *                                 |<-----------------------ARP协议头部------------------------------>|<------------------------ARP的请求或应答的数据部分---------------->|
 * source_MAC    dest_MAC    帧类型     硬件类型    协议类型    硬件地址长度    协议地址长度    操作方式    发送方硬件地址    发送方IP地址    接收方硬件地址     接收方IP地址
 *    6B            6B         3B          2B         2B            1B             1B             2B           6B               4B                 6B               4B
 *
 * ************************************************************************************************************************************************************************
 * 
 * **************************************************************
 * ARP协议头部数据结构
 * 
 * struct arphdr{
 *      __be16 ar_hrd;             // 硬件类型  其值为1
 *      __be16 ar_pro;             // 协议类型  其值为0x0800
 *      unsigned char ar_hln;      // 硬件地址长度  其值为6
 *      unsigned char ar_pln;      // 协议地址长度  其值为4
 *      __be16 ar_op;              // 操作码。 为1表示ARP请求
 * };
 * **************************************************************
 * 
 * **************************************************************
 * 自定义ARP数据包
 * 
 * struct arppacket{
 *      unsigned short ar_hrd;               // 硬件类型
 *      unsigned short ar_pro;               // 协议类型
 *      unsigned char ar_hln;                // 硬件地址长度
 *      unsigned char ar_pln;                // 协议地址长度
 *      unsigned short ar_op;                // 操作码
 *      unsigned char ar_sha[ETH_ALEN];      // 发送方MAC
 *      unsigned char* ar_sip;               // 发送方IP
 *      unsigned char ar_tha[ETH_ALEN];      // 目的MAC
 *      unsigned char* ar_tip;               // 目的IP
 * 
 * };
 * *******************************************************************
 * 
 * *******************************************************************
 * ARP请求的流程
 *  1. 定义一个以太网帧
 *  2. 获取以太网帧头部，定位以太网帧的数据部分
 *  3. 将源MAC和目的MAC赋值到以太网帧对应的字段中
 *  4. 设置协议类型
 *  5. 初始化ARP数据包
 *  6. 发送ARP数据报
 * ********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <errno.h>

/*定义ARP数据包*/
struct arppacket{
    /*arp协议头部*/
    unsigned short ar_hrd;
    unsigned short ar_pro;
    unsigned char ar_hln;
    unsigned char ar_pln;
    unsigned short ar_op;

    /*arp协议数据部分*/
    unsigned char ar_sha[ETH_ALEN];
    unsigned char* ar_sip;
    unsigned char ar_tha[ETH_ALEN];
    unsigned char* ar_tip;
};

int main(int argc, char* argv[])
{
    /*ethnet frame cache*/
    char ef_cache[ETH_FRAME_LEN]; // ETH_FRAME_LEN没有包含CRC
    /*ethnet frame header*/
    struct ethhdr *pethhdr;
    pethhdr = (struct ethhdr*) ef_cache;
    /*source_MAC and dest_MAC*/
    char dmac[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    char smac[ETH_ALEN] = {0x00, 0x15, 0x5d, 0x94, 0xbe, 0xfe};

    /*初始化套接字*/
    int fd  = socket(AF_INET, SOCK_PACKET, 0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }

    /*Initialize ethnet frame header*/
    memcpy(pethhdr->h_dest, dmac, ETH_ALEN);
    memcpy(pethhdr->h_source, smac, ETH_ALEN);
    pethhdr->h_proto = htons(0x0806); // 帧协议类型为ARP协议

    /*Define a ARP packet*/
    struct arppacket *parp;

    /*将parp指向ef_cache的数据部分*/
    parp = (struct arppacket*)(ef_cache+ ETH_ALEN);

    /*初始化arppacket*/
    parp->ar_hrd = htons(0x1);
    parp->ar_pro = htons(0x0800);
    parp->ar_hln = 6;
    parp->ar_pln = 4;
    parp->ar_op = 1;
    memcpy(parp->ar_sha, smac, ETH_ALEN);
    parp->ar_sip = (unsigned char*)inet_addr(" 172.18.209.47");
    memcpy(parp->ar_tha, dmac, ETH_ALEN);
    parp->ar_tip = (unsigned char*)inet_addr("192.168.31.1");

    /*发送ARP请求*/
    for(int i = 0; i<8; i++)
    {
        write(fd, ef_cache, ETH_FRAME_LEN);
        sleep(1);
    }
    close(fd);
    return 0;
      
}