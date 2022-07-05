#include "RBTree.hpp"
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char* argv[])
{
	RBTree<int, std::string>* tree = new RBTree<int, std::string>;
	tree->insert(1, "计算机操作系统");
	tree->insert(2, "计算机网络");
	tree->insert(3, "计算机组成原理");
	tree->insert(4, "数学");
	tree->insert(5, "英语");
	tree->insert(6, "语文");
	tree->show();
	cout << "*************************" << endl;
	tree->reverse_show();
	cout << "*********************" << endl;
	cout << "删除操作测试" << endl;
	cout << endl;
	tree->remove(5);
	tree->show();
}