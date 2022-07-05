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
	//将要删除的结点替换到最后一层
	replaceLastNode(cur);

	if (cur == this->root)//删除结点为根结点
	{
		this->root = nullptr;
		delete cur;
	}
	else if (cur->color == NodeColor::RED)//删除结点为红色
	{
		if (cur == cur->parent->lchild)
			cur->parent->lchild = nullptr;
		else
			cur->parent->rchild = nullptr;
		delete cur;
	}
	else//删除结点为黑色
	{
		RBNode* par = cur->parent;
		RBNode* bro = (cur == par->lchild ? par->rchild : par->lchild);
		RBNode* lnep = bro->lchild;
		RBNode* rnep = bro->rchild;
		//删除结点在左边
		if (cur == par->lchild)
		{
			//情况一：父节点为红色
			if (par->color == NodeColor::RED)
			{
				/*
				* 情况1.1 两个侄子结点为红色
				*           R
				*		   / \
				*         B   B
				*            / \
				*           R   R
				* 操作:
				*	1. 先删除当前结点
				*   2. 对父亲左旋
				*   3. 兄弟变红
				*   4. 右侄子变黑
				*/
				if (lnep&&rnep&&lnep->color == NodeColor::RED && rnep->color == NodeColor::RED)
				{
					delete cur;
					rotateLeft(par);
					bro->color = NodeColor::RED;
					rnep->color = NodeColor::BLACK;
				}
				/*
				* 情况1.2：只有一个左侄子，且左侄子一定为红色
				*             R
				*            / \
				*           B   B
				*              /
				*             R
				* 操作：
				*	1. 先删除当前结点
				*	2. 对兄弟右旋
				*   3. 对父亲左旋
				*	4. 父亲变黑
				*	5. 兄弟变红
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
				* 情况1.3：只有右侄子，没有左侄子,右侄子一定为红色（性质⑤）
				*           R
				*          / \
				*         B   B
				*              \
				*               R
				* 操作：
				*	1. 删除当前结点
				*   2. 父亲左旋
				*	3. 父亲变黑
				*   4. 兄弟变红
				*/
				if (lnep == nullptr && rnep != nullptr)
				{
					delete cur;
					rotateLeft(par);
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 
				}
				/*
				* 情况1.4：没有侄子
				*        R
				*       / \
				*      B   B
				* 操作：
				*   1. 删除当前结点
				*   2. 父亲变黑
				*	3. 兄弟变红
				*/
				if (lnep == nullptr && rnep == nullptr)
				{
					delete cur;
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 
				}
			}//情况一：父节点为红色
		    //情况二：父节点为黑色
			if (par->color == NodeColor::BLACK)
			{

				/*
				* 情况2.1：兄弟为红色，此时兄弟必有两个黑色孩子
				*          B
				*        /   \
				*       B     R
				*           /   \
				*          B     B
				*         / \   / \
				*        ?   ? ?   ?
				* 操作：
				*	1. 删除当前结点
				*	2. 父亲左旋
				*	3. 父亲再左旋
				*	4. 父亲变红
				*	5. 兄弟变黑
				*	6. 如果当前父节点有右孩子，孩子一定为红色，需要执行修复连续红色结点操作
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
				* 情况2.2/2.3：兄弟为黑，左右侄子为红或右孩子不存在
				*           B             B
				*          / \           / \  
				*         B   B   or    B   B 
				*            / \           /
				*           R   R         R
				* 操作：
				*	1. 删除当前结点
				*	2. 兄弟右旋
				*	3. 父亲左旋
				*	4. 左侄子变黑
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
				* 操作2.4：兄弟黑色，只有右侄子,右侄子一定为红色
				*         B
				*        / \
				*       B   B
				*          /
				*         R
				* 操作：
				*	1. 删除当前结点
				*   2. 父结点左旋
				*	3. 右侄子变黑
				*/
				if (bro->color == NodeColor::BLACK && lnep == nullptr && rnep != nullptr)
				{
					delete cur;
					rotateLeft(par);
					rnep->color = NodeColor::BLACK;
					 
				}
				/*
				* 情况2.5：兄弟为黑色，但没有侄子
				*          B
				*         / \
				*        B   B
				* 操作：
				*	1. 删除当前结点
				*	2. 兄弟变红，达到局部平衡，但是此时整体失衡
				*	3. 以父节点为失衡结点，开始执行修复失衡结点操作
				*/
				if (bro->color == NodeColor::BLACK && lnep == nullptr && rnep == nullptr)
				{
					delete cur;
					bro->color = NodeColor::RED;
					fixUpUnbalancedNode(par);
					 ;
				}
			}//情况二：父节点为黑色
		}//删除结点在左边

		//删除结点在右边
		if (cur == par->rchild)
		{
			//情况一：父节点为红色
			if (par->color == NodeColor::RED)
			{
				
				/*
				* 情况1.1 两个侄子结点为红色
				*           R
				*		   / \
				*         B   B
				*        / \
				*       R   R
				* 操作:
				*	1. 先删除当前结点
				*   2. 对父亲右旋旋
				*   3. 兄弟变红
				*   4. 左侄子变黑
				*/
				if (lnep&&rnep&&lnep->color == NodeColor::RED && rnep->color == NodeColor::RED)
				{
					delete cur;
					rotateRight(par);
					bro->color = NodeColor::RED;
					lnep->color = NodeColor::BLACK;
					 
				}
				/*
				* 情况1.2：只有一个右侄子，且右侄子一定为红色
				*             R
				*            / \
				*           B   B
				*            \
				*             R
				* 操作：
				*	1. 先删除当前结点
				*	2. 对兄弟左旋
				*   3. 对父亲右旋
				*	4. 父亲变黑
				*	5. 兄弟变红
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
				* 情况1.3：只有左侄子，没有右侄子,左侄子一定为红色（性质⑤）
				*           R
				*          / \
				*         B   B
				*        /
				*       R
				* 操作：
				*	1. 删除当前结点
				*   2. 父亲右旋
				*	3. 父亲变黑
				*   4. 兄弟变红
				*/
				if (lnep == nullptr && rnep != nullptr)
				{
					delete cur;
					rotateRight(par);
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 
				}
				/*
				* 情况1.4：没有侄子
				*        R
				*       / \
				*      B   B
				* 操作：
				*   1. 删除当前结点
				*   2. 父亲变黑
				*	3. 兄弟变红
				*/
				if (lnep == nullptr && rnep == nullptr)
				{
					delete cur;
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					 ;
				}
			}//情况一：父节点为红色
			//情况二：父节点为黑色
			if (par->color == NodeColor::BLACK)
			{

				/*
				* 情况2.1：兄弟为红色，此时兄弟必有两个黑色孩子
				*				        B
				*				      /   \
				*				     R     B
				*				   /   \
				*				  B     B
				*				 / \   / \
				*				?   ? ?   ?
				* 操作：
				*	1. 删除当前结点
				*	2. 父亲右旋
				*	3. 父亲再右旋
				*	4. 父亲变红
				*	5. 兄弟变黑
				*	6. 如果当前父节点有右孩子，孩子一定为红色，需要执行修复连续红色结点操作
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
				* 情况2.2/2.3：兄弟为黑，左右侄子为红或左孩子不存在
				*           B             B
				*          / \           / \
				*         B   B   or    B   B
				*        / \             \
				*       R   R             R
				* 操作：
				*	1. 删除当前结点
				*	2. 兄弟左旋
				*	3. 父亲右旋
				*	4. 右侄子变黑
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
				* 操作2.4：兄弟黑色，只有左侄子,左侄子一定为红色
				*         B
				*        / \
				*       B   B
				*        \
				*         R
				* 操作：
				*	1. 删除当前结点
				*   2. 父结点右旋
				*	3. 左侄子变黑
				*/
				if (bro->color == NodeColor::BLACK && rnep == nullptr && lnep != nullptr)
				{
					delete cur;
					rotateRight(par);
					lnep->color = NodeColor::BLACK;
					 
				}
				/*
				* 情况2.5：兄弟为黑色，但没有侄子
				*          B
				*         / \
				*        B   B
				* 操作：
				*	1. 删除当前结点
				*	2. 兄弟变红，达到局部平衡，但是此时整体失衡
				*	3. 以父节点为失衡结点，开始执行修复失衡结点操作
				*/
				if (bro->color == NodeColor::BLACK && lnep == nullptr && rnep == nullptr)
				{
					delete cur;
					bro->color = NodeColor::RED;
					fixUpUnbalancedNode(par);
					 
				}

			}//情况二：父节点为黑色

		}//删除结点在右边
		
	}
		
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

	//下面部分代码用于创建新的结点并完成新数据的存储

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
	curNode->color = NodeColor::RED;

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

	this->fixUpContinuousRedNodes(curNode);

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
	if (node->rchild != nullptr)
		cleanUp(node->rchild);

	delete node;
}

