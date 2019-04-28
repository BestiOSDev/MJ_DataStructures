//
//  ArrayStack.hpp
//  02-Array-Stack
//
//  Created by dzb on 2019/3/3.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#ifndef ArrayStack_hpp
#define ArrayStack_hpp

#include <stdio.h>
#include "Stack.hpp"
#include "ArrayList.hpp"


template <typename E>
class ArrayStack : public Stack<E> {
private:
    ArrayList<E> *array;
public:
    ArrayStack();
    ArrayStack(int capacity);
    ~ArrayStack();
    int getSize();
    int getCapacity();
    bool isEmpty();
    void push(E e);
    E pop();
    E peek();
    ///输出栈中所有元素
    void toString();
};
#pragma mark 构造 析构函数
template <typename E>
ArrayStack<E>::ArrayStack() : ArrayStack(10) {
    
}

template <typename E>
ArrayStack<E>::ArrayStack(int capacity) {
//    cout<<"ArrayStack<E>::ArrayStack(int capacity) "<<endl;
    array = new ArrayList<E>(capacity);
}

template <typename E>
ArrayStack<E>::~ArrayStack() {
    if (array != nullptr) {
        delete array;
        array = nullptr;
    }
//    cout << "ArrayStack<E>::~ArrayStack()" << endl;
}

template <typename E>
int ArrayStack<E>::getSize() {
    return array->getSize();
}
template <typename E>
bool ArrayStack<E>::isEmpty() {
    return array->isEmpty();
}

template <typename E>
int ArrayStack<E>::getCapacity() {
    return 0;
}

template <typename E>
void ArrayStack<E>::push(E e) {
    array->addLast(e);
}

template <typename E>
E ArrayStack<E>::pop() {
    return array->removeLast();
}

template <typename E>
E ArrayStack<E>::peek() {
    return array->getLast();
}

template <typename E>
void ArrayStack<E>::toString() {
    cout << "Stack: [";
    for (int i = 0; i <array->getSize(); ++i) {
        E t = array->objectAtIndex(i);
        if (i != 0) {
            cout << ", ";
        }
        std::cout << t;
    }
    cout << "] top" << endl;
}

#endif /* ArrayStack_hpp */
