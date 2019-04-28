//
//  LoopQueue.hpp
//  06-Loop-Queue
//
//  Created by dzb on 2019/3/4.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#ifndef LoopQueue_hpp
#define LoopQueue_hpp

#include <stdio.h>
#include "Queue.hpp"
#include <iostream>
#include "ArrayList.hpp"

using namespace std;

template <typename E>
class LoopQueue : public Queue<E> {
private:
	E *_data;
	int _front; ///队首
	int _tail; ///队尾
	int _size; ///队列元素个数
	int _capacity; ///队列容量
	// 有兴趣的同学，在完成这一章后，可以思考一下：
	// LoopQueue中不声明size，如何完成所有的逻辑？
	// 这个问题可能会比大家想象的要难一点点：）
public:
	///构造方法
	explicit  LoopQueue();
	explicit  LoopQueue(int capacity);
	///析构函数
	~LoopQueue();
	int getSize();
	bool isEmpty();
	void enqueue(E e);
	int getCapacity();
	E dequeue();
	E getFront();
	void resize(int newCapacity); ///动态扩容和缩容
	void toString();
};


///构造方法
template <typename E>
LoopQueue<E>::LoopQueue() :LoopQueue(10) { }

template <typename E>
LoopQueue<E>::LoopQueue(int capacity) : _capacity(capacity) , _front(0), _tail(0) , _size(0) {
	_data = new E[_capacity+1]();
}
///析构函数
template <typename E>
LoopQueue<E>::~LoopQueue() {
	if (_data != nullptr) {
		delete _data;
		_data = nullptr;
	}
}

template <typename E>
int LoopQueue<E>::getSize() {
	return _size;
}

template <typename E>
bool LoopQueue<E>::isEmpty() {
	return (bool)(_front == _tail);
}

template <typename E>
int LoopQueue<E>::getCapacity() {
	return (_capacity-1);
}

// 下一小节再做具体实现
template <typename E>
void LoopQueue<E>::enqueue(E e) {
	if((_tail + 1) % _capacity == _front) {
		resize(_capacity * 2);
	}
	_data[_tail] = e;
	_tail = (_tail + 1) % _capacity;
	_size ++;
}
// 下一小节再做具体实现
template <typename E>
E LoopQueue<E>::dequeue() {
	
	if(isEmpty()) {
		throw "Cannot dequeue from an empty queue.";
	}
	E ret = _data[_front];
	_data[_front] = NULL;
	_front = (_front + 1) % _capacity;
	_size --;
	int capacity = getCapacity();
	if(_size == capacity/4 && capacity / 2 != 0) {
		resize(capacity/2);
	}
	return ret;
}
// 下一小节再做具体实现
template <typename E>
E LoopQueue<E>::getFront() {
	if(isEmpty()) {
		throw "Cannot dequeue from an empty queue.";
	}
	return _data[_front];
}

template <typename E>
void LoopQueue<E>::resize(int newCapacity){
	_capacity = newCapacity + 1;
	E *newData = new E[_capacity](); ///新数组
	for(int i = 0 ; i < _size ; i ++) {
		newData[i] = _data[(i + _front) % _capacity];
	}
	delete [] _data;
	_data = newData;
	_front = 0;
	_tail = _size;
}

template <typename E>
void LoopQueue<E>::toString() {

	cout << "Queue: size = " <<_size << " , capacity = " <<_capacity << endl;
	cout << "front [";
	for (int i = _front; i != _tail; i = (i + 1) % _capacity) {
		E e = _data[i];
		cout << e;
		if((i + 1) % _capacity != _tail) {
			cout << ", ";
		}
	}
	cout << "] tail" << endl;
}

#endif /* LoopQueue_hpp */

