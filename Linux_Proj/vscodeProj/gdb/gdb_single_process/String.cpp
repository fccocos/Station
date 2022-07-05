
#include "String.h"
#include <cstring>
#include <iostream>

#ifndef ARRAY_DEFAULT_SIZE
#define ARRAY_DEFAULT_SIZE 512
#endif

static char *clear_front_behind_space(const char *str)
{
  char *tmp_str = new char[strlen(str) + 1];
  memset(tmp_str, 0, strlen(str) + 1);
  strcpy(tmp_str, str);
  *(tmp_str + strlen(str) + 1) = '\0';
  char *start, *end;
  int len = strlen(str);
  start = tmp_str;
  while (*start == ' ' && *start != '\0')
  {
    *start = '\0';
    start++;
  }
  end = tmp_str + len - 1;
  while (*end == ' ' && *end != '\0')
  {
    *end = '\0';
    end--;
  }
  return start;
}

std::ostream &operator<<(std::ostream &cout, String &str)
{
  cout << str.base;
  return cout;
}
std::istream &operator>>(std::istream &cin, String &str)
{
  cin >> str.base;
  return cin;
}
String::String() {}
String::String(const char *str)
{
  size_t len = strlen(str);
  this->size = len + 1;
  this->len = len;
  this->base = new char[size];
  strcpy(this->base, str);
  *(this->base+this->size) = '\0';
}
String::String(String &pstr)
{
  this->len = pstr.len;
  this->size = pstr.size;
  this->base = new char[this->size];
  strcpy(this->base, pstr.base);
}
String::~String()
{
  if (this->base != NULL)
  {
    delete this->base;
    this->base = NULL;
  }
}
size_t String::getLen() //获取字符串的长
{
  return this->len;
}
String *String::splitStr(char ch) //分割字符
{
  String *tmp_str = new String(*this);
  String *strArr = new String[ARRAY_DEFAULT_SIZE];
  int count = 0;
  if (base != NULL)
  {
    char *start = NULL;
    char*end = NULL;
    end = tmp_str->base;
    start = tmp_str->base;
   
    while (*end != '\0')
    {
      if (*end == ch)
      {
        *end = '\0';
        String newStr(clear_front_behind_space(start));
        strArr[count++] = newStr;
        start = end + 1;
      }
      end++;
    }
    String newStr(clear_front_behind_space(start));
    strArr[count++] = newStr;

    return strArr;
  }
  else
  {
    std::cerr << "字符串为空串，无法处理" << std::endl;
    return NULL;
  }
}

String *String::splitStr(char *str)
{
  //使用朴素模式匹配
  String *tmp_str = new String(*this);
  String *strArr = new String[ARRAY_DEFAULT_SIZE];
  int count = 0;
  if (base != NULL)
  {
    int step = strlen(str) - 1;
    char *mainStrEnd = tmp_str->base;
    char *mainStrStart = tmp_str->base;
    char *modeStrEnd = str;
    char *modeStrStart = str;
    while (*mainStrEnd != '\0')
    {
      if (*mainStrEnd == *modeStrEnd)
      {
        modeStrEnd++;
        mainStrEnd++;
        if (*(modeStrEnd + 1) == '\0')
        {
          modeStrEnd = modeStrStart;
          *(modeStrEnd - step) = '\0';
          strArr[count++] = String(clear_front_behind_space(mainStrStart));
          mainStrStart = mainStrEnd + 1;
        }
      }
      else
      {
        modeStrEnd = modeStrStart;
        mainStrEnd++;
      }
    }
    return strArr;
  }
  else
  {
    std::cerr << "字符串为空串；无法处理" << std::endl;
    return NULL;
  }
}

void String::clear()
{
  memset(this->base, 0, this->len);
  this->len = 0;
}

String &String::operator=(const char *str) //重载赋值运算
{
  if (this->base != NULL)
  {
    if (this->size < strlen(str) + 1)
    {
      delete this->base;
      this->base = new char[strlen(str) + 1];
      this->len = strlen(str);
      this->size = strlen(str) + 1;
    }
  }
  else
  {
    this->base = new char[strlen(str) + 1];
    this->len = strlen(str);
    this->size = strlen(str) + 1;
  }

  memset(this->base, 0, this->size);
  strcpy(this->base, str);

  return *this;
}
String &String::operator=(const String &str)
{
  if (this->base != NULL&&this->size < str.size)
  {
      delete this->base;
      this->base = new char[str.size];
      this->len = str.len;
      this->size = str.size;
  }
  if(this->base == NULL)
  {
    this->base = new char[str.size];
    this->len = str.len;
    this->size = str.size;
  }
  //如果this和str指向同一块内存，直接返回
  if(&str == this) return *this;

  memset(this->base, 0, this->size);
  this->size = str.size;
  this->len = str.len;
  strcpy(this->base, str.base);
  return *this;
}
String &String::operator+(const char *str) //重载拼接运算
{
  if (this->base == NULL)
  {
    this->base = new char[strlen(str)];
    this->len = strlen(str);
    this->size = strlen(str) + 1;
    memset(this->base, 0, this->size);
    strcpy(this->base, str);
  }
  else
  {
    this->base = strcat(this->base, str);
    this->len += strlen(str);
    this->size += strlen(str);
  }
  return *this;
}
String &String::operator+(const String &str)
{

  if (this->base == NULL)
  {
    this->base = new char[str.size];
    this->len = str.len;
    this->size = str.size;
    memset(this->base, 0, this->size);
    strcpy(this->base, str.base);
  }
  else
  {
    this->base = strcat(this->base, str.base);
    this->len += str.len;
    this->size += str.size;
  }
  return *this;
}
bool String::operator==(const char *str) //重载等号运算
{
  if (!strcmp(this->base, str))
    return true;
  return false;
}
bool String::operator==(const String &str)
{
  if (!strcmp(this->base, str.base))
    return true;
  return false;
}
