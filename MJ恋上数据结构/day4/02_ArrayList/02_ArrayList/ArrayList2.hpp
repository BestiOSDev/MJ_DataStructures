//
//  ArrayList2.hpp
//  02_ArrayList
//
//  Created by dzb on 2019/4/22.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#ifndef ArrayList2_hpp
#define ArrayList2_hpp

#include <stdio.h>
#include <iostream>
#include "Array.hpp"

using namespace std;

template <typename E>
//动态数组 ArrayList2 共用继承 Array 并重写父类虚函数
/**
 * 有动态缩容操作
 * @author MJ Lee
 *
 * @param <E>
 */
class ArrayList2 : public Array<E> {
private:
	int m_size;
	E *m_elements;
	int m_capacity;
	///数组越界判断 友元函数 可以访问类成员变量
	void rangeCheck(int index);
	///数组添加越界判断 友元函数 可以访问类成员变量
	void rangeCheckForAdd(int index);
	///数组越界判断 友元函数 可以访问类成员变量
	void outOfBounds(int index);
	//* 保证要有capacity的容量
	void ensureCapacity(int capacity);
public:
	//无参构造函数
	ArrayList2();
	//有参构造函数
	ArrayList2(int capacity);
	//析构函数
	~ArrayList2();
	/**
	 * 清除所有元素
	 */
	void clear_with_completion(void(*for_each)(E));
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
	E  set(int index, E element);
	
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
	//缩容操作
	void trim();
	//打印数组元素
	void toString();
};

//MARK:构造方法

//无参构造方法 调用有参构造函数 相当于initWithCapacity:10
template <typename E>
ArrayList2<E>::ArrayList2() : ArrayList2(DEFAULT_CAPACITY) {
	std::cout<<"ArrayList2() 无参函数" << std::endl;
	
}
// 有参构造函数
template <typename E>
ArrayList2<E>::ArrayList2(int capacity)  {
	std::cout<<"ArrayList2(int capacity) 有参构造函数" << std::endl;
	m_capacity = (capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : capacity;
	m_size = 0;
	m_capacity = capacity;
	//创建int数组 大小为capacity 初始化所有元素为0
	m_elements = new E[capacity]{0};
}
//析构函数
template <typename E>
ArrayList2<E>::~ArrayList2() {
	if (m_elements != nullptr) {
		this->clear_with_completion(NULL);
		delete [] m_elements;
	}
	std::cout<<"~ArrayList2() 析构函数" << std::endl;
}


/**
 * 清除所有元素
 */
template <typename E>
void ArrayList2<E>::clear_with_completion(void(*for_each)(E)) {
	for (int i = 0; i < m_size; i++) {
		E element = m_elements[i];
		if (for_each != NULL) {
			(*for_each)(element);
		}
	}
	m_size = 0;
}

/**
 * 元素的数量
 */
template <typename E>
int ArrayList2<E>::size() {
	return m_size;
}

/**
 * 是否为空
 */
template <typename E>
bool ArrayList2<E>::isEmpty() {
	return m_size == 0;
}

/**
 * 是否包含某个元素
 */
template <typename E>
bool ArrayList2<E>::contains(E element) {
	return indexOf(element) != ELEMENT_NOT_FOUND;
}

/**
 * 添加元素到尾部
 */
template <typename E>
void ArrayList2<E>::add(E element) {
	add(m_size,element);
}

/**
 * 获取index位置的元素
 */
template <typename E>
E ArrayList2<E>::get(int index) { // O(1)
	rangeCheck(index);
	return m_elements[index];
}

/**
 * 设置index位置的元素
 * @return 原来的元素ֵ
 */
template <typename E>
E ArrayList2<E>::set(int index, E element) { // O(1)
	rangeCheck(index);
	E old = m_elements[index];
	m_elements[index] = element;
	return old;
}

/**
 * 在index位置插入一个元素
 */
template <typename E>
void ArrayList2<E>::add(int index, E element) {
	/*
	 * 最好：O(1)
	 * 最坏：O(n)
	 * 平均：O(n)
	 */
	rangeCheckForAdd(index);
	ensureCapacity(m_size + 1);
	for (int i = m_size - 1; i >= index; i--) {
		m_elements[i + 1] = m_elements[i];
	}
	m_elements[index] = element;
	m_size++;
} // size是数据规模

/**
 * 删除index位置的元素
 */
template <typename E>
E ArrayList2<E>::remove(int index) {
	/*
	 * 最好：O(1)
	 * 最坏：O(n)
	 * 平均：O(n)
	 */
	rangeCheck(index);
	E ret = m_elements[index];
	for(int i = index + 1 ; i < m_size ;i ++) {
		m_elements[i - 1] = m_elements[i];
	}
	m_size --;
	///进行缩容
	trim();
	return ret;
}

/**
 * 查看元素的索引
 */
template <typename E>
int ArrayList2<E>::indexOf(E element) {
	for (int i = 0; i < m_size; i++) {
		if (m_elements[i] == element)
			return i;
	}
	return ELEMENT_NOT_FOUND;
}

///打印数组内容
template <typename E>
void ArrayList2<E>::toString() {
	std::cout << "[";
	for (int i = 0; i < m_size; ++i) {
		if (i != 0) {
			std::cout << ", ";
		}
		E t = m_elements[i];
		std::cout << t;
	}
	std::cout << "]" << endl;
}


#pragma mark - private functions

///数组越界判断 友元函数 可以访问类成员变量
template <typename E>
void ArrayList2<E>::rangeCheck(int index) {
	if (index < 0 || index >= m_size) {
		outOfBounds(index);
	}
	
}
///数组添加越界判断 友元函数 可以访问类成员变量
template <typename E>
void ArrayList2<E>::rangeCheckForAdd(int index) {
	if (index < 0 || index > m_size) {
		outOfBounds(index);
	}
}

///数组越界判断 友元函数 可以访问类成员变量
template <typename E>
void ArrayList2<E>::outOfBounds(int index) {
	throw "Index out of bounds";
}

/**
 * 保证要有capacity的容量
 */
template <typename E>
void ArrayList2<E>::ensureCapacity(int capacity) {
	int oldCapacity = m_capacity;
	if (oldCapacity >= capacity) return;
	
	// 新容量为旧容量的1.5倍
	int newCapacity = oldCapacity + (oldCapacity >> 1);
	//创建一个新的数组 容量是原来数组容量的1.5倍
	//新的数组
	E *newElements =  new E[newCapacity]{0};
	//旧的数组
	E *oldElements = m_elements;
	//旧值的拷贝
	size_t size = sizeof(E) * m_size;
	memcpy(newElements, oldElements, size);
	m_elements = newElements;
	//是否旧值
	delete [] oldElements;
	m_capacity = newCapacity;
	cout << oldCapacity << " 扩容为 " << newCapacity << endl;

}

/**
 动态缩容操作
 */
template <typename E>
void ArrayList2<E>::trim() {
	// 30
	int oldCapacity = m_capacity;
	// 15
	int newCapacity = oldCapacity >> 1;
	if (m_size > (newCapacity) || oldCapacity <= DEFAULT_CAPACITY) return;
	
	//新的数组
	E *newElements =  new E[newCapacity]{0};
	//旧的数组
	E *oldElements = m_elements;
	//旧值的拷贝
	size_t size = sizeof(E) * m_size;
	memcpy(newElements, oldElements, size);
	m_elements = newElements;
	//是否旧值
	delete [] oldElements;
	m_capacity = newCapacity;

	cout << oldCapacity << " 缩容为 " << newCapacity << endl;
	
}
#endif /* ArrayList2_hpp */
