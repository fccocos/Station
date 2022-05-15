#include <iostream>
#include "MyString.h"

int main(int argc, char* agrv[])
{
	MyString* str = new MyString("这是一个字符");
	std::cout << "*str = " << *str << std::endl;
	*str = "中国人";
	std::cout << "*str = " << *str << std::endl;
	MyString p1("只是一个多姿多彩的世界");
	std::cout << "p1.m_Size = " << p1.getSize() << std::endl;
	MyString p2(p1);
	std::cout << "p1 = " << p1 << " p2 = " << p2 << std::endl;
	MyString p3(p1);
	p3 = " ,越是绚丽就越是荆棘遍地，让人心生畏惧";
	std::cout << p2 << p3 << std::endl;
	MyString p4;
	//将p2和p3进行拼接并赋值给p4
	p4 = p2 + p3;
	std::cout << "p4 = [" << p4 << "]" << std::endl;
	if (p1 == p2)
		std::cout << "p1==p2" << std::endl;
	if (p3 == p4)
		std::cout << "p3==p4" << std::endl;
	else std::cout << "p3!=p4" << std::endl;
	std::cout << "为p1输入一串字符" << std::endl;
	std::cin >> p1;
	std::cout << "p1 = [" << p1 << "]" << std::endl;

}