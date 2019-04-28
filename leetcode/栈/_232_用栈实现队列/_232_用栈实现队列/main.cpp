//
//  main.cpp
//  _232_用栈实现队列
//
//  Created by dzb on 2019/4/28.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#include <iostream>
#include "Stack/ArrayStack.hpp"

int main(int argc, const char * argv[]) {
	
	ArrayStack<int> *stack = new ArrayStack<int>();
	stack->push(11);
	stack->push(22);
	stack->push(33);
	stack->push(44);

	while (!stack->isEmpty()) {
		int a = stack->pop();
		std::cout << a << std::endl;
	}
	
	stack->toString();
	
	return 0;
}
