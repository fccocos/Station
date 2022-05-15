#include "RBTree.h"
#include <stdexcept>

template<class T1, class T2>
inline RBTree<T1, T2>::RBTree() {}


template<class T1, class T2>
RBTree<T1, T2>::~RBTree()
{
	if (this->root != NULL)
	{
		cleanUp(this->root);
		this->root = nullptr;
	}
}

template<class T1, class T2>
void RBTree<T1, T2>::clear()
{
	if (this->root != nullptr)
	{
		cleanUp(this->root);
		this->root = nullptr;
	}
}

/*
* @brief �ж��ں�������Ƿ���ָ��������
* @param keyΪ���������д�ŵļ�
* @return �ɹ�����true, ʧ�ܷ���false
*/
template<class T1, class T2>
bool RBTree<T1, T2>::hasKeyValue(const T1& key)
{
	RBNode* p = root;
	while (p != nullptr)
	{
		if (p->key == key) return true;
		p = (p->key > key ? p->rchild :p->lchild);
	}
	
	return false;
}

/*
* @brief �ж��ں�������Ƿ���ָ��������
* @param valΪ���������д�ŵ�ֵ
* @param count���ڷ���key�ĸ���
* @return �ɹ�����true, ʧ�ܷ���false
*/
template<class T1, class T2>
bool RBTree<T1, T2>::hasKeyValue(const T2& val)
{
	RBNode* p = root;
	//�ò���������������
	//����һ��ѭ������
	const int MAXSIZE = 64;
	RBNode* que[MAXSIZE];
	int front;//ָ���ͷ
	int rear;//ָ���β
	front = rear= 0;

	//front==rear��ʾ����Ϊ��
	//(rear+1)%MAXSIZE == front��ʾ��������

   //��root���뵽������
	rear = (rear + 1) % MAXSIZE;
	que[rear] = p;

	while (rear != front)
	{
		//����
		front = (front + 1) % MAXSIZE;
		RBNode node = que[front];

		if (node->val == val) return true;

		if (node->lchild != nullptr)
		{
			rear = (rear + 1) % MAXSIZE;
			que[rear] = node->lchild;
		}
		if (node->rchild != nullptr)
		{
			rear = (rear + 1) % MAXSIZE;
			que[rear] = node->rchild;
		}

	}

	return false;

}

/*
* @brief �жϵ�ǰ������Ƿ�Ϊ��
* @return ��Ϊ�շ���false, Ϊ�շ���true
*/
template<class T1, class T2>
bool RBTree<T1, T2>::empty()
{
	if (this->root == nullptr)
		return true;
	return false;
}

/*
* @brief ͨ��key����ȡval
* @param keyΪ��ֵ���еļ�
* @return �ɹ����ز���keyָ���ļ�ֵ���е�ֵ�����򷵻�nullptr
*/
template<class T1, class T2>
T2& RBTree<T1, T2>::getVal(const T1& key)
{
	RBNode* p = root;
	while (p != nullptr)
	{
		if (p->key == key) return p->val;
		p = (p->key > key ? p->rchild : p->lchild);
	}
	return nullptr;
}

/*
* @brief ͨ��val����ȡkey
* @param valΪ��ֵ���е�ֵ
* @return �ɹ����ز���valָ���ļ�ֵ���е�ֵ���飬���򷵻�nullptr
*/
template<class T1, class T2>
T1* RBTree<T1, T2>::getKey(const T2& val, int& count)
{
	RBNode* p = root;
	//�ò���������������
	//����һ��ѭ������
	const int MAXSIZE = 64;
	const int BUFSIZE = 1024;
	RBNode* que[MAXSIZE];
	T1 key_buf[BUFSIZE];
	int front,buf_front;//ָ���ͷ
	int rear,buf_rear;//ָ���β
	int buf_len;

	front = rear = 0;
	buf_len = buf_front = buf_rear = 0;
	

	//front==rear��ʾ����Ϊ��
	//(rear+1)%MAXSIZE == front��ʾ��������

   //��root���뵽������
	rear = (rear + 1) % MAXSIZE;
	que[rear] = p;

	while (rear != front)
	{
		//����
		front = (front + 1) % MAXSIZE;
		RBNode node = que[front];

		if (node->val == val)
		{
			buf_rear = (buf_rear + 1) % MAXSIZE;
			key_buf[buf_rear] = node->key;
			buf_len++;
			if ((rear + 1) % MAXSIZE == front)
				throw std::runtime_error("KEY_BUF was full.");
		}

		if (node->lchild != nullptr)
		{
			rear = (rear + 1) % MAXSIZE;
			que[rear] = node->lchild;
		}
		if (node->rchild != nullptr)
		{
			rear = (rear + 1) % MAXSIZE;
			que[rear] = node->rchild;
		}

	}

	if (buf_rear == buf_front)
	{
		throw std::runtime_error("KEY_BUF was empty,so there is not any key in the red black tree");;
		return nullptr;
	}

	count = buf_len;
		
	return key_buf;
	
}

