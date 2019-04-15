//
//  main.cpp
//  02_ArrayList
//
//  Created by dzb on 2019/4/15.
//  Copyright © 2019年 dzb. All rights reserved.
//

#include <iostream>
#include "ArrayList.hpp"


int main(int argc, const char * argv[]) {
    int array[] = {11,22,33};
    ArrayList *list = new ArrayList();
    list->clear();
    
    // 1
    // size++;
    list->add(99);
    
    // 2
    // size++
    list->add(88);
    
    // list.get(2);
    // list.set(2, element)
    
    delete list;
    return 0;
}
