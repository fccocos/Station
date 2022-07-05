#include "msgqueue.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*打开消息队列，如果消息不存在则创建一个消息队列*/
int OpenMsgque(const char *path)
{
    key_t key = ftok(path, 'd');
    if (key == -1)
    {
        perror("ftok_err");
        exit(EXIT_FAILURE);
    }

    int msgflag = IPC_CREAT; // | IPC_EXCL;
    int msgid = msgget(key, msgflag);
    if (msgid == -1)
    {
        perror("mssgget_err");
        return msgid;

    }
    return msgid;
}

/*在消息队列中获取消息*/
void ReadMsgInQue(int msgid, struct msg_buf buf)
{
    int ret = msgrcv(msgid, &buf, strlen(buf.mtext), 10, IPC_NOWAIT);
    if (ret == -1)
    {
        perror("msgrcv_err");
        //exit(EXIT_FAILURE);
    }
}
/*在消息队列中写消息*/
void WriteMsgInQue(int msgid, struct msg_buf buf)
{
    int ret = msgsnd(msgid, &buf, strlen(buf.mtext), IPC_NOWAIT);
    if (ret == -1)
    {
        perror("msgsnd_err");
       // exit(EXIT_FAILURE);
    }
}
/*控制消息队列*/
void CtlQue(int msgid, int cmd, struct msqid_ds *buf)
{
    int ret = msgctl(msgid, cmd, buf);
    if (ret == -1)
    {
        perror("msgctl_err");
       // exit(EXIT_FAILURE);
    }
}

/*显示小队列的权限信息*/
void msg_show_attr(int msgid, struct msqid_ds buf)
{

    int ret = msgctl(msgid, IPC_STAT, &buf);
    if (ret == -1)
    {
        perror("msgctl_err");
       // exit(EXIT_FAILURE);
    }

    fprintf(stdout,
            "\n\n\t\tmsgqueue attribute permission" 
            "\n\tnbytes \tmsgs \tqbytes \tlspid \tlrpid \tlstime \tlrtime \tlctime \tuid \tgid"
            "\n\t%4ld \t%4d \t%4d \t%4d \t%4d \t%4s \t%4s \t%4s \t%4d \t%4d\n\n",
            buf.msg_cbytes,
            (int)buf.msg_qnum,       (int)buf.msg_qbytes,
            buf.msg_lspid,           buf.msg_lrpid,
            ctime(&(buf.msg_stime)), ctime(&(buf.msg_rtime)), ctime(&(buf.msg_ctime)),
            buf.msg_perm.uid,        buf.msg_perm.gid
            );
}