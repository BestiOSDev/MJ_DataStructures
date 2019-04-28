//
//  ArrayQueue.hpp
//  05-Array-Queue
//
//  Created by dzb on 2019/3/4.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#ifndef ArrayQueue_hpp
#define ArrayQueue_hpp

#include <stdio.h>
#include "Queue.hpp"
#include <iostream>
#include "ArrayList.hpp"

using namespace std;

template <typename E>
class ArrayQueue : public Queue<E> {
private:
	ArrayList<E> *m_array;
public:
	///构造方法
	explicit  ArrayQueue();
	explicit  ArrayQueue(int capacity);
	///析构函数
	~ArrayQueue();
	int getSize();
	bool isEmpty();
	void enqueue(E e);
	int getCapacity();
	E dequeue();
	E getFront();
	void toString();
};

///构造方法
template <typename E>
ArrayQueue<E>::ArrayQueue() :ArrayQueue(10) { }

template <typename E>
ArrayQueue<E>::ArrayQueue(int capacity) {
	m_array = new ArrayList<E>(capacity);
}
///析构函数
template <typename E>
ArrayQueue<E>::~ArrayQueue() {
	if (m_array != nullptr) {
		delete m_array;
		m_array = nullptr;
	}
}

template <typename E>
int ArrayQueue<E>::getSize() {
	return m_array->getSize();
}

template <typename E>
bool ArrayQueue<E>::isEmpty() {
	return m_array->isEmpty();
}

template <typename E>
int ArrayQueue<E>::getCapacity() {
	return m_array->getCapacity();
}


template <typename E>
void ArrayQueue<E>::enqueue(E e) {
	m_array->addLast(e);
}

template <typename E>
E ArrayQueue<E>::dequeue() {
	return m_array->removeFirst();
}

template <typename E>
E ArrayQueue<E>::getFront() {
	return m_array->getFirst();
}

template <typename E>
void ArrayQueue<E>::toString() {
	cout << "Queue: " << "front [";
	size_t _size = m_array->getSize();
	for (int i = 0; i < _size; ++i) {
		E e = m_array->objectAtIndex(i);
		if (i != 0) {
			cout << ", ";
		}
		cout << e;
	}
	cout << "] tail" << endl;
}

#endif /* ArrayQueue_hpp */
