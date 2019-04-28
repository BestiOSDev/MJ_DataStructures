//
//  main.m
//  02-Array-Stack
//
//  Created by dzb on 2019/3/3.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#include <iostream>
#include "ArrayStack.hpp"
#import <Foundation/Foundation.h>

using namespace std;

int main() {
    {
        ArrayStack<int> stack(10);
        stack.push(10);
        stack.push(100);
        stack.toString();
    }
	getchar();
	return 0;
}
