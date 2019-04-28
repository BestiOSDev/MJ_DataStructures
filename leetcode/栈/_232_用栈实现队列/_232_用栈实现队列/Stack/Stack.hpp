//
//  Stack.hpp
//  02-Array-Stack
//
//  Created by dzb on 2019/3/3.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

///Stakc虚基类
template <class E>
class Stack {
	
public:
    virtual int getSize() { return 0; }
    virtual bool isEmpty() { return false; }
    virtual void push(E e) { }
    virtual E pop() { return (E)(0);}
    virtual E peek() { return (E)0; }
};


#endif /* Stack_hpp */
