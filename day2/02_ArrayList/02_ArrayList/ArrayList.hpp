//
//  ArrayList.hpp
//  02_ArrayList
//
//  Created by dzb on 2019/4/15.
//  Copyright © 2019年 dzb. All rights reserved.
//

#ifndef ArrayList_hpp
#define ArrayList_hpp


#include <stdio.h>
#include <iostream>
#include "Array.hpp"

using namespace std;

template <typename E>
//动态数组 ArrayList 共用继承 Array 并重写父类虚函数

class ArrayList : public Array<E> {
private:
	int m_size;
	E *m_elements;
	int m_capacity;
public:
	//无参构造函数
	ArrayList();
	//有参构造函数
	ArrayList(int capacity);
	//析构函数
	~ArrayList();
	/**
	 * 清除所有元素
	 */
	void clear();
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
	 * @return 原来的元素ֵ
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
	
};



static int DEFAULT_CAPACITY = 10;
static int ELEMENT_NOT_FOUND = 10;

//MARK:构造方法

//无参构造方法 调用有参构造函数 相当于initWithCapacity:10
template <typename E>
ArrayList<E>::ArrayList() : ArrayList(DEFAULT_CAPACITY) {
	std::cout<<"ArrayList() 无参函数" << std::endl;
	
}
// 有参构造函数
template <typename E>
ArrayList<E>::ArrayList(int capacity)  {
	std::cout<<"ArrayList(int capacity) 有参构造函数" << std::endl;
	
	if (capacity < DEFAULT_CAPACITY) {
		capacity = DEFAULT_CAPACITY;
	}
	m_size = 0;
	m_capacity = capacity;
	//创建int数组 大小为capacity 初始化所有元素为0
	m_elements = new E[capacity]{0};
}
//析构函数
template <typename E>
ArrayList<E>::~ArrayList() {
	if (m_elements != nullptr) {
		delete [] m_elements;
	}
	std::cout<<"~ArrayList() 析构函数" << std::endl;
}

/**
 * 清除所有元素
 */
template <typename E>
void ArrayList<E>::clear() {
	m_size = 0;
}

/**
 * 元素的数量
 */
template <typename E>
int ArrayList<E>::size() {
	return m_size;
}

/**
 * 是否为空
 */
template <typename E>
bool ArrayList<E>::isEmpty() {
	return m_size == 0;
}


/**
 * 是否包含某个元素
 */
template <typename E>
bool ArrayList<E>::contains(E element) {
	return indexOf(element) != ELEMENT_NOT_FOUND;
}

/**
 * 添加元素到尾部
 */
template <typename E>
void ArrayList<E>::add(E element) {
	
}

/**
 * 获取index位置的元素
 */
template <typename E>
E ArrayList<E>::get(int index) {
	if (index < 0 || index >= m_size) {
		throw "Index out of bounds";
	}
	return m_elements[index];
}

/**
 * 设置index位置的元素
 * @return 原来的元素ֵ
 */
template <typename E>
E ArrayList<E>::set(int index, E element) {
	if (index < 0 || index >= m_size) {
		throw "Index out of bounds";
	}
	int old = m_elements[index];
	m_elements[index] = element;
	return old;
}

/**
 * 在index位置插入一个元素
 */
template <typename E>
void ArrayList<E>::add(int index, E element) {
	
}

/**
 * 删除index位置的元素
 */
template <typename E>
E ArrayList<E>::remove(int index) {
	return 0;
}

/**
 * 查看元素的索引
 */
template <typename E>
int ArrayList<E>::indexOf(E element) {
	for (int i = 0; i < m_size; i++) {
		if (m_elements[i] == element) return i;
	}
	return ELEMENT_NOT_FOUND;
}

#endif /* ArrayList_hpp */

