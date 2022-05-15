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
* @brief 判断在红黑树中是否有指定的内容
* @param key为红黑树结点中存放的键
* @return 成功返回true, 失败返回false
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
* @brief 判断在红黑树中是否有指定的内容
* @param val为红黑树结点中存放的值
* @param count用于返回key的个数
* @return 成功返回true, 失败返回false
*/
template<class T1, class T2>
bool RBTree<T1, T2>::hasKeyValue(const T2& val)
{
	RBNode* p = root;
	//用层序遍历整个红黑树
	//定义一个循环队列
	const int MAXSIZE = 64;
	RBNode* que[MAXSIZE];
	int front;//指向对头
	int rear;//指向队尾
	front = rear= 0;

	//front==rear表示对列为空
	//(rear+1)%MAXSIZE == front表示队列已满

   //将root插入到队列中
	rear = (rear + 1) % MAXSIZE;
	que[rear] = p;

	while (rear != front)
	{
		//出队
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
* @brief 判断当前红黑树是否为空
* @return 不为空返回false, 为空返回true
*/
template<class T1, class T2>
bool RBTree<T1, T2>::empty()
{
	if (this->root == nullptr)
		return true;
	return false;
}

/*
* @brief 通过key来获取val
* @param key为键值对中的键
* @return 成功返回参数key指定的键值对中的值，否则返回nullptr
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
* @brief 通过val来获取key
* @param val为键值对中的值
* @return 成功返回参数val指定的键值对中的值数组，否则返回nullptr
*/
template<class T1, class T2>
T1* RBTree<T1, T2>::getKey(const T2& val, int& count)
{
	RBNode* p = root;
	//用层序遍历整个红黑树
	//定义一个循环队列
	const int MAXSIZE = 64;
	const int BUFSIZE = 1024;
	RBNode* que[MAXSIZE];
	T1 key_buf[BUFSIZE];
	int front,buf_front;//指向对头
	int rear,buf_rear;//指向队尾
	int buf_len;

	front = rear = 0;
	buf_len = buf_front = buf_rear = 0;
	

	//front==rear表示对列为空
	//(rear+1)%MAXSIZE == front表示队列已满

   //将root插入到队列中
	rear = (rear + 1) % MAXSIZE;
	que[rear] = p;

	while (rear != front)
	{
		//出队
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
 * @brief 通过key来指定结点来进行删除
 * @param key为键值对中的键
 * @return 成功返回当前对象，否则返回nullptr
 */
template<class T1, class T2>
RBTree<T1, T2>& RBTree<T1, T2>::reomve(const T1& key)
{
	return nullptr;
}

/*
* @brief 通过val来指定结点来进行删除，删除的为最先找到的那一个红黑结点
* @param val为键值对中的值
* @return 成功返回当前对象，否则返回nullptr
*/
template<class T1, class T2>
RBTree<T1, T2>& RBTree<T1, T2>::remove(const T2& val)
{

	return nullptr;
}

/*插入结点*/
/*
* @brief 通过指定键值对来插入结点
* @param val为键值对中的值
* @param key为键值对中的键
* @return 成功返回当前对象，否则返回nullptr
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

	//下面部分代码用于串讲新的结点并完成新数据的存储

	/*
	* 此时,curNode为nullptr,currentFather指向最后一次遍历到的结点
	* 插入时newnode为红色，根据key的大小来插入到最后一个结点的左子树还是右子树上
	*/
	
	/*创建新节点*/
	curNode = new RBNode;
	curNode->parent = curFather;
	curNode->lchild = curNode->rchild = nullptr;
	curNode->key = key;
	curNode->val = val;

	/*红黑树为空树：直接插入结点，将颜色变成黑色。*/
	if (curFather == nullptr)
	{
		curNode->color = NodeColor::BLACK;
		this->root = curNode;
		return *this;
	}

	//如果新结点的key小于当前结点curFather的key
	if (curNode->key < curFather->key)
		curFather->lchild = curNode;//插入到curFather的左边
	else curFather->rchild = curNode;//插入到cruFather的右边
		curNode->parent = curFather;

		this->fixUpContinuousNodes(curNode);
	
	
	return *this;
}

//////////////////////////////////////////////////////////////////////

/*递归的清空指定结点*/
template<class T1, class T2>
void RBTree<T1, T2>::cleanUp(RBNode* node)
{
	//采用中序遍历的方式来删除结点
	if (node->lchild != nullptr)
		cleanUp(node->lchild);

	delete node;

	if (node->rchild != nullptr)
		cleanUp(node->rchild);
}

/*左单旋*/
template<class T1, class T2>
void RBTree<T1, T2>::rotateLeft(RBNode* node)
{
	RBNode* parent = node->parent;
	RBNode* left = node->lchild;
	RBNode* right = node->rchild;
	RBNode* rlgrandson = right->lchild;

	//判断当前结点的父结点是否为nullptr
	if (parent == nullptr)
	{
		root = node;
	}
	else {
		//判断当前结点是否为父结点的左孩子
		if (parent->lchild == node)	 parent->lchild = right;
		if (parent->rchild == node) parent->rchild = right;
	}
	right->parent = parent;
	
	//将当前结点的右孩子的左孩子进行连接
	//首先判断当前结点的右孩子的左孩子是否存在
	if (rlgrandson == nullptr) 
		node->rchild = nullptr;
	else
	{
		node->rchild = rlgrandson;
		rlgrandson->parent = node;
	}

}

/*右单旋*/
template<class T1, class T2>
void RBTree<T1, T2>::rotateRight(RBNode* node)
{
	RBNode* parent = node->parent;
	RBNode* left = node->lchild;
	RBNode* right = node->rchild;
	RBNode* lrgrandson = left->lchild;

	//判断当前结点的父结点是否为nullptr
		
	if (parent == nullptr)
	{
		root = node;
	}
	else {
		//判断当前结点是否为父结点的左孩子
		if (parent->lchild == node)	 parent->lchild = left;
		//判断当前结点是否为父结点的右孩子
		if (parent->rchild == node) parent->rchild = left;
	}

	left->parent = parent;
	
	//将当前结点的左孩子的右孩子进行连接
	//首先判断当前结点的左孩子的右孩子是否存在
	if (lrgrandson == nullptr)
		node->lchild = nullptr;
	else
	{
		node->lchild = lrgrandson;
		lrgrandson->parent = node;
	}
}

/*修复"连续红色结点"*/
template<class T1, class T2>
void RBTree<T1, T2>::fixUpContinuousNodes(RBNode* node)
{
	RBNode* curNode = node;
	//只有当前结点颜色为红色时，次啊可能在父节点为红色时违背红黑树规则
	while (curNode->color == NodeColor::RED)
	{
		RBNode* curFather = node->parent;
		if (curFather == nullptr)
		{
			//curNode是根结点
			curNode->color = NodeColor::BLACK;
			break;
		}
		else if(curFather->color == NodeColor::BLACK)
		{
			break;
		}

		/*到此，父结点不存在或父结点为黑色的情况处理完毕*/
		/*接下来要处理父结点为红色的情况*/


		/*插入位置的父结点为红色且叔叔结点为红色情况：*/
	//操作：
		/* 
		1. 结点插入到当前位置，
	    2. 将祖父结点变成红色
		3. 将父结点和叔叔结点变成黑色。
		*/
		RBNode* curGrandpa = curFather->parent;
		RBNode* uncle = (curGrandpa->lchild != curFather ?
			curGrandpa->lchild : curGrandpa->rchild);
		if (uncle != nullptr && uncle->color == NodeColor::RED)
		{
			curGrandpa->color = NodeColor::RED;
			curFather->color = NodeColor::BLACK;
			uncle->color = NodeColor::BLACK;

			//将祖父结点设为当前结点
			curNode = curGrandpa;
		}
		else
		{
			/*插入位置的父结点为红色，叔叔结点为黑色或没有叔叔*/

			
		//情况一：
			/*插入位置为左孩子的右子树上，即父亲结点为祖父结点的左孩子，插入位置为父亲的右孩子*/
		//操作：
			/*1. 对父亲结点做一次左旋
			  2. 对祖父结点做一次右旋
			  3. 将祖父结点的颜色变成红色
			  4. 插入结点的颜色变成黑色。
			*/
			if (curFather == curGrandpa->lchild && curNode == curFather->rchild)
			{
				this->rotateLeft(curFather);
				this->rotateRight(curGrandpa);
				curGrandpa->color = NodeColor::RED;
				curNode->color = NodeColor::BLACK;

			}
		//情况二
			/*插入位置为左孩子的左子树上，即父亲结点为祖父结点的左孩子，插入位置为父亲的左孩子*/
		//操作：
			/*1. 祖父节点做一次右单旋
			  2. 祖父结点的颜色变成红色
			  3. 将父亲结点的颜色变成黑色
			*/
			if (curFather == curGrandpa->lchild && curNode == curFather->lchild)
			{
				this->rotateRight(curGrandpa);
				curGrandpa->color = NodeColor::RED;
				curFather->color = NodeColor::BLACK;
			}
		//情况三
			/*插入位置为右孩子的左子树上，即父亲结点为祖父结点的右孩子，插入位置为父亲结点的左孩子：*/
		//操作：
			/*1. 对父亲做一次右旋
			  2. 对祖父结点做一次左旋
			  3. 将祖父结点的颜色变成红色
			  4. 插入结点的颜色变成黑色。
			 */
			if (curFather == curGrandpa->rchild && curNode == curFather->lchild)
			{
				this->rotateRight(curFather);
				this->rotateLeft(curGrandpa);
				curGrandpa->color = NodeColor::RED;
				curNode->color = NodeColor::BLACK;
			}
		//情况四
			/*插入位置为右孩子的右子树上，即父亲结点为祖父结点的右孩子，插入位置为父亲的右孩子*/
		//操作：
			/*1. 对祖父节点做一次左单旋
			  2. 将祖父结点的颜色变成红色
			  3. 将父亲结点的颜色变成黑色
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

/*修复“失衡结点”*/
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
			//当前结点有右孩子
			//使用后继后继结点进行替换
			//后继结点的最孩子一定为空，即当前结点右子树的右下角的结点
			RBNode* replaceNode = curNode->rchild;
			while (replaceNode->lchild != nullptr)
				replaceNode = replaceNode->lchild;
		}
	}
	
}