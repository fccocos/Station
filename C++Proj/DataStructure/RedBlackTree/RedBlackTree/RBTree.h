#ifndef RBTREE_H
#define RBTREE_H

template<class T1,class T2>
class RBTree {
public:
	RBTree();
	~RBTree();
	/*
	* @brief ������������
	*/
	void clear();
public:
	/*�жϼ�ֵ���Ƿ��ں������*/
	//ע�⣺��ֵ����key��Ψһ�ģ�value�����ж����ͬ,��һ��keyֻ����һ��value������һ��value�ж����ͬ��key
	/*
	* @brief �ж��ں�������Ƿ���ָ�������� 
	* @param keyΪ���������д�ŵļ�
	* @return �ɹ�����true, ʧ�ܷ���false
	*/
	bool hasKeyValue(const T1& key);

	/*
	* @brief �жϵ�ǰ������Ƿ�Ϊ��
	* @return ��Ϊ�շ���false, Ϊ�շ���true
	*/
	bool empty();

	/*
	* @brief �ж��ں�������Ƿ���ָ��������
	* @param valΪ���������д�ŵ�ֵ
	* @param count���ڷ���key�ĸ���
	* @return �ɹ�����true, ʧ�ܷ���false
	*/
	bool hasKeyValue(const T2& val);


	/*��ȡ����*/
   
	/*
	* @brief ͨ��key����ȡval
	* @param keyΪ��ֵ���еļ�
	* @return �ɹ����ز���keyָ���ļ�ֵ���е�ֵ�����򷵻�nullptr
	*/
	T2& getVal(const T1& key);

	/*
	* @brief ͨ��val����ȡkey
	* @param valΪ��ֵ���е�ֵ
	* @return �ɹ����ز���valָ���ļ�ֵ���е�ֵ���飬���򷵻�nullptr
	*/
	T1* getKey(const T2& val, int &count);

	
	/*ɾ��ָ�����*/

	/*
	* @brief ͨ��key��ָ�����������ɾ��
	* @param keyΪ��ֵ���еļ�
	* @return �ɹ����ص�ǰ���󣬷��򷵻�nullptr
	*/
	RBTree<T1, T2>& remove(const T1& key);
	
	/*
	* @brief ͨ��val��ָ�����������ɾ����ɾ����Ϊ�����ҵ�����һ����ڽ��
	* @param valΪ��ֵ���е�ֵ
	* @return �ɹ����ص�ǰ���󣬷��򷵻�nullptr
	*/
	RBTree<T1, T2>& remove(const T2& val);

	/*������*/
	/*
	* @brief ͨ��ָ����ֵ����������
	* @param valΪ��ֵ���е�ֵ
	* @param keyΪ��ֵ���еļ�
	* @return �ɹ����ص�ǰ���󣬷��򷵻�nullptr
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
	/*˽���������͵Ķ���*/

	/*����������ɫ����*/
	enum class NodeColor{ RED, BLACK };
	/*�����������*/
	enum class TreeSide { LEFT, RIGHT};
	/*��������ṹ��*/
	struct RBNode {
		T1 key;                          //��key
		T2 val;                          //ֵvalue
		struct RBNode* parent;           //ָ�򸸽��
		struct RBNode* lchild;           //ָ������
		struct RBNode* rchild;           //ָ���Һ���
		NodeColor color = NodeColor::RED;//�����ɫ���ԣ�Ĭ��Ϊ��ɫ
	};
private:
	//˽�в���

	/*�ݹ�����ָ�����*/
	void cleanUp(RBNode* node);

	/*����*/
	void rotateLeft(RBNode* node);

	/*�ҵ���*/
	void rotateRight(RBNode* node);

	/*�޸�"������ɫ���"*/
		/*
	*
	* ������򣺲���Ľ��Ĭ��Ϊ��ɫ����������ƻ��������
	*
	*  1. �����Ϊ������ֱ�Ӳ����㣬����ɫ��ɺ�ɫ��
	*
	*  2. ����λ�õĸ�����Ǻ�ɫ��ֱ�Ӳ��룬����Ҫ��������
	*
	*  3. ����λ�õĸ����Ϊ��ɫ��������Ϊ��ɫ���Ƚ������뵽��ǰλ�ã�
	*	  ��ʱ�����͵�ǰ��㶼Ϊ��ɫ����ʱΥ���˺����������4����·����
	*	  ���ܳ��������ĺ�ɫ�������Ҫ�Խ�������ɫ���������游����ɺ�
	*	  ɫ�����������������ɺ�ɫ��
	*
	*  	  1. ����游���ĸ����Ϊ��ɫ��������Ҫ���游���Ϊ��ʼλ�ÿ�ʼ��
	*        �ϼ���������ֱ�����������������Ķ��塣
	*
	*  	  2. ����游���ĸ����Ϊ��ɫ�����ǾͲ���Ҫ���е�����
	*
	*  4. ����λ�õĸ����Ϊ��ɫ��������Ϊ��ɫ��û������
	*  	  1. ����λ��Ϊ���ӵ��������ϣ������׽��Ϊ�游�������ӣ�����
	*		 λ��Ϊ���׵��Һ��ӣ���ʱ�ȶԸ��׽����һ��������Ȼ����游���
	*		 ��һ����������������ң�����ٽ��游������ɫ��ɺ�ɫ�������
	*		 �����ɫ��ɺ�ɫ��
	*
	*  	  2. ����λ��Ϊ���ӵ��������ϣ������׽��Ϊ�游�������ӣ�����
	*		 λ��Ϊ���׵����ӣ���ʱ�ȶ��游�ڵ���һ���ҵ�����Ȼ���游��
	*		 �����ɫ��ɺ�ɫ�������׽�����ɫ��ɺ�ɫ��
	*
	*  	  3. ����λ��Ϊ�Һ��ӵ��������ϣ������׽��Ϊ�游�����Һ��ӣ�����
	*		 λ��Ϊ���׽������ӣ���ʱ�ȶԸ�����һ��������Ȼ����游���
	*		 ��һ�������������Һ�������ٽ��游������ɫ��ɺ�ɫ������
	*		 ������ɫ��ɺ�ɫ��
	*
	*  	  4. ����λ��Ϊ�Һ��ӵ��������ϣ������׽��Ϊ�游�����Һ��ӣ�����
	*		 λ��Ϊ���׵��Һ��ӣ���ʱ�ȶ��游�ڵ���һ��������Ȼ���游��
	*		 �����ɫ��ɺ�ɫ�������׽�����ɫ��ɺ�ɫ��
	*/
	void fixUpContinuousRedNodes(RBNode* node);
	
	/*�޸���ʧ���㡱*/
	void fixUpUnbalancedNode(RBNode* node);

	/*���ɾ��ʱ���滻����*/
	/*1. ɾ�����û�к��ӽ�㣨��ʱ˵���������һ�㣩
	  2. ɾ�������һ�����ӽ��
	     1. ɾ�����������������ǰ�������滻
	     2. ɾ����������������ú�̽����滻
	  3. ɾ��������������ӽ��
	     1. ɾ��������������������������������ǰ�����̽����滻
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

