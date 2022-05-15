#ifndef MYSTRING_H
#define MYSTRING_H
#define _CRT_SECURE_NO_WARNINGS
#include <ostream>
#include <istream>
class MyString
{
	friend std::ostream& operator<<(std::ostream& cout, MyString& str);
	friend std::istream& operator>>(std::istream& cin, MyString& str);
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();

	//重载[]
	char& operator[](int index);

	//重载+ 拼接符
	MyString operator+(const char* str);
	MyString operator+(const MyString& str);

	//重载= 赋值号
	MyString& operator=(const char* str);
	MyString& operator=(const MyString& str);

	//重载== 比较符
	bool operator==(const char* str);
	bool operator==(const MyString& str);

	int getSize() { return this->m_Size; }

private:
	char* pString;
	int m_Size;

};

#endif // !MYSTRING_H



