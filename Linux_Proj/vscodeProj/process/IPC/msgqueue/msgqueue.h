#ifndef _MSGQUEUE_H_
#define _MSGQUEUE_H_
#include <sys/msg.h>
#define MSG_MTEXT_SIZE 10
/*
* 使用消息队列的步骤
* 0. 需要自定义个消息缓冲区的数据结构，其中的mtype成员必须与内核中的消息缓冲结构体中的mtype一致
* 1. ftok获取文件对应的systemv的键值
* 2. 用ftok获取的键值通过msgget函数来获取msgid
* 3. 用msgid来对消息队列进行消息的读写(msgsnd、msgrsv)和消息队列的修改（msgctl）
*/
struct msg_buf{
  int mtype;
  char mtext[MSG_MTEXT_SIZE];
};

/*打开消息队列，如果消息不存在则创建一个消息队列*/
int OpenMsgque(const char* path);

/*在消息队列中获取消息*/
void ReadMsgInQue(int msgid, struct msg_buf buf);
/*在消息队列中写消息*/
void WriteMsgInQue(int msgid, struct msg_buf buf);
/*控制消息队列*/
void CtlQue(int msgid, int cmd, struct msqid_ds* buf);

/*显示小队列的权限信息*/
void msg_show_attr(int msgid, struct msqid_ds buf);

#endif