/*左单旋*/
template<class T1, class T2>
void RBTree<T1, T2>::rotateLeft(RBNode* node)
{
	RBNode* father = node->parent;
	RBNode* targetRoot = node->rchild;

	// 重新绑定子树的根。
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

	node->rchild = targetRoot->lchild; // 孩子有可能是 nullptr
	if (node->rchild != nullptr) { // 只有当孩子不是空的时候，才可尝试重新绑定父节点。
		node->rchild->parent = node;
	}
	targetRoot->lchild = node;
	node->parent = targetRoot;

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
void RBTree<T1, T2>::fixUpContinuousRedNodes(RBNode* node)
{
	RBNode* curNode = node;
	//只有当前结点颜色为红色时，才可能在父节点为红色时违背红黑树规则
	while (curNode->color == NodeColor::RED)
	{
		RBNode* curFather = curNode->parent;

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
			curNode = curGrandpa;//以祖父为当前结点时，此时的父结点为红色，仍然可能出现连续红色结点问题
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

	RBNode* cur = node;
	while (cur != root)
	{

		RBNode* par = cur->parent;
		RBNode* bro = (cur == par->lchild) ? par->rchild : par->lchild;
		RBNode* lnep = bro->lchild;
		RBNode* rnep = bro->rchild;
		//失衡结点在左边
		if (cur == par->lchild)
		{
			//情况一: 失衡结点的父结点是红色
			if (par->color == NodeColor::RED)
			{
				//子情况1:左侄子为黑色
					/*
					* R--red B--black ?--any
					*	    R
					*	   / \
					*     B   B
					*		 / \
					*	    B   ?
					*/
				//操作: 父节点左旋
				if (lnep->color == NodeColor::BLACK)
				{
					rotateLeft(par);
					break;
				}
				//子情况二：左侄子为红色，右侄子为黑色
					/*
					*        R
					*		/ \
					*	   B   B
					*         / \
					*	     R   B
					*/
				//操作:
					/*
					* 1. 父节点颜色变成黑色
					* 2. 兄弟结点变成红色
					* 3. 对左侄子结点执行"修复连续红色结点"的操作
					*/
				if (lnep->color == NodeColor::RED && rnep->color == NodeColor::BLACK)
				{
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					fixUpContinuousRedNodes(lnep);
					break;
				}
				//子情况3：左侄子红色，右侄子红色
					/*
					*           R
					*		   / \
					*         B   B
					*            / \
					*           R   R
					*/
				//操纵：
					/*
					* 1. 将父亲变黑
					* 2. 将兄弟变红
					* 3. 将右孩子变黑
					* 4. 对父亲左旋
					*/
				if (lnep->color == NodeColor::RED && rnep->color == NodeColor::BLACK)
				{
					par->color == NodeColor::BLACK;
					bro->color == NodeColor::RED;
					rnep->color = NodeColor::BLACK;
					rotateLeft(par);
				}
			}
			//情况二：失衡结点的父结点是黑色
			if (par->color == NodeColor::BLACK)
			{
				//子情况1：兄弟黑色，左右侄子黑色
					/*
					*         B
					*		 / \
					*       B   B
					*          / \
					*         B   B
					*/
				//操作：
					/*
					* 1. 兄弟变红
					* 2. 将父节点变成新的结点
					*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::BLACK
					&& rnep->color == NodeColor::BLACK)
				{
					bro->color == NodeColor::RED;
					cur = par;
				}
				//子情况2：兄弟黑色，右侄子红色，左侄子为任意结点
					/*
					*        B
					*		/ \
					*      B   B
					*         / \
					*        ?   R
					*/
				//操作：
					/*
					* 1. 父结点左旋
					* 2. 右侄子变黑
					*/
				if (bro->color == NodeColor::BLACK && rnep->color == NodeColor::RED)
				{
					rotateLeft(par);
					rnep->color == NodeColor::BLACK;
					break;
				}
				//子情况3：兄弟为黑色，左侄子红色，右侄子黑色
					/*
					*              B
					*             / \
					*            B   B
					*               / \
					*              R   B
					*/
				//操作：
					/*
					* 1. 将左侄子变黑
					* 2. 兄弟右旋
					* 3. 父亲左旋
					*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::RED
					&& rnep->color == NodeColor::BLACK)
				{
					lnep->color == NodeColor::BLACK;
					rotateRight(bro);
					rotateLeft(par);
					break;
				}
			//子情况4:兄弟红色
				/*
				*          B
				*         / \
				*        B   R
				*           / \
				*          B   B
				*/
			//操作：
				/*
				* 1. 父亲变红
				* 2. 兄弟变黑
				* 3. 父亲左旋
				* 4. 转换到情况一
				*/
				if (bro->color == NodeColor::RED)
				{
					par->color = NodeColor::RED;
					bro->color = NodeColor::BLACK;
					rotateLeft(par);
					continue;
				}
			}

		}//失衡结点在左边

		//失衡结点在右边
		if (cur == par->rchild)
		{
			//情况一: 失衡结点的父结点是红色
			if (par->color == NodeColor::RED)
			{
				//子情况1:右侄子为黑色
					/*
					* R--red B--black ?--any
					*	    R
					*	   / \
					*     B   B-->unblanced
					*    / \
					*	?   B
					*/
				//操作: 父节点右旋
				if (lnep->color == NodeColor::BLACK)
				{
					rotateRight(par);
					break;
				}
				//子情况二：右侄子为红色，左侄子为黑色
					/*
					*        R
					*		/ \
					*	   B   B
					*     / \
					*	 B   R
					*/
				//操作:
					/*
					* 1. 父节点颜色变成黑色
					* 2. 兄弟结点变成红色
					* 3. 对右侄子结点执行"修复连续红色结点"的操作
					*/
				if (lnep->color == NodeColor::RED && rnep->color == NodeColor::BLACK)
				{
					par->color = NodeColor::BLACK;
					bro->color = NodeColor::RED;
					fixUpContinuousRedNodes(rnep);
					break;
				}
				//子情况3：左侄子红色，右侄子红色
					/*
					*           R
					*		   / \
					*         B   B
					*        / \
					*       R   R
					*/
				//操纵：
					/*
					* 1. 将父亲变黑
					* 2. 将兄弟变红
					* 3. 将左孩子变黑
					* 4. 对父亲右旋
					*/
				if (lnep->color == NodeColor::RED && rnep->color == NodeColor::BLACK)
				{
					par->color == NodeColor::BLACK;
					bro->color == NodeColor::RED;
					lnep->color = NodeColor::BLACK;
					rotateRight(par);
				}
			}//情况一: 失衡结点的父结点是红色
			//情况二：失衡结点的父结点是黑色
			if (par->color == NodeColor::BLACK)
			{
				//子情况1：兄弟黑色，左右侄子黑色
				/*
				*         B
				*		 / \
				*       B   B
				*      / \
				*     B   B
				*/
				//操作：
					/*
					* 1. 兄弟变红
					* 2. 将父节点变成新的结点
					*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::BLACK
					&& rnep->color == NodeColor::BLACK)
				{
					bro->color == NodeColor::RED;
					cur = par;
				}
				//子情况2：兄弟黑色，左侄子红色，右侄子为任意结点
					/*
					*        B
					*		/ \
					*      B   B
					*     / \
					*    R   ?   
					*/
				//操作：
					/*
					* 1. 父结点右旋
					* 2. 左侄子变黑
					*/
				if (bro->color == NodeColor::BLACK && lnep->color == NodeColor::RED)
				{
					rotateRight(par);
					lnep->color == NodeColor::BLACK;
					break;
				}
				//子情况3：兄弟为黑色，右侄子红色，左侄子黑色
					/*
					*              B
					*             / \
					*            B   B
					*           / \
					*          B   R   
					*/
				//操作：
					/*
					* 1. 将右侄子变黑
					* 2. 兄弟左旋
					* 3. 父亲右旋
					*/
				if (bro->color == NodeColor::BLACK && rnep->color == NodeColor::RED
					&& lnep->color == NodeColor::BLACK)
				{
					rnep->color == NodeColor::BLACK;
					rotateLeft(bro);
					rotateRight(par);
					break;
				}
				//子情况4:兄弟红色
					/*
					*          B
					*         / \
					*        B   R
					*           / \
					*          B   B
					*/
				//操作：
					/*
					* 1. 父亲变红
					* 2. 兄弟变黑
					* 3. 父亲右旋
					* 4. 转换到情况一
					*/
				if (bro->color == NodeColor::RED)
				{
					par->color = NodeColor::RED;
					bro->color = NodeColor::BLACK;
					rotateRight(par);
					continue;
				}

			}//情况二：失衡结点的父结点是黑色

		}//失衡结点在右边
	}

}

/*删除时，将删除结点替换到最后一层*/
template<class T1, class T2>
void RBTree<T1, T2>::replaceLastNode(RBNode* &node)
{
	RBNode* curNode = node;
	while (curNode->lchild != nullptr || curNode->rchild != nullptr)
	{
		if (curNode->rchild != nullptr)
		{
			//当前结点有右孩子或者左右两个孩子都有
			//使用后继后继结点进行替换
			//后继结点的左孩子一定为空，即当前结点右子树的左下角的结点
			RBNode* replaceNode = curNode->rchild;
			while (replaceNode->lchild != nullptr)
				replaceNode = replaceNode->lchild;
			//将当前结点和替换结点的val color key进行交换
			swap(curNode->key, replaceNode->key);
			swap(curNode->val, replaceNode->val);
			swap(curNode->color, replaceNode->color);
			curNode = replaceNode;
		}
		else {
			//当前为左孩子，没有右孩子
			//使用前驱结点作为替换结点
			//当前结点的前驱结点的右孩子一定为nullptr
			RBNode* replaceNode = curNode->lchild;
			while (replaceNode->rchild != nullptr)
				replaceNode = replaceNode->rchild;
			//将当前结点和替换结点的val color key进行交换
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