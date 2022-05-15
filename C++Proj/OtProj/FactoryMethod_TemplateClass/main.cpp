#include <iostream>
#include "creator.hpp"
#include "product.hpp"
#include <string>
using namespace std;

struct Attribute_Str
{
   enum{off,on=1};
   string productName = "Xiaomi";
   int status =on;
   string CPU = "Xiaolong 855";
   string mem = "flash";
   void print()
   {
       cout<<"*****************************"<<endl;
       cout<<"name: "<<productName<<endl;
       cout<<"status: "<<status<<endl;
       cout<<"CPU: "<<CPU<<endl;
       cout<<"memory: "<<mem<<endl;
       cout<<"****************************"<<endl;
   }

};

void test01()
{
   string end=string();
   cout<<"input \"start\" to launch "<<endl;
   cin>>end;
   while(end.compare("end")!=0)
   {
       end.clear();
       cout<<"input \"Xiaomi\"or\"Huwei\"o\"end\""<<endl;
       cin>>end;
      if(end.compare("Xiaomi")==0)
      {
          Creator<Attribute_Str>* plantXiaomi = new ConcreteProductA<Attribute_Str>();
          Attribute_Str xiaomi_attri;
          plantXiaomi->setAttri(xiaomi_attri);
          plantXiaomi->showCreator().print();
          plantXiaomi->showProduct().print();

      }
      if(end.compare("Huwei")==0)
      {
          Creator<Attribute_Str>* plantHuawei = new ConcreteProductB<Attribute_Str>();
          Attribute_Str Huawei_attri;
          Huawei_attri.productName = "Huawei";
          Huawei_attri.CPU = "Qilin 970";
          plantHuawei->setAttri(Huawei_attri);
          plantHuawei->showCreator().print();
          plantHuawei->showProduct().print();

      }
   }
}


int main()
{



   test01();
    return 0;
}
