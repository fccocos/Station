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
		tree->insert(1, "计算机操作系统").insert(2, "计算机网络").insert(3, "计算机组成原理");
		tree->insert(4, "数学").insert(5, "英语").insert(6, "语文");
		
	    CPPUNIT_ASSERT_MESSAGE("《计算机网络》在红黑树中", tree->hasKeyValue("计算机网络"));
		
	}
};

#endif
