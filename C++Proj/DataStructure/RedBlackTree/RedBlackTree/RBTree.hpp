#include "RBTree.h"
#include <stdexcept>
#include <iostream>

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
		RBNode* node = que[front];

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
RBTree<T1, T2>& RBTree<T1, T2>::remove(const T1& key)
{
	RBNode* cur = root;
	while (cur != nullptr)
	{
		if (key == cur->key)
			break;
		else
			cur = (key < cur->key ? cur->lchild : cur->rchild);
	}
	if (cur == nullptr)
		throw std::runtime_error("could not find key in the RBTree");
	//��Ҫɾ���Ľ���滻�����һ��
	replaceLastNode(cur);

	if (cur == this->root)//ɾ�����Ϊ�����
	{
		this->root = nullptr;
		delete cur;
	}
	else if (cur->color == NodeColor::RED)//ɾ�����Ϊ��ɫ
	{
		if (cur == cur->parent->lchild)
			cur->parent->lchild = nullptr;
		else
			cur->parent->rchild = nullptr;
		delete cur;
	}
	else//ɾ�����Ϊ��ɫ
	{
		RBNode* par = cur->parent;
		RBNode* bro = (cur == par->lchild ? par->rchild : par->lchild);
		RBNode* lnep = bro->lchild;
		RBNode* rnep = bro->rchild;
		//ɾ����������
		if (cur == par->lchild)
		{
			//���һ�����ڵ�Ϊ��ɫ
			if (par->color == NodeColor::RED)
			{
				/*
				* ���1.1 ����ֶ�ӽ��Ϊ��ɫ
				*           R
				*		   / \
				*         B   B
				*            / \
				*           R   R
				* ����:
				*	1. ��ɾ����ǰ���
				*   2. �Ը�������
				*   3. �ֵܱ��
				*   4. ��ֶ�ӱ��
				*/
				if (lnep&&rnep&&lnep->color == NodeColor::RED && rnep->color == NodeColor::RED)
				{
					delete cur;
					rotateLeft(par);
					bro->color = NodeColor::RED;
					rnep->color = NodeColor::BLACK;
				}
				/*
				* ���1.2��ֻ��һ����ֶ�ӣ�����ֶ��һ��Ϊ��ɫ
				*             R
				*            / \
				*           B   B
				*              /
				*             R
				* ������
				*	1. ��ɾ����ǰ���
				*	2. ���ֵ�����
				*   3. �Ը�������
				*	4. ���ױ��
				*	5. �ֵܱ��
				*/
				if (lnep != nullptr && rnep == nullptr)
				{
					delete cur;
					rotateRight(bro);
					rotateLeft(par);
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
				}
				/*
				* ���1.3��ֻ����ֶ�ӣ�û����ֶ��,��ֶ��һ��Ϊ��ɫ�����ʢݣ�
				*           R
				*          / \
				*         B   B
				*              \
				*               R
				* ������
				*	1. ɾ����ǰ���
				*   2. ��������
				*	3. ���ױ��
				*   4. �ֵܱ��
				*/
				if (lnep == nullptr && rnep != nullptr)
				{
					delete cur;
					rotateLeft(par);
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 
				}
				/*
				* ���1.4��û��ֶ��
				*        R
				*       / \
				*      B   B
				* ������
				*   1. ɾ����ǰ���
				*   2. ���ױ��
				*	3. �ֵܱ��
				*/
				if (lnep == nullptr && rnep == nullptr)
				{
					delete cur;
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 
				}
			}//���һ�����ڵ�Ϊ��ɫ
		    //����������ڵ�Ϊ��ɫ
			if (par->color == NodeColor::BLACK)
			{

				/*
				* ���2.1���ֵ�Ϊ��ɫ����ʱ�ֵܱ���������ɫ����
				*          B
				*        /   \
				*       B     R
				*           /   \
				*          B     B
				*         / \   / \
				*        ?   ? ?   ?
				* ������
				*	1. ɾ����ǰ���
				*	2. ��������
				*	3. ����������
				*	4. ���ױ��
				*	5. �ֵܱ��
				*	6. �����ǰ���ڵ����Һ��ӣ�����һ��Ϊ��ɫ����Ҫִ���޸�������ɫ������
				*/
				if (bro->color == NodeColor::RED)
				{
					delete cur;
					rotateLeft(par);
					rotateLeft(par);
					par->color = NodeColor::RED;
					bro->color = NodeColor::BLACK;
					if (par->rchild != nullptr)
						fixUpContinuousRedNodes(par->rchild);
					 
				}
				/*
				* ���2.2/2.3���ֵ�Ϊ�ڣ�����ֶ��Ϊ����Һ��Ӳ�����
				*           B             B
				*          / \           / \  
				*         B   B   or    B   B 
				*            / \           /
				*           R   R         R
				* ������
				*	1. ɾ����ǰ���
				*	2. �ֵ�����
				*	3. ��������
				*	4. ��ֶ�ӱ��
				*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::RED &&
					(rnep == nullptr || rnep->color == NodeColor::RED))
				{
					delete cur;
					rotateRight(bro);
					rotateLeft(par);
					lnep->color = NodeColor::BLACK;
					 
				}
				/*
				* ����2.4���ֵܺ�ɫ��ֻ����ֶ��,��ֶ��һ��Ϊ��ɫ
				*         B
				*        / \
				*       B   B
				*          /
				*         R
				* ������
				*	1. ɾ����ǰ���
				*   2. ���������
				*	3. ��ֶ�ӱ��
				*/
				if (bro->color == NodeColor::BLACK && lnep == nullptr && rnep != nullptr)
				{
					delete cur;
					rotateLeft(par);
					rnep->color = NodeColor::BLACK;
					 
				}
				/*
				* ���2.5���ֵ�Ϊ��ɫ����û��ֶ��
				*          B
				*         / \
				*        B   B
				* ������
				*	1. ɾ����ǰ���
				*	2. �ֵܱ�죬�ﵽ�ֲ�ƽ�⣬���Ǵ�ʱ����ʧ��
				*	3. �Ը��ڵ�Ϊʧ���㣬��ʼִ���޸�ʧ�������
				*/
				if (bro->color == NodeColor::BLACK && lnep == nullptr && rnep == nullptr)
				{
					delete cur;
					bro->color = NodeColor::RED;
					fixUpUnbalancedNode(par);
					 ;
				}
			}//����������ڵ�Ϊ��ɫ
		}//ɾ����������

		//ɾ��������ұ�
		if (cur == par->rchild)
		{
			//���һ�����ڵ�Ϊ��ɫ
			if (par->color == NodeColor::RED)
			{
				
				/*
				* ���1.1 ����ֶ�ӽ��Ϊ��ɫ
				*           R
				*		   / \
				*         B   B
				*        / \
				*       R   R
				* ����:
				*	1. ��ɾ����ǰ���
				*   2. �Ը���������
				*   3. �ֵܱ��
				*   4. ��ֶ�ӱ��
				*/
				if (lnep&&rnep&&lnep->color == NodeColor::RED && rnep->color == NodeColor::RED)
				{
					delete cur;
					rotateRight(par);
					bro->color = NodeColor::RED;
					lnep->color = NodeColor::BLACK;
					 
				}
				/*
				* ���1.2��ֻ��һ����ֶ�ӣ�����ֶ��һ��Ϊ��ɫ
				*             R
				*            / \
				*           B   B
				*            \
				*             R
				* ������
				*	1. ��ɾ����ǰ���
				*	2. ���ֵ�����
				*   3. �Ը�������
				*	4. ���ױ��
				*	5. �ֵܱ��
				*/
				if (lnep != nullptr && rnep == nullptr)
				{
					delete cur;
					rotateLeft(bro);
					rotateRight(par);
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 
				}
				/*
				* ���1.3��ֻ����ֶ�ӣ�û����ֶ��,��ֶ��һ��Ϊ��ɫ�����ʢݣ�
				*           R
				*          / \
				*         B   B
				*        /
				*       R
				* ������
				*	1. ɾ����ǰ���
				*   2. ��������
				*	3. ���ױ��
				*   4. �ֵܱ��
				*/
				if (lnep == nullptr && rnep != nullptr)
				{
					delete cur;
					rotateRight(par);
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 
				}
				/*
				* ���1.4��û��ֶ��
				*        R
				*       / \
				*      B   B
				* ������
				*   1. ɾ����ǰ���
				*   2. ���ױ��
				*	3. �ֵܱ��
				*/
				if (lnep == nullptr && rnep == nullptr)
				{
					delete cur;
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 ;
				}
			}//���һ�����ڵ�Ϊ��ɫ
			//����������ڵ�Ϊ��ɫ
			if (par->color == NodeColor::BLACK)
			{

				/*
				* ���2.1���ֵ�Ϊ��ɫ����ʱ�ֵܱ���������ɫ����
				*				        B
				*				      /   \
				*				     R     B
				*				   /   \
				*				  B     B
				*				 / \   / \
				*				?   ? ?   ?
				* ������
				*	1. ɾ����ǰ���
				*	2. ��������
				*	3. ����������
				*	4. ���ױ��
				*	5. �ֵܱ��
				*	6. �����ǰ���ڵ����Һ��ӣ�����һ��Ϊ��ɫ����Ҫִ���޸�������ɫ������
				*/
				if (bro->color == NodeColor::RED)
				{
					delete cur;
					rotateRight(par);
					rotateRight(par);
					par->color = NodeColor::RED;
					bro->color = NodeColor::BLACK;
					if (par->lchild != nullptr)
						fixUpContinuousRedNodes(par->lchild);
					 ;
				}
				/*
				* ���2.2/2.3���ֵ�Ϊ�ڣ�����ֶ��Ϊ������Ӳ�����
				*           B             B
				*          / \           / \
				*         B   B   or    B   B
				*        / \             \
				*       R   R             R
				* ������
				*	1. ɾ����ǰ���
				*	2. �ֵ�����
				*	3. ��������
				*	4. ��ֶ�ӱ��
				*/
				if (bro->color == NodeColor::BLACK && rnep->color == NodeColor::RED &&
					(lnep->color == NodeColor::RED || lnep == nullptr))
				{
					delete cur;
					rotateLeft(bro);
					rotateRight(par);
					rnep->color = NodeColor::BLACK;
					 
				}
				/*
				* ����2.4���ֵܺ�ɫ��ֻ����ֶ��,��ֶ��һ��Ϊ��ɫ
				*         B
				*        / \
				*       B   B
				*        \
				*         R
				* ������
				*	1. ɾ����ǰ���
				*   2. ���������
				*	3. ��ֶ�ӱ��
				*/
				if (bro->color == NodeColor::BLACK && rnep == nullptr && lnep != nullptr)
				{
					delete cur;
					rotateRight(par);
					lnep->color = NodeColor::BLACK;
					 
				}
				/*
				* ���2.5���ֵ�Ϊ��ɫ����û��ֶ��
				*          B
				*         / \
				*        B   B
				* ������
				*	1. ɾ����ǰ���
				*	2. �ֵܱ�죬�ﵽ�ֲ�ƽ�⣬���Ǵ�ʱ����ʧ��
				*	3. �Ը��ڵ�Ϊʧ���㣬��ʼִ���޸�ʧ�������
				*/
				if (bro->color == NodeColor::BLACK && lnep == nullptr && rnep == nullptr)
				{
					delete cur;
					bro->color = NodeColor::RED;
					fixUpUnbalancedNode(par);
					 
				}

			}//����������ڵ�Ϊ��ɫ

		}//ɾ��������ұ�
		
	}
		
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
	curNode->color = NodeColor::RED;

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

	this->fixUpContinuousRedNodes(curNode);

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
	if (node->rchild != nullptr)
		cleanUp(node->rchild);

	delete node;
}

