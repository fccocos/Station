#include "RBTree.hpp"
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char* argv[])
{
	RBTree<int, std::string>* tree = new RBTree<int, std::string>;
	tree->insert(1, "���������ϵͳ");
	tree->insert(2, "���������");
	tree->insert(3, "��������ԭ��");
	tree->insert(4, "��ѧ");
	tree->insert(5, "Ӣ��");
	tree->insert(6, "����");
	tree->show();
	cout << "*************************" << endl;
	tree->reverse_show();
	cout << "*********************" << endl;
	cout << "ɾ����������" << endl;
	cout << endl;
	tree->remove(5);
	tree->show();
}