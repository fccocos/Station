#include <iostream>
#include "creator.h"
#include "process.h"
#include <string>
using namespace std;

void test01()
{
   string end=string();
   cout<<"input \"start\" to launch "<<endl;
   cin>>end;
   while(end.compare("end")!=0)
   {
       end.clear();
       cout<<"input \"A\"or\"B\"o\"end\""<<endl;
       cin>>end;
      if(end.compare("A")==0)
      {
          Creator* createA = new ConcreteProuductA();
          createA->doOthersSomething();//业务相关的核心逻辑
      }
      if(end.compare("B")==0)
      {
          Creator* createB = new ConcreteProuductB();
          createB->doOthersSomething();//业务相关的核心逻辑
      }
   }
}

int main()
{
    test01();
    return 0;
}
