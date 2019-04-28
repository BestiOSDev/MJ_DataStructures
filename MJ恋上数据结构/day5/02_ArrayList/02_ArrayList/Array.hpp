//
//  Array.hpp
//  02_ArrayList1
//
//  Created by dzb on 2019/4/17.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>


static int DEFAULT_CAPACITY = 10;
static int ELEMENT_NOT_FOUND = 10;


///Array 接口类 不可被直接拿来使用 定义了 Array 的一些接口
///子类才用共用基础方式 重新虚函数
template <typename E>
class Array {
	
public:
	/**
	 * 清除所有元素
	 */
	virtual void clear_with_completion(void(*for_each)(E));
	/**
	 * 元素的数量
	 */
	virtual int size();
	/**
	 * 是否为空
	 */
	virtual bool isEmpty();
	
	/**
	 * 是否包含某个元素
	 */
	virtual bool contains(E element);
	
	/**
	 * 添加元素到尾部
	 */
	virtual void add(E element);
	
	/**
	 * 获取index位置的元素
	 */
	virtual E get(int index);
	
	/**
	 * 设置index位置的元素
	 * @return 原来的元素ֵ
	 */
	virtual E set(int index, E element);
	
	/**
	 * 在index位置插入一个元素
	 */
	virtual void add(int index, E element);
	
	/**
	 * 删除index位置的元素
	 */
	virtual E remove(int index);
	/**
	 * 查看元素的索引
	 */
	virtual int indexOf(E element);
    //打印数组元素
    virtual void toString();
};

/**
 * 清除所有元素
 */
template <typename E>
void Array<E>::clear_with_completion(void(*for_each)(E)) {
	
}

/**
 * 元素的数量
 */
template <typename E>
int Array<E>::size() {
	return 0;
}

/**
 * 是否为空
 */
template <typename E>
bool Array<E>::isEmpty() {
	return true;
}


/**
 * 是否包含某个元素
 */
template <typename E>
bool Array<E>::contains(E element) {
	return false;
}

/**
 * 添加元素到尾部
 */
template <typename E>
void Array<E>::add(E element) {
	
}

/**
 * 获取index位置的元素
 */
template <typename E>
E Array<E>::get(int index) {
	return 0;
}

/**
 * 设置index位置的元素
 * @return 原来的元素ֵ
 */
template <typename E>
E Array<E>::set(int index, E element) {
	return 0;
}

/**
 * 在index位置插入一个元素
 */
template <typename E>
void Array<E>::add(int index, E element) {
	
}

/**
 * 删除index位置的元素
 */
template <typename E>
E Array<E>::remove(int index) {
    return NULL;
}
/**
 * 查看元素的索引
 */
template <typename E>
int Array<E>::indexOf(E element) {
	return 0;
}

///打印数组内容
template <typename E>
void Array<E>::toString() {
    
}


#endif /* Array_hpp */
