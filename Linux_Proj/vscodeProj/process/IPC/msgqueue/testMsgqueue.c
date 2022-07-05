#include "msgqueue.h"
#include <string.h>
#include <stdio.h>
#include <error.h>
#include <assert.h>
#include <stdlib.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/CUError.h>

char*  path = "/mnt/f/Station/Linux_Proj/vscodeProj/process/msgqueue/ipc/msg/";
int msgid;
int ret;
struct msqid_ds buf_info;
struct msg_buf buf={10,"test msg"};

int init_suite(void)
{
    
    if(-1==(msgid=OpenMsgque(path)))
        return -1;
    else
    {
        msg_show_attr(msgid,buf_info);
        return 0;

    }
}

int clean_suite(void)
{
    if(-1 == msgctl(msgid, IPC_RMID, &buf_info))
    {
        perror("msgctl_err");
        return -1;
    }
    else 
    {
        msg_show_attr(msgid, buf_info);
        return 0;
    }
    
}

void testReadMsgInQue()
{
    ReadMsgInQue(msgid,buf);
    msg_show_attr(msgid,buf_info);
}

void testWriteMsgInQue()
{

    WriteMsgInQue(msgid, buf);
    msg_show_attr(msgid, buf_info);

}
void testCtlQue()
{
    buf_info.msg_perm.uid = 8;
    buf_info.msg_perm.gid = 8;
    buf_info.msg_qbytes = 12345;
    CtlQue(msgid, IPC_SET, &buf_info);
    msg_show_attr(msgid,buf_info);
}
//管理测试用例
CU_TestInfo tests[]={
    {"testWriteMsgInQue",testWriteMsgInQue},
    {"testReadMsgInQue", testReadMsgInQue},
    {"testCtlQue",testCtlQue},
      CU_TEST_INFO_NULL,
};

//管理套件
CU_SuiteInfo suites[]={
    {"oneSuite", init_suite, clean_suite,NULL,NULL, tests},
      CU_SUITE_INFO_NULL,
};

void AddTest(void)
{
    assert(NULL!=CU_get_registry());
    assert(!CU_is_test_running());

    /*注册套件*/
    if(CU_register_suites(suites)!=CUE_SUCCESS)
    {
        fprintf(stderr,"suite registration failed - %s\n",CU_get_error_msg());
        exit(EXIT_FAILURE);
    }
    
}

int main()
{
    CU_BasicRunMode mode = CU_BRM_VERBOSE;
    CU_ErrorAction err_action = CUEA_IGNORE;
    //初始化注册biao 
    if(CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    //把套件添加到注册表
    AddTest();

    //设置基本模式
    CU_basic_set_mode(mode);
    CU_set_error_action(err_action);
    
    //运行测试用例
    printf("\n Test completed with return value %d.\n", CU_basic_run_tests());
    
    //清理注册表
    CU_cleanup_registry();

    return 0;

}