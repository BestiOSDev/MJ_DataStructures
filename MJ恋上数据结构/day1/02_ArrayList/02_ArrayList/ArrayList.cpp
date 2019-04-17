//
//  ArrayList.cpp
//  02_ArrayList
//
//  Created by dzb on 2019/4/15.
//  Copyright © 2019年 dzb. All rights reserved.
//

#include "ArrayList.hpp"
#include <iostream>

static int DEFAULT_CAPACITY = 10;
static int ELEMENT_NOT_FOUND = 10;

//MARK:构造方法

//无参构造方法 调用有参构造函数 相当于initWithCapacity:10
ArrayList::ArrayList() : ArrayList(DEFAULT_CAPACITY) {
    std::cout<<"ArrayList() 无参函数" << std::endl;

}
// 有参构造函数
ArrayList::ArrayList(int capacity)  {
    std::cout<<"ArrayList(int capacity) 有参构造函数" << std::endl;

    if (capacity < DEFAULT_CAPACITY) {
        capacity = DEFAULT_CAPACITY;
    }
    m_size = 0;
    m_capacity = capacity;
    //创建int数组 大小为capacity 初始化所有元素为0
    m_elements = new int[capacity]{0};
}
//析构函数
ArrayList::~ArrayList() {
    if (m_elements != nullptr) {
        delete [] m_elements;
    }
    std::cout<<"~ArrayList() 析构函数" << std::endl;
}
/**
 * 清除所有元素
 */
void ArrayList::clear() {
    m_size = 0;
}
/**
 * 元素的数量
 */
int ArrayList::size() {
    return m_size;
}
/**
 * 是否为空
 */
bool ArrayList::isEmpty() {
    return m_size == 0;
}
/**
 * 是否包含某个元素
 */
bool ArrayList::contains(int element) {
    return indexOf(element) != ELEMENT_NOT_FOUND;
}
/**
 * 添加元素到尾部
 */
void ArrayList::add(int element) {
    
}

/**
 * 获取index位置的元素
 * @param index 索引
 */
int ArrayList::get(int index) {
    if (index < 0 || index >= m_size) {
        throw "Index out of bounds";
    }
    return m_elements[index];
}

/**
 * 设置index位置的元素
 * @param index 索引
 * @param element 元素
 * @return 原来的元素ֵ
 */
int ArrayList::set(int index, int element) {
    if (index < 0 || index >= m_size) {
        throw "Index out of bounds";
    }
    int old = m_elements[index];
    m_elements[index] = element;
    return old;
}

/**
 * 在index位置插入一个元素
 * @param index  索引
 * @param element 元素
 */
void ArrayList::add(int index, int element) {
    
}

/**
 * 删除index位置的元素
 * @param index 索引
 * @return 要删除的元素的值
 */
int ArrayList::remove(int index) {
    return 0;
}

/**
 * 查看元素的索引
 * @param element 元素
 * @return 返回查找结果
 */
int ArrayList::indexOf(int element) {
    for (int i = 0; i < m_size; i++) {
        if (m_elements[i] == element) return i;
    }
    return ELEMENT_NOT_FOUND;
}
