#pragma once

template <class T, int num>
class ProjectPool
{

	//����������Ƕ��
    //����ڵ��࣬���ڴ�Ŷ���
	struct ObjectNode
	{
		T obj;//ģ�������
		ObjectNode* next_node;//ָ����һ������ڵ�
		bool isFree; //�����ж��ýڵ��Ƿ�Ϊ��
	};

	//�������
	struct ObjectBlock
	{
		ObjectBlock* next_block;//ָ����һ�������
		ObjectNode* nodes;//����ڵ�ָ������ָ��һ������ڵ�����}
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
	ObjectBlock* m_firstBlock;//ָ���һ�������
	ObjectBlock* m_curBlock;//ָ��ǰ�Ŀ����
	ObjectNode* m_firstFreeNode;//ָ���һ������ָ��
	ObjectNode* m_lastFreeNode;//ָ�����һ������ָ��
	int usingObjects;//��ǰʹ�õĶ���ڵ���

};
template <class T, int num>
ProjectPool<T, num>* ProjectPool<T, num>::proPtr = new ProjectPool<T,num>;