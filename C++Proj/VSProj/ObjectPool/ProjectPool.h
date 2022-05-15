#pragma once

template <class T, int num>
class ProjectPool
{

	//声明两个内嵌类
    //对象节点类，用于存放对象
	struct ObjectNode
	{
		T obj;//模板类对象
		ObjectNode* next_node;//指向下一个对象节点
		bool isFree; //用于判定该节点是否为空
	};

	//对象块类
	struct ObjectBlock
	{
		ObjectBlock* next_block;//指向下一个块对象
		ObjectNode* nodes;//对象节点指针用于指向一个对象节点数组}
	};
public:
	static ProjectPool<T,num>* getPoolInstance()
	{
		return proPtr;
	}
	T& getProject()
	{
		
	}
private:
	void InitMemery()
	{
		m_firstBlock = new ObjectBlock();
	}

	void NodeAddrAddOne()
	{
		if (m_firstFreeNode >= m_lastFreeNode)
		{
			ObjectBlock* newBlock = new ObjectBlock();
			m_curBlock->next_block = newBlock;
			m_curBlock = m_curBlock->next_block;
			m_firstBlock = m_curBlock->nodes;
			m_lastFreeNode = m_cur

			
		}
		
	}
	static ProjectPool<T,num>* proPtr;
	ProjectPool<T,num>() {}
	ProjectPool<T, num>(ProjectPool& in) {}
	ObjectBlock* m_firstBlock;//指向的一个块对象
	ObjectBlock* m_curBlock;//指向当前的块对象
	ObjectNode* m_firstFreeNode;//指向第一个空闲指针
	ObjectNode* m_lastFreeNode;//指向最后一个空闲指针
	int usingObjects;//当前使用的对象节点数

};
template <class T, int num>
ProjectPool<T, num>* ProjectPool<T, num>::proPtr = new ProjectPool<T,num>;