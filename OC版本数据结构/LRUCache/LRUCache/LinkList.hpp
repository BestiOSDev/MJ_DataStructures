//
//  LinkList.hpp
//  LinkList
//
//  Created by dzb on 2019/3/17.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#ifndef LinkList_hpp
#define LinkList_hpp

#include <stdio.h>
#include <iostream>

#pragma mark - Interface

template <typename T>
class LinkList {
  
public:
    ///链表节点
    class LinkNode {
    public:
        T _data; ///数据域
        const char * _key; ///查找数据的key
        double _time; ///数据操作时间
        LinkNode *_pre; /// 当前节点上一个节点
        LinkNode *_next; ///当前节点下一个节点
        LinkNode();
        ~LinkNode();
        LinkNode(T data,LinkNode *pre,LinkNode *next,const char *key,double time);
    };
    LinkList();
    ~LinkList();
    ///获取链表内容大小
    int size();
    ///头插法插入数据到链表头部位置
    LinkNode * insert(T object);
    ///查找元素
    LinkNode * find(T object);
    ///获取尾结点
    LinkNode * lastObject();
    ///获取头结点
    LinkNode * firstObject();
    /// 移动结点到链表头部
    void bring_node_to_head(LinkNode *pFind);
    ///遍历所有元素
    void for_each_elements(void(*for_each)(T));
    ///按元素值进行删除
    T remove_by(T obj);
    ///通过节点删除元素
    T remove_by(LinkNode *pFind);
    /// 移除尾结点
    T remove_tail_node();
    ///销毁链表的元素
    void clear_by_completion(void(*for_each)(T));
private:
    ///链表长度
    int _size;
    ///头节点
    LinkNode *_header;
    ///插入节点到指定位置
    void insert(LinkNode *pFind);
};

#endif /* LinkList_hpp */

#pragma mark - LinkNode Implementation

template<class T>
LinkList<T>::LinkNode::LinkNode() : LinkNode(NULL,NULL,NULL,"",0) {
    
}

template<class T>
LinkList<T>::LinkNode::LinkNode(T data,LinkNode *pre,LinkNode *next,const char *key,double time) {
    this->_data = data;
    this->_pre = pre;
    this->_next = next;
    this->_key = key;
    this->_time = time;
}

template<class T>
LinkList<T>::LinkNode::~LinkNode() {
//    std::cout << "~LinkNode()" << std::endl;
}

#pragma mark - LinkList
template<class T>
LinkList<T>::LinkList() {
    _header = new LinkNode();
    _header->_next = _header->_pre = _header;
    _size = 0;
}

template<class T>
LinkList<T>::~LinkList() {
//    std::cout << "LinkList()" << std::endl;
}

/**
 头插法插入数据到链表头部位置
 */
template<class T>
typename LinkList<T>::LinkNode * LinkList<T>::insert(T object) {
    LinkNode *cur = new LinkNode();
    cur->_data = object;
    insert(cur);
    _size ++;
    return cur;
}

///插入节点到指定位置
template<class T>
void LinkList<T>::insert(LinkNode *pFind) {
    pFind->_next = _header->_next;
    _header->_next = pFind;
    pFind->_pre = _header;
    pFind->_next->_pre = pFind;
}

///遍历链表元素
template<class T>
void LinkList<T>::for_each_elements(void(*for_each)(T)) {
    LinkNode *sh = _header->_next;
    while (sh != _header) {
        T &obj = sh->_data;
        (*for_each)(obj);
        sh = sh->_next;
    }
}

/// 获取链表内容长度
template<class T>
int LinkList<T>::size() {
    return _size;
}

///通过节点删除元素
template<class T>
T LinkList<T>::remove_by(LinkNode *pFind) {
    if (pFind == NULL)
        return NULL;
    LinkNode *pre = pFind->_pre;
    pre->_next = pFind->_next;
    pFind->_next->_pre = pre;
    T data = pFind->_data;
    delete pFind;
    _size--;
    return data;
}

///按元素值进行删除
template<class T>
T LinkList<T>::remove_by(T obj) {
    
    if (find(obj) == NULL) return;
    
    LinkNode *deleteNode = _header->_next;
    LinkNode *pre = NULL;
    for (int i = 0; i<_size; i++) {
        if (deleteNode->_data == obj) {
            break;
        }
        pre = deleteNode;
        deleteNode = deleteNode->_next;
    }
    
    pre->_next = deleteNode->_next;
    
    T &data = deleteNode->_data;
    delete deleteNode;
    _size--;
    
    return data;
}

///查找元素
template<class T>
typename LinkList<T>::LinkNode * LinkList<T>::find(T object) {
    if (object == NULL)
        return NULL;
    
    LinkNode *clock = _header->_next, *unclock = _header->_pre;
    while (unclock != clock->_pre) {
        if (clock->_data == object) {
            return clock;
        }
        if (unclock->_data == object) {
            return unclock;
        }
        if (clock == unclock) {
            break;
        }
        clock = clock->_next;
        unclock = unclock->_pre;
    }
    return NULL;
}

///获取尾结点
template<class T>
typename LinkList<T>::LinkNode * LinkList<T>::lastObject() {
    LinkNode *tail = _header->_pre;
    if (tail == _header) return NULL;
    return tail;
}
///获取头结点
template<class T>
typename LinkList<T>::LinkNode * LinkList<T>::firstObject() {
    LinkNode *first = _header->_next;
    if (first == _header) {
        return NULL;
    }
    return first;
}

///销毁链表
template<class T>
void LinkList<T>::clear_by_completion(void(*for_each)(T)) {
    if (_size == 0) return;
    
    _header->_pre->_next = NULL;
    LinkNode *cur;
    while (_header != NULL) {
        cur = _header;
        _header = _header->_next;
        T data = cur->_data;
        if (data != NULL) {
            (*for_each)(data);
        }
        delete cur;
    }
    
}

/// 移动结点到链表头部
template<class T>
void LinkList<T>::bring_node_to_head(LinkNode *pFind) {
    LinkNode *pre = pFind->_pre;
    if (pre == _header) return;
    
    /// 断开pFind所有连接节点
    pre->_next = pFind->_next;
    pFind->_next->_pre = pre;
    
    ///将 pFind插入到头节点位置
    insert(pFind);
    
}

/// 移除尾结点
template<class T>
T LinkList<T>::remove_tail_node() {
    
    LinkNode *tail = _header->_pre;
    if (tail == _header) return NULL;
    T data = remove_by(tail);
    
    return data;
}
