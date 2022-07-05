#ifndef TEST_H
#define TEST_H
#include "RBTree.h"
#include <string>
#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TextTestRunner.h>
class RBTreeTest : public CppUnit::TestCase {
public:
	void runTest()
	{
		RBTree<int, std::string>* tree = new RBTree<int, std::string>;
		tree->insert(1, "���������ϵͳ").insert(2, "���������").insert(3, "��������ԭ��");
		tree->insert(4, "��ѧ").insert(5, "Ӣ��").insert(6, "����");
		
	    CPPUNIT_ASSERT_MESSAGE("����������硷�ں������", tree->hasKeyValue("���������"));
		
	}
};

#endif
