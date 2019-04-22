//
//  SingleLinkedList.hpp
//  SingleLinkedList
//
//  Created by dzb on 2019/4/22.
//  Copyright © 2019 dzb. All rights reserved.
//

#ifndef SingleLinkedList_hpp
#define SingleLinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

static const int SL_ELEMENT_NOT_FOUND = -1;

template <typename E>
//单向链表采用尾插法
//单向链表没有虚拟节点
class SingleLinkedList {
	
	class Node { //内部类
	public:
		E m_element;
		Node *m_next;
		//无参构造方法
		Node() : Node(NULL,NULL){}
		//有参构造方法
		Node(E element,Node *next) : m_element(element),m_next(next)  {
		}
		//析构方法
		~Node() {
			cout<<"~Node()" << endl;
		}
	};
	
public:
	//构造方法
	SingleLinkedList();
	//析构方法
	~SingleLinkedList();
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
	Node *m_head;
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
		SingleLinkedList::Node *pFind = m_head->m_next;
		for (int i = 0; i<index; i++) {
			pFind = pFind->m_next;
		}
		return pFind;
	}
};

//无参构造函数
template <typename E>
SingleLinkedList<E>::SingleLinkedList() {
	this->m_head = new SingleLinkedList::Node();
	this->m_size = 0;
}

//析构函数
template <typename E>
SingleLinkedList<E>::~SingleLinkedList() {
	cout<<"~SingleLinkedList()"<<endl;
	//需要开发者自己调用 clear_with_completion 在销毁 linklist之前
	this->clear_with_completion(NULL);
}

/**
 * 元素的数量
 */
template <typename E>
int SingleLinkedList<E>::size() {
	return m_size;
}

/**
 * 是否为空
 */
template <typename E>
bool SingleLinkedList<E>::isEmpty() {
	return m_size == 0;
}

/**
 * 是否包含某个元素
 */
template <typename E>
bool SingleLinkedList<E>::contains(E element) {
	return indexOf(element) != SL_ELEMENT_NOT_FOUND;
}

/**
 * 添加元素到尾部
 */
template <typename E>
void SingleLinkedList<E>::add(E element) {
	add(m_size,element);
}


/**
 * 获取index位置的元素
 */
template <typename E>
E SingleLinkedList<E>::get(int index) {
	/*
	 * 最好：O(1)
	 * 最坏：O(n)
	 * 平均：O(n)
	 */
	rangeCheck(index);
	SingleLinkedList::Node *pFind = node(index);
	E element = pFind->m_element;
	return element;
}

/**
 * 设置index位置的元素 返回上一个值 需要开发者自己拿到这个值后管理内存
 */
template <typename E>
E SingleLinkedList<E>::set(int index, E element) {
	/*
	 * 最好：O(1)
	 * 最坏：O(n)
	 * 平均：O(n)
	 */
	rangeCheck(index);
	SingleLinkedList::Node *pFind = node(index);
	E old = pFind->m_element;
	pFind->m_element = element;
	return old;
}

/**
 * 在index位置插入一个元素
 */
template <typename E>
void SingleLinkedList<E>::add(int index, E element) {
	/*
	 * 最好：O(1)
	 * 最坏：O(n)
	 * 平均：O(n)
	 */
	rangeCheckForAdd(index);
	if (index == 0) {
		SingleLinkedList::Node *pFind = node(index);
		SingleLinkedList::Node *cur = new SingleLinkedList::Node(element,pFind);
		m_head->m_next = cur;
	} else {
		//待添加节点的前一个节点
		SingleLinkedList::Node *pre = node(index-1);
		SingleLinkedList::Node *cur = new SingleLinkedList::Node(element,pre->m_next);
		pre->m_next = cur;
	}
	m_size++;
}

/**
 * 删除index位置的元素
 */
template <typename E>
E SingleLinkedList<E>::remove(int index) {
	/*
	 * 最好：O(1)
	 * 最坏：O(n)
	 * 平均：O(n)
	 */
	rangeCheck(index);
	E element; //要删除的元素
	SingleLinkedList::Node *cur = NULL; //要删除的节点
	if (index == 0) {
		cur = node(index);
		m_head->m_next = cur->m_next;
		element = cur->m_element;
	} else {
		///待删除节点前一个节点
		SingleLinkedList::Node *pre = node(index-1);
		cur = pre->m_next;
		element = cur->m_element;
		pre->m_next = cur->m_next;
	}
	m_size--;
	delete cur; //删除节点 对于节点数据需要开发者自行管理内存
	return element;
}

/**
 * 查看元素的索引
 */
template <typename E>
int SingleLinkedList<E>::indexOf(E element) {
	SingleLinkedList::Node *cur = m_head->m_next;
	for (int i = 0; i<m_size; i++) {
		if (element == cur->m_element) {
			return i;
		}
		cur = cur->m_next;
	}
	return SL_ELEMENT_NOT_FOUND;
}

///遍历所有元素
template <typename E>
void SingleLinkedList<E>::for_each_elements(void(*for_each)(E)) {
	SingleLinkedList::Node *sh = m_head->m_next;
	while (sh != NULL) {
		E obj = sh->m_element;
		sh = sh->m_next;
		if (for_each != NULL) {
			(*for_each)(obj);
		}
	}
}
///销毁链表的元素
template <typename E>
void SingleLinkedList<E>::clear_with_completion(void(*for_each)(E)) {
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
void SingleLinkedList<E>::toString() {
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


#endif /* SingleLinkedList_hpp */
