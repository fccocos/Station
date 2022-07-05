#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

static void InsertSort(int *arr,int len)
{
  int* p=NULL;
  int* q=NULL;
  for(p=arr+1; p<arr+len; ++p)
  {
     if(*p<*(p-1))
     {
        int tmp=*p;
        for(q=p-1;q>=arr; --q)
           *(q+1) = *q;
        *(q+1) = tmp;
     }   
  }
      
}


static void swap(int* a, int* b)
{
  int temp=0;
  temp = *a;
  *a = *b;
  *b = temp;
}

static void BubbleSort(int *arr)
{
  int* p=NULL;
  int* q=NULL;
  int len = 0;
  q=arr;
  while(q++) len++;
  for(q=(arr+len); q>=arr; q--)
  {
    for(p=arr; (p+1)<q; p++)
    {
      if(*p>*(p+1))
      {
        swap(p, p+1);
      }
    }
  }
}

int main()
{
  int mpid,cpid;
  //主进程做插入排序
  //子进程做选择排序
  int sort[12]={8,3,43,12,34,534,56,0,123,44,32,34};
  int ret = fork();
  if(ret>0)
  {
    mpid = getpid();
    int ppid = getppid();//获取父进程号
    InsertSort(&sort[0],12);
    printf("mpid=%d, ppid=%d\n",mpid, ppid);
    for(int i=0; i<12; i++)
      printf("%d\n", sort[i]),sleep(1);
    
  }
  else
  {
    cpid = getpid();
    int ppid = getppid();
    printf("cpid=%d, ppid=%d\n",cpid, ppid);
    BubbleSort(sort);
    int* i=sort;
    for(int i=0; i<12; i++)
      printf("%d\n", sort[i]),sleep(1);
  }
 return 0;
}
