#include "mysem.h"

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
#include <error.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
key_t key=0;
const char* path="/mnt/f/Station/Linux_Proj/vscodeProj/process/sem/ipc/msg";
sem_t semid=0;
int value=0;

//套件初始化回调函数
int init_suite()
{
    key = ftok(path, 'e');
    if(key == -1)
    {
        perror("ftok_err");
        CU_ASSERT_EQUAL(key, -1);

        return -1;
    }
    
    semid = CreateSem(key, 100);
    if(semid==-1)
    {
        perror("CreateSem_err");
        CU_TEST(semid);
    } 

    return 0;
}

//套件清理函数
int clean_suite()
{
    DestorySem(semid);
    return 0;
}


void testSem_P()
{
  Sem_P(semid);
}

void testSem_V()
{
   Sem_V(semid);
}


void testSetvalueSem()
{
    SetvalueSem(semid, 70);
}

void testGetvalueSem()
{
   value  = GetvalueSem(semid);
   CU_ASSERT(value);
   CU_ASSERT_EQUAL(value, 100);
   CU_ASSERT_EQUAL(value, 70);
   CU_ASSERT_NOT_EQUAL(value, 100);
   CU_ASSERT_NOT_EQUAL(value,70);
   printf("\n\t信号量的值为%d\n",value);
}


CU_TestInfo Group1[]={
    {"testSem_P_1", testSem_P},
    {"testSem_V_1", testSem_V},
    {"testSem_P_2", testSem_P},
    {"testSem_V_2", testSem_V},
    {"testSem_P_3", testSem_P},
    {"testSem_V_3", testSem_V},
    {"testSem_P_4", testSem_P},
    {"testSem_V_4", testSem_V},
    {"testGetvalueSem", testGetvalueSem},
      CU_TEST_INFO_NULL,
};
CU_TestInfo Group2[]={
    {"testSetvalueSem", testSetvalueSem},
    {"testGetvalueSem", testGetvalueSem},
      CU_TEST_INFO_NULL,
};

CU_TestInfo Group3[]={
    {"testSem_P_1", testSem_P},
    {"testSem_P_2", testSem_P},
    {"testSem_P_3", testSem_P},
    {"testSem_P_4", testSem_P},
    {"testGetvalueSem", testGetvalueSem},
      CU_TEST_INFO_NULL,
};

CU_TestInfo Group4[]={
    {"testSem_V_1", testSem_V},
    {"testSem_V_2", testSem_V},
    {"testSem_V_3", testSem_V},
    {"testSem_V_4", testSem_V},
    {"testGetvalueSem", testGetvalueSem},
      CU_TEST_INFO_NULL,
};

CU_TestInfo Group5[]={
    {"testSetvalueSem", testSetvalueSem},
    {"testSem_P_1", testSem_P},
    {"testSem_P_2", testSem_P},
    {"testSem_P_3", testSem_P},
    {"testSem_P_4", testSem_P},
    {"testGetvalueSem", testGetvalueSem},
      CU_TEST_INFO_NULL,
};

CU_TestInfo Group6[]={
    {"testSetvalueSem", testSetvalueSem},
    {"testSem_V_1", testSem_V},
    {"testSem_V_2", testSem_V},
    {"testSem_V_3", testSem_V},
    {"testSem_V_4", testSem_V},
    {"testGetvalueSem", testGetvalueSem},
      CU_TEST_INFO_NULL,
};

CU_SuiteInfo suites[]={
    {"suite1",init_suite, clean_suite, NULL, NULL, Group1},
    {"suite2",init_suite, clean_suite, NULL, NULL, Group2},
    {"suite3",init_suite, clean_suite, NULL, NULL, Group3},
    {"suite4",init_suite, clean_suite, NULL, NULL, Group4},
    {"suite5",init_suite, clean_suite, NULL, NULL, Group5},
    {"suite6",init_suite, clean_suite, NULL, NULL, Group6},
      CU_SUITE_INFO_NULL,
};

void AddTest()
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
    
    //setting automated mode
    CU_set_output_filename("testMysem");
    CU_list_tests_to_file();
    CU_automated_run_tests();

    //清理注册表
    CU_cleanup_registry();

    // key_t key;
    // sem_t id;
    // key = ftok(path, 'a');

    // semid = CreateSem(key,100);
    // for(int i=0; i<=3;i++)
    //     Sem_P(semid),Sem_V(semid);
    // value = GetvalueSem(semid);
    // printf("信号量的值为:%d\n",value);
    // DestorySem(semid);

    return 0;

}