/*
 * @brief ͨ��key��ָ�����������ɾ��
 * @param keyΪ��ֵ���еļ�
 * @return �ɹ����ص�ǰ���󣬷��򷵻�nullptr
 */
template<class T1, class T2>
RBTree<T1, T2>& RBTree<T1, T2>::reomve(const T1& key)
{
	return nullptr;
}

/*
* @brief ͨ��val��ָ�����������ɾ����ɾ����Ϊ�����ҵ�����һ����ڽ��
* @param valΪ��ֵ���е�ֵ
* @return �ɹ����ص�ǰ���󣬷��򷵻�nullptr
*/
template<class T1, class T2>
RBTree<T1, T2>& RBTree<T1, T2>::remove(const T2& val)
{

	return nullptr;
}

/*������*/
/*
* @brief ͨ��ָ����ֵ����������
* @param valΪ��ֵ���е�ֵ
* @param keyΪ��ֵ���еļ�
* @return �ɹ����ص�ǰ���󣬷��򷵻�nullptr
*/
template<class T1, class T2>
RBTree<T1, T2>& RBTree<T1, T2>::insert(const T1& key, const T2& val)
{
	RBNode* curNode = root;
	RBNode* curFather = nullptr;

	while (curNode != nullptr)
	{
		if (curNode->key == key)
		{
			curNode->val = val;
			return *this;
		}
		else
		{
			curFather = curNode;
			curNode = (key < curNode->key ? curNode->lchild : curNode->rchild);
		}
	}

	//���沿�ִ������ڴ����µĽ�㲢��������ݵĴ洢

	/*
	* ��ʱ,curNodeΪnullptr,currentFatherָ�����һ�α������Ľ��
	* ����ʱnewnodeΪ��ɫ������key�Ĵ�С�����뵽���һ������������������������
	*/
	
	/*�����½ڵ�*/
	curNode = new RBNode;
	curNode->parent = curFather;
	curNode->lchild = curNode->rchild = nullptr;
	curNode->key = key;
	curNode->val = val;

	/*�����Ϊ������ֱ�Ӳ����㣬����ɫ��ɺ�ɫ��*/
	if (curFather == nullptr)
	{
		curNode->color = NodeColor::BLACK;
		this->root = curNode;
		return *this;
	}

	//����½���keyС�ڵ�ǰ���curFather��key
	if (curNode->key < curFather->key)
		curFather->lchild = curNode;//���뵽curFather�����
	else curFather->rchild = curNode;//���뵽cruFather���ұ�
		curNode->parent = curFather;

		this->fixUpContinuousNodes(curNode);
	
	
	return *this;
}

//////////////////////////////////////////////////////////////////////

/*�ݹ�����ָ�����*/
template<class T1, class T2>
void RBTree<T1, T2>::cleanUp(RBNode* node)
{
	//������������ķ�ʽ��ɾ�����
	if (node->lchild != nullptr)
		cleanUp(node->lchild);

	delete node;

	if (node->rchild != nullptr)
		cleanUp(node->rchild);
}

/*����*/
template<class T1, class T2>
void RBTree<T1, T2>::rotateLeft(RBNode* node)
{
	RBNode* parent = node->parent;
	RBNode* left = node->lchild;
	RBNode* right = node->rchild;
	RBNode* rlgrandson = right->lchild;

	//�жϵ�ǰ���ĸ�����Ƿ�Ϊnullptr
	if (parent == nullptr)
	{
		root = node;
	}
	else {
		//�жϵ�ǰ����Ƿ�Ϊ����������
		if (parent->lchild == node)	 parent->lchild = right;
		if (parent->rchild == node) parent->rchild = right;
	}
	right->parent = parent;
	
	//����ǰ�����Һ��ӵ����ӽ�������
	//�����жϵ�ǰ�����Һ��ӵ������Ƿ����
	if (rlgrandson == nullptr) 
		node->rchild = nullptr;
	else
	{
		node->rchild = rlgrandson;
		rlgrandson->parent = node;
	}

}

/*�ҵ���*/
template<class T1, class T2>
void RBTree<T1, T2>::rotateRight(RBNode* node)
{
	RBNode* parent = node->parent;
	RBNode* left = node->lchild;
	RBNode* right = node->rchild;
	RBNode* lrgrandson = left->lchild;

	//�жϵ�ǰ���ĸ�����Ƿ�Ϊnullptr
		
	if (parent == nullptr)
	{
		root = node;
	}
	else {
		//�жϵ�ǰ����Ƿ�Ϊ����������
		if (parent->lchild == node)	 parent->lchild = left;
		//�жϵ�ǰ����Ƿ�Ϊ�������Һ���
		if (parent->rchild == node) parent->rchild = left;
	}

	left->parent = parent;
	
	//����ǰ�������ӵ��Һ��ӽ�������
	//�����жϵ�ǰ�������ӵ��Һ����Ƿ����
	if (lrgrandson == nullptr)
		node->lchild = nullptr;
	else
	{
		node->lchild = lrgrandson;
		lrgrandson->parent = node;
	}
}

