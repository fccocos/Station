#include <iostream>
#include "MyString.h"

int main(int argc, char* agrv[])
{
	MyString* str = new MyString("����һ���ַ�");
	std::cout << "*str = " << *str << std::endl;
	*str = "�й���";
	std::cout << "*str = " << *str << std::endl;
	MyString p1("ֻ��һ�����˶�ʵ�����");
	std::cout << "p1.m_Size = " << p1.getSize() << std::endl;
	MyString p2(p1);
	std::cout << "p1 = " << p1 << " p2 = " << p2 << std::endl;
	MyString p3(p1);
	p3 = " ,Խ��Ѥ����Խ�Ǿ�����أ���������η��";
	std::cout << p2 << p3 << std::endl;
	MyString p4;
	//��p2��p3����ƴ�Ӳ���ֵ��p4
	p4 = p2 + p3;
	std::cout << "p4 = [" << p4 << "]" << std::endl;
	if (p1 == p2)
		std::cout << "p1==p2" << std::endl;
	if (p3 == p4)
		std::cout << "p3==p4" << std::endl;
	else std::cout << "p3!=p4" << std::endl;
	std::cout << "Ϊp1����һ���ַ�" << std::endl;
	std::cin >> p1;
	std::cout << "p1 = [" << p1 << "]" << std::endl;

}