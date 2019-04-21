//
//  main.cpp
//  LinkedList
//
//  Created by dzb on 2019/4/21.
//  Copyright © 2019年 dzb. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
using namespace std;


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
    
    int e = list->remove(0);
    cout << e << endl;
    delete list;
    
}

int main(int argc, const char * argv[]) {
    
 
    return 0;
}