/*�޸�"������ɫ���"*/
template<class T1, class T2>
void RBTree<T1, T2>::fixUpContinuousNodes(RBNode* node)
{
	RBNode* curNode = node;
	//ֻ�е�ǰ�����ɫΪ��ɫʱ���ΰ������ڸ��ڵ�Ϊ��ɫʱΥ�����������
	while (curNode->color == NodeColor::RED)
	{
		RBNode* curFather = node->parent;
		if (curFather == nullptr)
		{
			//curNode�Ǹ����
			curNode->color = NodeColor::BLACK;
			break;
		}
		else if(curFather->color == NodeColor::BLACK)
		{
			break;
		}

		/*���ˣ�����㲻���ڻ򸸽��Ϊ��ɫ������������*/
		/*������Ҫ�������Ϊ��ɫ�����*/


		/*����λ�õĸ����Ϊ��ɫ��������Ϊ��ɫ�����*/
	//������
		/* 
		1. �����뵽��ǰλ�ã�
	    2. ���游����ɺ�ɫ
		3. ���������������ɺ�ɫ��
		*/
		RBNode* curGrandpa = curFather->parent;
		RBNode* uncle = (curGrandpa->lchild != curFather ?
			curGrandpa->lchild : curGrandpa->rchild);
		if (uncle != nullptr && uncle->color == NodeColor::RED)
		{
			curGrandpa->color = NodeColor::RED;
			curFather->color = NodeColor::BLACK;
			uncle->color = NodeColor::BLACK;

			//���游�����Ϊ��ǰ���
			curNode = curGrandpa;
		}
		else
		{
			/*����λ�õĸ����Ϊ��ɫ��������Ϊ��ɫ��û������*/

			
		//���һ��
			/*����λ��Ϊ���ӵ��������ϣ������׽��Ϊ�游�������ӣ�����λ��Ϊ���׵��Һ���*/
		//������
			/*1. �Ը��׽����һ������
			  2. ���游�����һ������
			  3. ���游������ɫ��ɺ�ɫ
			  4. ���������ɫ��ɺ�ɫ��
			*/
			if (curFather == curGrandpa->lchild && curNode == curFather->rchild)
			{
				this->rotateLeft(curFather);
				this->rotateRight(curGrandpa);
				curGrandpa->color = NodeColor::RED;
				curNode->color = NodeColor::BLACK;

			}
		//�����
			/*����λ��Ϊ���ӵ��������ϣ������׽��Ϊ�游�������ӣ�����λ��Ϊ���׵�����*/
		//������
			/*1. �游�ڵ���һ���ҵ���
			  2. �游������ɫ��ɺ�ɫ
			  3. �����׽�����ɫ��ɺ�ɫ
			*/
			if (curFather == curGrandpa->lchild && curNode == curFather->lchild)
			{
				this->rotateRight(curGrandpa);
				curGrandpa->color = NodeColor::RED;
				curFather->color = NodeColor::BLACK;
			}
		//�����
			/*����λ��Ϊ�Һ��ӵ��������ϣ������׽��Ϊ�游�����Һ��ӣ�����λ��Ϊ���׽������ӣ�*/
		//������
			/*1. �Ը�����һ������
			  2. ���游�����һ������
			  3. ���游������ɫ��ɺ�ɫ
			  4. ���������ɫ��ɺ�ɫ��
			 */
			if (curFather == curGrandpa->rchild && curNode == curFather->lchild)
			{
				this->rotateRight(curFather);
				this->rotateLeft(curGrandpa);
				curGrandpa->color = NodeColor::RED;
				curNode->color = NodeColor::BLACK;
			}
		//�����
			/*����λ��Ϊ�Һ��ӵ��������ϣ������׽��Ϊ�游�����Һ��ӣ�����λ��Ϊ���׵��Һ���*/
		//������
			/*1. ���游�ڵ���һ������
			  2. ���游������ɫ��ɺ�ɫ
			  3. �����׽�����ɫ��ɺ�ɫ
			*/
			if (curFather == curGrandpa->rchild && curNode == curFather->rchild)
			{
				this->rotateLeft(curGrandpa);
				curGrandpa->color = NodeColor::RED;
				curFather->color = NodeColor::BLACK;
			}


		}

	}
}

/*�޸���ʧ���㡱*/
template<class T1, class T2>
void RBTree<T1, T2>::fixUpUnbalancedNode(RBNode* node)
{
}

template<class T1, class T2>
void RBTree<T1, T2>::replaceLastNode(RBNode* node)
{
	RBNode* curNode = node;
	while (curNode->lchild != nullptr || curNode->rchild != nullptr)
	{
		if (curNode->rchild != nullptr)
		{
			//��ǰ������Һ���
			//ʹ�ú�̺�̽������滻
			//��̽������һ��Ϊ�գ�����ǰ��������������½ǵĽ��
			RBNode* replaceNode = curNode->rchild;
			while (replaceNode->lchild != nullptr)
				replaceNode = replaceNode->lchild;
		}
	}
	
}