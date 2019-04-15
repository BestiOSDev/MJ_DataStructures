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



class ArrayList {
private:
    int m_size;
    int *m_elements;
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
    bool contains(int element);
    
    /**
     * 添加元素到尾部
     */
    void add(int element);
    
    /**
     * 获取index位置的元素
     */
    int get(int index);
    
    /**
     * 设置index位置的元素
     * @return 原来的元素ֵ
     */
    int set(int index, int element);
  
    /**
     * 在index位置插入一个元素
     */
    void add(int index, int element);
    
    /**
     * 删除index位置的元素
     */
    int remove(int index);
    /**
     * 查看元素的索引
     */
    int indexOf(int element);
    
};

#endif /* ArrayList_hpp */
