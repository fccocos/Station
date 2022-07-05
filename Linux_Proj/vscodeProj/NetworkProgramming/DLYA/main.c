#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#include <arpa/inet.h>

#include <unistd.h>

#define IFNAME "eth0"

int main(int argc, char *argv[])
{
    int fd;
    /*捕獲鏈路以太網幀，但需要獲取超級權限*/
    fd = socket(AF_INET, SOCK_PACKET, htons(0x0003));
    if (fd == -1)
    {
        perror("socket");
        exit(1);
    }

    char *ethname = IFNAME;
    /*將網卡接口設置為混雜模式*/
    struct ifreq ifr;
    strcpy(ifr.ifr_name, ethname);
    int ret = ioctl(fd, SIOCGIFFLAGS, &ifr);
    if (ret == -1)
    {
        perror("ioctl::SIOCGIFFLAGS");
        exit(0);
    }
    /*在保存現有設置的情況下，設置為混雜模式*/
    ifr.ifr_flags |= IFF_PROMISC;

    /*設置flags*/
    ret = ioctl(fd, SIOCSIFFLAGS, &ifr);
    if (ret == -1)
    {
        perror("ioctl::SIOCSIFFLAGS");
        exit(0);
    }

    /*获取以太网帧协议中的信息*/
    char eth_buf[ETH_FRAME_LEN];
    struct ethhdr *pethhder;
    int n;
    pethhder = (struct echhdr *)eth_buf;
    /*从fd中获取以太网帧*/
    read(fd, eth_buf, ETH_FRAME_LEN);
    /*打印以太网帧头信息*/
    printf("dest MAC: ");
    for (int i = 0; i < ETH_ALEN - 1; i++)
        printf("%02x-", pethhder->h_dest[i]);
    printf("%02x\n", pethhder->h_dest[ETH_ALEN - 1]);

    printf("source MAC: ");
    for (int i = 0; i < ETH_ALEN - 1; i++)
        printf("%02x-", pethhder->h_source[i]);
    printf("%02x\n", pethhder->h_source[ETH_ALEN - 1]);

    printf("protocol number: 0x%04x\n", pethhder->h_proto);

    /*获取以太网帧的数据部分*/
    char *data = (eth_buf + ETH_HLEN);
    printf("%s\n", data);
    /*判断以太网帧中携带的数据是否是IP数据报*/
    if (htons(pethhder->h_proto) == 0x0800)
    {
        /*定位IP头部*/
        struct iphdr *piphdr;
        piphdr = (struct iphdr *)(eth_buf + ETH_HLEN);
        /*打印IP头部相关信息*/
        printf("ip头部长度: 0x%04x\n", piphdr->ihl);
        printf("ip版本号: 0x%04x\n", piphdr->version);
        printf("ip服务类型: 0x%04x\n", piphdr->tos);
        printf("ip总长度: 0x%04x\n", piphdr->tot_len);
        printf("ip标识: 0x%04x\n", piphdr->id);
        printf("ip片偏移: 0x%04x\n", piphdr->frag_off);
        printf("ip's TTL: 0x%04x\n", piphdr->ttl);
        printf("ip's proto: 0x%04x\n", piphdr->protocol);
        printf("ip's check: 0x%04x\n", piphdr->check);
        char saddrb[16] = {0};
        inet_ntop(AF_INET, &piphdr->saddr, saddrb, 16);
        char daddrb[16] = {0};
        inet_ntop(AF_INET, &piphdr->daddr, daddrb, 16);
        printf("ip's saddr: %s\n", saddrb);
        printf("ip's daddr: %s\n", daddrb);
        /*
        要想获得IP数据报的数据，就要定义一个指针指向数据部分
        偏移量：IP头部长度 + IP选项长度（3timesIP头部长度）
        */

        char* app_data = NULL;
        int app_len = 0;
        /*判断IP数据报携带的数据类型*/
        if (piphdr->protocol == 6) // TCP
        {
            /*获取TCP头部*/
            struct tcphdr *ptchdr = (struct tcphdr *)(piphdr + piphdr->ihl * 4);
            /*打印源端口*/
            printf("src port: %d\n", ntohs(ptchdr->source));
            /*打印目的端口*/
            printf("dest port: %d\n", ntohs(ptchdr->dest));
            /*获取TCP协议部分的应用数据地址*/
            app_data = ptchdr+20;
            /*获取数据长度 = 以太网帧协议长度- 以太网帧首部长度 - ip首部 - ip选项 - tcp首部*/
            app_len = n - 16 - piphdr->ihl*4 - 20;
        }
        else if (piphdr->protocol == 17)
        {
            /*获取UDP头部*/
            struct udphdr *pudphdr = (struct updhdr *)(piphdr + piphdr->ihl * 4);
            /*打印源端口*/
            printf("src port: %d\n", ntohs(pudphdr->source));
            /*打印目的端口*/
            printf("dest port: %d\n", ntohs(pudphdr->dest));
            /*获取UDP协议部分的应用数据地址*/
            app_data = pudphdr + pudphdr->len;
            app_len = n - 16 - piphdr->ihl*4 - pudphdr->len;
        }

        printf("application data address:0x%s, length: %d\n", app_data, app_len);
    }
}
