#ifndef RBTREE_H
#define RBTREE_H

template<class T1,class T2>
class RBTree {
public:
	RBTree();
	~RBTree();
	/*
	* @brief 用于清除红黑树
	*/
	void clear();
public:
	/*判断键值对是否在红黑树中*/
	//注意：键值对中key是唯一的，value可以有多个相同,即一个key只能有一个value，但是一个value有多个不同的key
	/*
	* @brief 判断在红黑树中是否有指定的内容 
	* @param key为红黑树结点中存放的键
	* @return 成功返回true, 失败返回false
	*/
	bool hasKeyValue(const T1& key);

	/*
	* @brief 判断当前红黑树是否为空
	* @return 不为空返回false, 为空返回true
	*/
	bool empty();

	/*
	* @brief 判断在红黑树中是否有指定的内容
	* @param val为红黑树结点中存放的值
	* @param count用于返回key的个数
	* @return 成功返回true, 失败返回false
	*/
	bool hasKeyValue(const T2& val);


	/*获取数据*/
   
	/*
	* @brief 通过key来获取val
	* @param key为键值对中的键
	* @return 成功返回参数key指定的键值对中的值，否则返回nullptr
	*/
	T2& getVal(const T1& key);

	/*
	* @brief 通过val来获取key
	* @param val为键值对中的值
	* @return 成功返回参数val指定的键值对中的值数组，否则返回nullptr
	*/
	T1* getKey(const T2& val, int &count);

	
	/*删除指定结点*/

	/*
	* @brief 通过key来指定结点来进行删除
	* @param key为键值对中的键
	* @return 成功返回当前对象，否则返回nullptr
	*/
	RBTree<T1, T2>& remove(const T1& key);
	
	/*
	* @brief 通过val来指定结点来进行删除，删除的为最先找到的那一个红黑结点
	* @param val为键值对中的值
	* @return 成功返回当前对象，否则返回nullptr
	*/
	RBTree<T1, T2>& remove(const T2& val);

	/*插入结点*/
	/*
	* @brief 通过指定键值对来插入结点
	* @param val为键值对中的值
	* @param key为键值对中的键
	* @return 成功返回当前对象，否则返回nullptr
	*/
	RBTree<T1, T2>& insert(const T1& key, const T2& val);

	void show()
	{
		if (root != nullptr)
			MidShow(root);
	}

	void reverse_show()
	{
	 if (root != nullptr)
		ReverseShow(root);
	}
	
private:
	/*私有数据类型的定义*/

	/*红黑树结点颜色属性*/
	enum class NodeColor{ RED, BLACK };
	/*红黑树边属性*/
	enum class TreeSide { LEFT, RIGHT};
	/*红黑树结点结构体*/
	struct RBNode {
		T1 key;                          //键key
		T2 val;                          //值value
		struct RBNode* parent;           //指向父结点
		struct RBNode* lchild;           //指向左孩子
		struct RBNode* rchild;           //指向右孩子
		NodeColor color = NodeColor::RED;//结点颜色属性，默认为红色
	};
private:
	//私有操作

	/*递归的清空指定结点*/
	void cleanUp(RBNode* node);

	/*左单旋*/
	void rotateLeft(RBNode* node);

	/*右单旋*/
	void rotateRight(RBNode* node);

	/*修复"连续红色结点"*/
		/*
	*
	* 插入规则：插入的结点默认为红色，插入后不能破坏红黑树。
	*
	*  1. 红黑树为空树：直接插入结点，将颜色变成黑色。
	*
	*  2. 插入位置的父结点是黑色：直接插入，不需要做调整。
	*
	*  3. 插入位置的父结点为红色且叔叔结点为红色：先将结点插入到当前位置，
	*	  此时父结点和当前结点都为红色，此时违背了红黑树的性质4，即路径上
	*	  不能出现连续的红色。因此需要对结点进行颜色调整，将祖父结点变成红
	*	  色，将父结点和叔叔结点变成黑色。
	*
	*  	  1. 如果祖父结点的父结点为红色，我们需要以祖父结点为起始位置开始向
	*        上继续调整，直到整个树满足红黑树的定义。
	*
	*  	  2. 如果祖父结点的父结点为黑色，我们就不需要进行调整。
	*
	*  4. 插入位置的父结点为红色，叔叔结点为黑色或没有叔叔
	*  	  1. 插入位置为左孩子的右子树上，即父亲结点为祖父结点的左孩子，插入
	*		 位置为父亲的右孩子：此时先对父亲结点做一次左旋，然后对祖父结点
	*		 做一次右旋，即先左后右，其次再将祖父结点的颜色变成红色，插入结
	*		 点的颜色变成黑色。
	*
	*  	  2. 插入位置为左孩子的左子树上，即父亲结点为祖父结点的左孩子，插入
	*		 位置为父亲的左孩子：此时先对祖父节点做一次右单旋，然后将祖父结
	*		 点的颜色变成红色，将父亲结点的颜色变成黑色。
	*
	*  	  3. 插入位置为右孩子的左子树上，即父亲结点为祖父结点的右孩子，插入
	*		 位置为父亲结点的左孩子：此时先对父亲做一次右旋，然后对祖父结点
	*		 做一次左旋，即先右后左，其次再将祖父结点的颜色变成红色，插入
	*		 结点的颜色变成黑色。
	*
	*  	  4. 插入位置为右孩子的右子树上，即父亲结点为祖父结点的右孩子，插入
	*		 位置为父亲的右孩子：此时先对祖父节点做一次左单旋，然后将祖父结
	*		 点的颜色变成红色，将父亲结点的颜色变成黑色。
	*/
	void fixUpContinuousRedNodes(RBNode* node);
	
	/*修复“失衡结点”*/
	void fixUpUnbalancedNode(RBNode* node);

	/*结点删除时的替换操作*/
	/*1. 删除结点没有孩子结点（此时说明已在最后一层）
	  2. 删除结点有一个孩子结点
	     1. 删除结点有左子树，用前驱进行替换
	     2. 删除结点有右子树，用后继进行替换
	  3. 删除结点有两个孩子结点
	     1. 删除结点既有左子树又有右子树，可以用前驱或后继进行替换
	*/
	void  replaceLastNode(RBNode*& node);

	void MidShow(RBNode* node);
	void ReverseShow(RBNode* node);
	
private:
	RBNode* root = nullptr;

};

template <class T>
inline void swap(T& a, T& b);

#endif