/*����*/
template<class T1, class T2>
void RBTree<T1, T2>::rotateLeft(RBNode* node)
{
	RBNode* father = node->parent;
	RBNode* targetRoot = node->rchild;

	// ���°������ĸ���
	if (father == nullptr) {
		this->root = targetRoot;
	}
	else {
		if (node == father->lchild) {
			father->lchild = targetRoot;
		}
		else {
			father->rchild = targetRoot;
		}
	}
	targetRoot->parent = father;

	node->rchild = targetRoot->lchild; // �����п����� nullptr
	if (node->rchild != nullptr) { // ֻ�е����Ӳ��ǿյ�ʱ�򣬲ſɳ������°󶨸��ڵ㡣
		node->rchild->parent = node;
	}
	targetRoot->lchild = node;
	node->parent = targetRoot;

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
void RBTree<T1, T2>::fixUpContinuousRedNodes(RBNode* node)
{
	RBNode* curNode = node;
	//ֻ�е�ǰ�����ɫΪ��ɫʱ���ſ����ڸ��ڵ�Ϊ��ɫʱΥ�����������
	while (curNode->color == NodeColor::RED)
	{
		RBNode* curFather = curNode->parent;

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
			curNode = curGrandpa;//���游Ϊ��ǰ���ʱ����ʱ�ĸ����Ϊ��ɫ����Ȼ���ܳ���������ɫ�������
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

	RBNode* cur = node;
	while (cur != root)
	{

		RBNode* par = cur->parent;
		RBNode* bro = (cur == par->lchild) ? par->rchild : par->lchild;
		RBNode* lnep = bro->lchild;
		RBNode* rnep = bro->rchild;
		//ʧ���������
		if (cur == par->lchild)
		{
			//���һ: ʧ����ĸ�����Ǻ�ɫ
			if (par->color == NodeColor::RED)
			{
				//�����1:��ֶ��Ϊ��ɫ
					/*
					* R--red B--black ?--any
					*	    R
					*	   / \
					*     B   B
					*		 / \
					*	    B   ?
					*/
				//����: ���ڵ�����
				if (lnep->color == NodeColor::BLACK)
				{
					rotateLeft(par);
					break;
				}
				//�����������ֶ��Ϊ��ɫ����ֶ��Ϊ��ɫ
					/*
					*        R
					*		/ \
					*	   B   B
					*         / \
					*	     R   B
					*/
				//����:
					/*
					* 1. ���ڵ���ɫ��ɺ�ɫ
					* 2. �ֵܽ���ɺ�ɫ
					* 3. ����ֶ�ӽ��ִ��"�޸�������ɫ���"�Ĳ���
					*/
				if (lnep->color == NodeColor::RED && rnep->color == NodeColor::BLACK)
				{
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					fixUpContinuousRedNodes(lnep);
					break;
				}
				//�����3����ֶ�Ӻ�ɫ����ֶ�Ӻ�ɫ
					/*
					*           R
					*		   / \
					*         B   B
					*            / \
					*           R   R
					*/
				//���ݣ�
					/*
					* 1. �����ױ��
					* 2. ���ֵܱ��
					* 3. ���Һ��ӱ��
					* 4. �Ը�������
					*/
				if (lnep->color == NodeColor::RED && rnep->color == NodeColor::BLACK)
				{
					par->color == NodeColor::BLACK;
					bro->color == NodeColor::RED;
					rnep->color = NodeColor::BLACK;
					rotateLeft(par);
				}
			}
			//�������ʧ����ĸ�����Ǻ�ɫ
			if (par->color == NodeColor::BLACK)
			{
				//�����1���ֵܺ�ɫ������ֶ�Ӻ�ɫ
					/*
					*         B
					*		 / \
					*       B   B
					*          / \
					*         B   B
					*/
				//������
					/*
					* 1. �ֵܱ��
					* 2. �����ڵ����µĽ��
					*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::BLACK
					&& rnep->color == NodeColor::BLACK)
				{
					bro->color == NodeColor::RED;
					cur = par;
				}
				//�����2���ֵܺ�ɫ����ֶ�Ӻ�ɫ����ֶ��Ϊ������
					/*
					*        B
					*		/ \
					*      B   B
					*         / \
					*        ?   R
					*/
				//������
					/*
					* 1. ���������
					* 2. ��ֶ�ӱ��
					*/
				if (bro->color == NodeColor::BLACK && rnep->color == NodeColor::RED)
				{
					rotateLeft(par);
					rnep->color == NodeColor::BLACK;
					break;
				}
				//�����3���ֵ�Ϊ��ɫ����ֶ�Ӻ�ɫ����ֶ�Ӻ�ɫ
					/*
					*              B
					*             / \
					*            B   B
					*               / \
					*              R   B
					*/
				//������
					/*
					* 1. ����ֶ�ӱ��
					* 2. �ֵ�����
					* 3. ��������
					*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::RED
					&& rnep->color == NodeColor::BLACK)
				{
					lnep->color == NodeColor::BLACK;
					rotateRight(bro);
					rotateLeft(par);
					break;
				}
			//�����4:�ֵܺ�ɫ
				/*
				*          B
				*         / \
				*        B   R
				*           / \
				*          B   B
				*/
			//������
				/*
				* 1. ���ױ��
				* 2. �ֵܱ��
				* 3. ��������
				* 4. ת�������һ
				*/
				if (bro->color == NodeColor::RED)
				{
					par->color = NodeColor::RED;
					bro->color = NodeColor::BLACK;
					rotateLeft(par);
					continue;
				}
			}

		}//ʧ���������

		//ʧ�������ұ�
		if (cur == par->rchild)
		{
			//���һ: ʧ����ĸ�����Ǻ�ɫ
			if (par->color == NodeColor::RED)
			{
				//�����1:��ֶ��Ϊ��ɫ
					/*
					* R--red B--black ?--any
					*	    R
					*	   / \
					*     B   B-->unblanced
					*    / \
					*	?   B
					*/
				//����: ���ڵ�����
				if (lnep->color == NodeColor::BLACK)
				{
					rotateRight(par);
					break;
				}
				//�����������ֶ��Ϊ��ɫ����ֶ��Ϊ��ɫ
					/*
					*        R
					*		/ \
					*	   B   B
					*     / \
					*	 B   R
					*/
				//����:
					/*
					* 1. ���ڵ���ɫ��ɺ�ɫ
					* 2. �ֵܽ���ɺ�ɫ
					* 3. ����ֶ�ӽ��ִ��"�޸�������ɫ���"�Ĳ���
					*/
				if (lnep->color == NodeColor::RED && rnep->color == NodeColor::BLACK)
				{
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					fixUpContinuousRedNodes(rnep);
					break;
				}
				//�����3����ֶ�Ӻ�ɫ����ֶ�Ӻ�ɫ
					/*
					*           R
					*		   / \
					*         B   B
					*        / \
					*       R   R
					*/
				//���ݣ�
					/*
					* 1. �����ױ��
					* 2. ���ֵܱ��
					* 3. �����ӱ��
					* 4. �Ը�������
					*/
				if (lnep->color == NodeColor::RED && rnep->color == NodeColor::BLACK)
				{
					par->color == NodeColor::BLACK;
					bro->color == NodeColor::RED;
					lnep->color = NodeColor::BLACK;
					rotateRight(par);
				}
			}//���һ: ʧ����ĸ�����Ǻ�ɫ
			//�������ʧ����ĸ�����Ǻ�ɫ
			if (par->color == NodeColor::BLACK)
			{
				//�����1���ֵܺ�ɫ������ֶ�Ӻ�ɫ
				/*
				*         B
				*		 / \
				*       B   B
				*      / \
				*     B   B
				*/
				//������
					/*
					* 1. �ֵܱ��
					* 2. �����ڵ����µĽ��
					*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::BLACK
					&& rnep->color == NodeColor::BLACK)
				{
					bro->color == NodeColor::RED;
					cur = par;
				}
				//�����2���ֵܺ�ɫ����ֶ�Ӻ�ɫ����ֶ��Ϊ������
					/*
					*        B
					*		/ \
					*      B   B
					*     / \
					*    R   ?   
					*/
				//������
					/*
					* 1. ���������
					* 2. ��ֶ�ӱ��
					*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::RED)
				{
					rotateRight(par);
					lnep->color == NodeColor::BLACK;
					break;
				}
				//�����3���ֵ�Ϊ��ɫ����ֶ�Ӻ�ɫ����ֶ�Ӻ�ɫ
					/*
					*              B
					*             / \
					*            B   B
					*           / \
					*          B   R   
					*/
				//������
					/*
					* 1. ����ֶ�ӱ��
					* 2. �ֵ�����
					* 3. ��������
					*/
				if (bro->color == NodeColor::BLACK && rnep->color == NodeColor::RED
					&& lnep->color == NodeColor::BLACK)
				{
					rnep->color == NodeColor::BLACK;
					rotateLeft(bro);
					rotateRight(par);
					break;
				}
				//�����4:�ֵܺ�ɫ
					/*
					*          B
					*         / \
					*        B   R
					*           / \
					*          B   B
					*/
				//������
					/*
					* 1. ���ױ��
					* 2. �ֵܱ��
					* 3. ��������
					* 4. ת�������һ
					*/
				if (bro->color == NodeColor::RED)
				{
					par->color = NodeColor::RED;
					bro->color = NodeColor::BLACK;
					rotateRight(par);
					continue;
				}

			}//�������ʧ����ĸ�����Ǻ�ɫ

		}//ʧ�������ұ�
	}

}

/*ɾ��ʱ����ɾ������滻�����һ��*/
template<class T1, class T2>
void RBTree<T1, T2>::replaceLastNode(RBNode* &node)
{
	RBNode* curNode = node;
	while (curNode->lchild != nullptr || curNode->rchild != nullptr)
	{
		if (curNode->rchild != nullptr)
		{
			//��ǰ������Һ��ӻ��������������Ӷ���
			//ʹ�ú�̺�̽������滻
			//��̽�������һ��Ϊ�գ�����ǰ��������������½ǵĽ��
			RBNode* replaceNode = curNode->rchild;
			while (replaceNode->lchild != nullptr)
				replaceNode = replaceNode->lchild;
			//����ǰ�����滻����val color key���н���
			swap(curNode->key, replaceNode->key);
			swap(curNode->val, replaceNode->val);
			swap(curNode->color, replaceNode->color);
			curNode = replaceNode;
		}
		else {
			//��ǰΪ���ӣ�û���Һ���
			//ʹ��ǰ�������Ϊ�滻���
			//��ǰ����ǰ�������Һ���һ��Ϊnullptr
			RBNode* replaceNode = curNode->lchild;
			while (replaceNode->rchild != nullptr)
				replaceNode = replaceNode->rchild;
			//����ǰ�����滻����val color key���н���
			swap(curNode->key, replaceNode->key);
			swap(curNode->val, replaceNode->val);
			swap(curNode->color, replaceNode->color);
			curNode = replaceNode;
		}
	}
	node = curNode;
	
}

template<class T>
inline void swap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<class T1, class T2>
void RBTree<T1, T2>::MidShow(RBNode* node)
{
	if (node->lchild != nullptr)
		MidShow(node->lchild);
	std::cout << node->key << ": " << node->val << std::endl;
	std::cout << "color:" << (node->color == NodeColor::RED ? "red" : "black")
			  << " parent:" << (node->parent == nullptr ? 0:node->parent->key) 
			  << " left:" << (node->lchild == nullptr ? 0 : node->lchild->key) 
			  << " right:" << (node->rchild == nullptr ? 0 : node->rchild->key) 
		      << std::endl;
	std::cout << std::endl;
	if (node->rchild != nullptr)
		MidShow(node->rchild);

}

template<class T1, class T2>
void RBTree<T1, T2>::ReverseShow(RBNode* node)
{
	if (node->rchild != nullptr)
		ReverseShow(node->rchild);
	std::cout << node->key << ": " << node->val << std::endl;
	std::cout << "color:" << (node->color == NodeColor::RED ? "red" : "black")
		<< " parent:" << (node->parent == nullptr ? 0 : node->parent->key)
		<< " left:" << (node->lchild == nullptr ? 0 : node->lchild->key)
		<< " right:" << (node->rchild == nullptr ? 0 : node->rchild->key)
		<< std::endl;
	std::cout << std::endl;
	if (node->lchild != nullptr)
		ReverseShow(node->lchild);
}