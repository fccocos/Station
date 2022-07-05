#include "String.h"
#include <iostream>

using namespace std;

int main()
{

 String say_str("hello world");
 //获取字符长度
 int len=say_str.getLen();
 cout<<"say_str's len = "<<len<<endl;
 //分割字符
 String* substr = say_str.splitStr(' ');
while(!substr->isNull())
{
 cout<<*substr<<endl;
 substr++;
}

//赋值测试
 say_str = "hello String";
 cout<<"say_str="<<say_str<<endl;
 String obj_str(say_str);
 cout<<"obj_str="<<obj_str<<endl;
 say_str = obj_str;
 cout<<"say_str="<<say_str<<endl;
 //拼接测试

 String tt_str("center handler");
 say_str = say_str+tt_str;
 cout<<"say_str="<<say_str<<endl;

 //比较测
 if(say_str == obj_str)
 {
   cout<<"say_str == obj_str"<<endl;
 }else
 {
   cout<<"say_str!=obj_str"<<endl;
 }
 return 0;
}
