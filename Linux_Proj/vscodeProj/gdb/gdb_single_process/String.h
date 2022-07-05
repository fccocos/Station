#ifndef _STRING_H_
#define _STRING_H_
#include <ostream>  
#include <istream>
#define MAXSIZE (4*1024)
class String
{

  friend std::ostream& operator<<(std::ostream& cout,String& str);
  friend std::istream& operator>>(std::istream& cin, String& str);
public:
  String();
  String(const char* str);
  String(String& pstr);
  ~String();
  size_t getLen();//获取字符串的长度
  String* splitStr(char ch );//分割字符串
  String* splitStr(char* str);
  bool isNull(){ return this->base?false:true;}
  void clear();

  String& operator=(const char* str);//重载赋值运算符
  String& operator=(const String& str);

  String& operator+(const char* str);//重载拼接运算符
  String& operator+(const String& str);
  bool operator==(const char* str);//重载等号运算符
  bool operator==(const String& str);
private:
  size_t len=0;
  char* base=NULL;
  size_t size=0;
};

#endif 
