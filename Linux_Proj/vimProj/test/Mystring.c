
#include "Mystring.h"

int StrLen(char* str)
{
  int len=0;
  while(*str++!='\0') len++;
  return len;
}
