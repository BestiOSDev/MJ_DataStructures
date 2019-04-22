//
//  main.cpp
//  LinkedList
//
//  Created by dzb on 2019/4/21.
//  Copyright © 2019年 dzb. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include "SingleLinkedList.hpp"
#include "SingleLinkedList2.hpp"

using namespace std;

class Person {
public:
	int age;
	string name;
	Person(string name,int age) {
		this->name = name;
		this->age = age;
	}
	~Person() {
		cout<<"~Person()"<<endl;
	}
	/// 重载 == 操作符 类似 equals 方法
	bool operator ==(Person *p) {
		if (p->name == this->name && p->age == this->age) {
			return true;
		}
		return false;
	}
};


/**
 双向循环链表
 */
void test1() {
    
    // 建议 请勿使用堆空间 指向栈空间内存 除非在函数作用域结束后 不再使用链表
    // 往里边内部添加元素 尽量使用指针类型
    
    LinkedList<int> *list = new LinkedList<int>();
    list->add(10);
    list->add(20);
    list->add(30);
    list->for_each_elements([](int element){
        cout << element << endl;
    });
    //    int a = list->get(0);
    //    cout << a << endl;
    //在这个拉姆达表达式内部可以做内存释放工作 只有new出来的内存 才需要释放内存
    list->clear_with_completion([](int element){
        
    });
    list->add(100);
    list->add(200);
    list->add(350);
    list->toString();
	
	int a = list->get(2);
	cout << a << endl;
	
	bool ret = list->contains(33);
	cout << ret << endl;
	
	list->set(0,44);
	list->toString();

    int e = list->remove(0);
    cout << e << endl;
    delete list;
    
}


/**
 双向循环链表 测试 2
 */
void test4() {
	LinkedList<int> *list = new LinkedList<int>();
	for (int i = 0; i<100; i++) {
		list->add(i);
	}
	list->toString();
	
	list->clear_with_completion(NULL);
	list->toString();

}

/**
 单向链表不带虚拟节点
 */
void test2() {
	
	Person *p1 = new Person(string("dzb"),20);
	Person *p2 = new Person(string("james"),24);
	Person *p3 = new Person(string("kobe"),24);
	SingleLinkedList<Person *> *list = new SingleLinkedList<Person *>();
	list->add(p1);
	list->add(p2);
	list->add(p3);
	list->for_each_elements([](Person *person){
		cout << person->name << " age " << person->age << endl;
	});
	//在这个拉姆达表达式内部可以做内存释放工作 只有new出来的内存 才需要释放内存
	list->clear_with_completion([](Person *person){
		if (person != NULL) {
			delete person;
		}
	});
	
	list->add(p1);
	list->add(p2);
	list->add(p3);
	list->toString();
	
	///自定义判断添加规则 重载 == 操作符
	int index = list->indexOf(p3);
	cout << "p3 index is  " << index << endl;

	Person *e = list->remove(0);
	cout << e->name << endl;
	delete list;
	
}

///单向链表带虚拟头节点
void test3() {
	
	// 建议 请勿使用堆空间 指向栈空间内存 除非在函数作用域结束后 不再使用链表
	// 往里边内部添加元素 尽量使用指针类型
	
	SingleLinkedList2<int> *list = new SingleLinkedList2<int>();
	list->add(10);
	list->add(20);
	list->add(30);
	//获取
	int a = list->get(2);
	cout << "a = " << a << endl;
	list->for_each_elements([](int element){
		cout << element << endl;
	});
	//    int a = list->get(0);
	//    cout << a << endl;
	//在这个拉姆达表达式内部可以做内存释放工作 只有new出来的内存 才需要释放内存
	list->clear_with_completion([](int element){
		
	});
	list->add(100);
	list->add(200);
	list->add(350);
	list->toString();
	
	
	int e = list->remove(0);
	cout << e << endl;
	delete list;
	
}

int main(int argc, const char * argv[]) {
//
//	test1();
////	test2();
//	test3();
	test4();
	
    return 0;
}
