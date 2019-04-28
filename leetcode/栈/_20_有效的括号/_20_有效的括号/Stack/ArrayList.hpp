//
//  ArrayList.hpp
//  02-Create-Our-Own-Array
//
//  Created by dzb on 2019/2/27.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <stdio.h>
#include <iostream>

#pragma mark - ArrayList interface

template <class T>
class ArrayList {
    
private:
    T *_data; /// int型指针数组
    int _size; ///数组元素个数
    int _capacity; ///数组容量
    // 将数组空间的容量变成newCapacity大小
    void resize(int newCapacity);
public:
    ///构造方法
    explicit  ArrayList();
    explicit  ArrayList(int capacity);
    ///析构函数
    ~ArrayList();
    // 获取数组的容量
    int getCapacity();
    ///获取数组中的元素个数
    int getSize();
    // 返回数组是否为空
    bool isEmpty();
    // 向所有元素后添加一个新元素
    void addLast(T element);
    // 在所有元素前添加一个新元素
    void addFirst(T element);
    /// 在数组任意位置插入一个元素
    void insert(T element,int index);
    /// 获取index索引位置的元素
    T objectAtIndex(int index);
    /// 获取数组最后一个元素
    T getLast();
    /// 获取数组首元素
    T getFirst();
    /// 修改index索引位置的元素为e
    void setObject(T element,int index);
    // 查找数组中是否有元素e
    bool contains(T e);
    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    int find(T e);
    // 从数组中删除index位置的元素, 返回删除的元素
    T remove(int index);
    // 从数组中删除第一个元素, 返回删除的元素
    T removeFirst();
    // 从数组中删除最后一个元素, 返回删除的元素
    T removeLast();
    // 从数组中删除元素e
    void removeElement(T e);
    ///打印内部元素
    void print();
};

#pragma mark - ArrayList implementation

using namespace std;

template <class T>
/**
 默认数组容量是10
 */
ArrayList<T>::ArrayList() : ArrayList(10) {
//    cout << "ArrayList()构造函数" << endl;
}

template <class T>
ArrayList<T> ::ArrayList(int capacity) {
    _capacity = capacity;
    _size = 0;
    _data = new T[capacity]();
//    cout << "ArrayList(int capacity)构造函数" << endl;
}

template <class T>
int ArrayList<T>::getCapacity() {
    return _capacity;
}

template <class T>
int ArrayList<T>::getSize() {
    return _size;
}

template <class T>
bool ArrayList<T>::isEmpty() {
    return _size == 0;
}

template <class T>
ArrayList<T>::~ArrayList() {
//    cout << "~ArrayList()析构函数" << endl;
    if (_data != nullptr) {
        delete [] _data;
        _data = nullptr;
    }
}

#pragma mark - 添加元素
template <class T>
// 向所有元素后添加一个新元素
void ArrayList<T>::addLast(T element) {
    insert(element,_size);
}
template <class T>
// 在所有元素前添加一个新元素
void ArrayList<T>::addFirst(T element) {
    insert(element,0);
}

template <class T>
void ArrayList<T>::insert(T element,int index) {
    
    if(index < 0 || index > _size) {
        throw "Add failed. Require index >= 0 and index <= size.";
    }
    
    if (_size == _capacity) {
        resize(2 * _capacity);
    }
    
    ///交换索引位置 移动数组索引位置 主要是针对往数组中间位置插入元素时候 需要移动元素位置
    for(int i = ( _size - 1);(i >= index && i >= 0); i--) {
        _data[i + 1] = _data[i];
    }
    
    _data[index] = element;
    _size ++;
}

template <class T>
/// 修改index索引位置的元素为e
void ArrayList<T>::setObject(T element, int index) {
    if(index < 0 || index >= _size) {
        throw "Set failed. Index is illegal.";
    }
    _data[index] = element;
}
#pragma mark - 查找

/// 获取数组最后一个元素
template <class T>
T ArrayList<T>::getLast() {
    return objectAtIndex(_size);
}

/// 获取数组首元素
template <class T>
T ArrayList<T>::getFirst() {
    return objectAtIndex(0);
}

template <class T>
// 查找数组中是否有元素e
bool ArrayList<T>::contains(T e) {
    for(int i = 0 ; i < _size ; i ++){
        if(_data[i] == e)
            return true;
    }
    return false;
}

template <class T>
// 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
int ArrayList<T>::find(T e) {
    for(int i = 0 ; i < _size ; i ++){
        if(_data[i] == e)
            return i;
    }
    return -1;
}

template <class T>
/// 获取index索引位置的元素
T ArrayList<T>::objectAtIndex(int index) {
    if (index < 0 || index >= _size) {
        throw "Get failed. Index is illegal." ;
    }
    return _data[index];
}

#pragma mark - 删除
template <class T>
// 从数组中删除index位置的元素, 返回删除的元素
T ArrayList<T>::remove(int index) {
    if(index < 0 || index >= _size) {
        throw "Remove failed. Index is illegal." ;
    }
    T ret = _data[index];
    for(int i = index + 1 ; i < _size ; i ++)
        _data[i - 1] = _data[i];
    _size --;
    ///数组的缩容操作
    if(_size == _capacity / 4 && _capacity / 2 != 0) {
        resize(_capacity / 2);
    }
    return ret;
}
template <class T>
// 从数组中删除第一个元素, 返回删除的元素
T ArrayList<T>::removeFirst() {
    return remove(0);
}
template <class T>
// 从数组中删除最后一个元素, 返回删除的元素
T ArrayList<T>::removeLast() {
    return remove(_size-1);
}

template <class T>
// 从数组中删除元素e
void ArrayList<T>::removeElement(T e) {
    int index = find(e);
    if(index != -1)
        remove(index);
}

template <class T>
void ArrayList<T>::print() {
    std::cout << "[";
    for (int i = 0; i < _size; ++i) {
        T t = _data[i];
        std::cout << t;
        if (i != _size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << endl;
}

template <class T>

// 将数组空间的容量变成newCapacity大小
void ArrayList<T>::resize(int newCapacity){
    T *oldData = _data; ///旧数据
    T *newData = new T[newCapacity](); ///新数组
    
    size_t size = sizeof(T) * _size;
    memcpy(newData,oldData,size); ///对旧的数组进行值的拷贝
    //  也可以通过便利数组 将旧数组的值 拷贝到新数组中
    //    for(int i = 0 ; i < _size ; i ++)
    //        newData[i] = oldData[i];
    //
    delete [] oldData;
    _data = newData;
    _capacity = newCapacity;
}


#endif /* ArrayList_hpp */
