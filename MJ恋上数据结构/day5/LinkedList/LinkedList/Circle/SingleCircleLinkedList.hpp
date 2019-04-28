//
//  SingleCircleLinkedList.hpp
//  SingleCircleLinkedList
//
//  Created by dzb on 2019/4/28.
//  Copyright © 2019 dzb. All rights reserved.
//

#ifndef SingleCircleLinkedList_hpp
#define SingleCircleLinkedList_hpp

#include <stdio.h>

using namespace std;

static const int CIRCLE_ELEMENT_NOT_FOUND = -1;

template <typename E>
//双向循环链表
class SingleCircleLinkedList {
	
	class Node { //内部类
	public:
		E m_element;
		Node *m_next; //后驱
		//无参构造方法
		Node() : Node(NULL,NULL,NULL){}
		//有参构造方法
		Node(E element,Node *next,Node *pre) : m_element(element),m_next(next)  {
		}
		//析构方法
		~Node() {
			cout<<"~Node()" << endl;
		}
	};
	
public:
	//构造方法
	SingleCircleLinkedList();
	//析构方法
	~SingleCircleLinkedList();
	/**
	 * 元素的数量
	 */
	int size();
	
	/**
	 * 是否为空
	 */
	bool isEmpty();
	
	/**
	 * 是否包含某个元素
	 */
	bool contains(E element);
	
	/**
	 * 添加元素到尾部
	 */
	void add(E element);
	
	/**
	 * 获取index位置的元素
	 */
	E get(int index);
	
	/**
	 * 设置index位置的元素
	 */
	E set(int index, E element);
	
	/**
	 * 在index位置插入一个元素
	 */
	void add(int index, E element);
	
	/**
	 * 删除index位置的元素
	 */
	E remove(int index);
	
	/**
	 * 查看元素的索引
	 */
	int indexOf(E element);
	///遍历所有元素
	void for_each_elements(void(*for_each)(E));
	///销毁链表的元素
	void clear_with_completion(void(*for_each)(E));
	//打印链表元素
	void toString();
	
private:
	Node *_header;
	int m_size;
	void outOfBounds(int index) {
		throw "Index out of bounds";
	}
	void rangeCheck(int index) {
		if (index < 0 || index >= m_size) {
			outOfBounds(index);
		}
	}
	void rangeCheckForAdd(int index) {
		if (index < 0 || index > m_size) {
			outOfBounds(index);
		}
	}
	Node *node(int index) {
		SingleCircleLinkedList::Node *cur = _header->m_next;
		for (int i = 0; i < index; i++) {
			cur = cur->m_next;
		}
		return cur;
	}
};

//无参构造函数
template <typename E>
SingleCircleLinkedList<E>::SingleCircleLinkedList() {
	this->m_size = 0;
	this->_header = new SingleCircleLinkedList::Node();
	_header->m_next = _header;
}

//析构函数
template <typename E>
SingleCircleLinkedList<E>::~SingleCircleLinkedList() {
	cout<<"~SingleCircleLinkedList()"<<endl;
	//需要开发者自己调用 clear_with_completion 在销毁 linklist之前
	this->clear_with_completion(NULL);
}

/**
 * 元素的数量
 */
template <typename E>
int SingleCircleLinkedList<E>::size() {
	return m_size;
}

/**
 * 是否为空
 */
template <typename E>
bool SingleCircleLinkedList<E>::isEmpty() {
	return m_size == 0;
}

/**
 * 是否包含某个元素
 */
template <typename E>
bool SingleCircleLinkedList<E>::contains(E element) {
	return indexOf(element) != ELEMENT_NOT_FOUND;
}

/**
 * 添加元素到尾部
 */
template <typename E>
void SingleCircleLinkedList<E>::add(E element) {
	add(m_size,element);
}


/**
 * 获取index位置的元素
 */
template <typename E>
E SingleCircleLinkedList<E>::get(int index) {
	rangeCheck(index);
	SingleCircleLinkedList::Node *pFind = node(index);
	E element = pFind->m_element;
	return element;
}

/**
 * 设置index位置的元素 返回上一个值 需要开发者自己拿到这个值后管理内存
 */
template <typename E>
E SingleCircleLinkedList<E>::set(int index, E element) {
	rangeCheck(index);
	SingleCircleLinkedList::Node *pFind = node(index);
	E old = pFind->m_element;
	pFind->m_element = element;
	return old;
}

/**
 * 在index位置插入一个元素
 */
template <typename E>
void SingleCircleLinkedList<E>::add(int index, E element) {
	rangeCheckForAdd(index);
	//把双向循环链表 想象成汉堡包🍔 就不难立即 add 方法怎么实现
	SingleCircleLinkedList::Node *cur = new SingleCircleLinkedList::Node();
	cur->m_element = element;
	cur->m_next = _header->m_next;
	_header->m_next = cur;
	m_size++;
}

/**
 * 删除index位置的元素
 */
template <typename E>
E SingleCircleLinkedList<E>::remove(int index) {
	rangeCheck(index);
	SingleCircleLinkedList::Node *prev = node(index-1); ///要删除节点
	SingleCircleLinkedList::Node *cur = prev->m_next; ///要删除节点的前驱
	prev->m_next = cur->m_next;
	E element = cur->m_element; //要删除的元素
	delete cur; //删除节点 对于节点数据需要开发者自行管理内存
	m_size--;
	return element;
}

/**
 * 查看元素的索引
 */
template <typename E>
int SingleCircleLinkedList<E>::indexOf(E element) {
	SingleCircleLinkedList::Node *cur = _header->m_next;
	for (int i = 0; i<m_size; i++) {
		if (element == cur->m_element) {
			return i;
		}
		cur = cur->m_next;
	}
	return ELEMENT_NOT_FOUND;
}

///遍历所有元素
template <typename E>
void SingleCircleLinkedList<E>::for_each_elements(void(*for_each)(E)) {
	SingleCircleLinkedList::Node *sh = _header->m_next;
	while (sh != _header) {
		E obj = sh->m_element;
		sh = sh->m_next;
		if (for_each != NULL) {
			(*for_each)(obj);
		}
	}
}
///销毁链表的元素
template <typename E>
void SingleCircleLinkedList<E>::clear_with_completion(void(*for_each)(E)) {
	if (size() == 0) return;
	while (m_size > 0) {
		E old = remove(m_size-1);
		if (for_each != NULL) {
			(*for_each)(old);
		}
	}
}

//打印元素
template <typename E>
void SingleCircleLinkedList<E>::toString() {
	std::cout << "[ ";
	for (int i = 0; i<m_size;i++) {
		if (i != 0) {
			cout << ",";
		}
		E element = get(i);
		cout<<element;
	}
	cout<<" ]"<<endl;
}

#endif /* SingleCircleLinkedList_hpp */

