//
//  main.cpp
//  01_TheComplexity
//
//  Created by dzb on 2019/4/15.
//  Copyright © 2019年 dzb. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "TimeTool.hpp"

using namespace std;

/* 0 1 2 3 4 5
 * 0 1 1 2 3 5 8 13 ....
 */

// O(2^n)
int fib1(int n) {
	if (n <= 1) return n;
	return fib1(n - 1) + fib1(n - 2);
}

// O(n)
int fib2(int n) {
	if (n <= 1) return n;
	
	int first = 0;
	int second = 1;
	for (int i = 0; i < n - 1; i++) {
		int sum = first + second;
		first = second;
		second = sum;
	}
	return second;
}

int fib3(int n) {
	if (n <= 1) return n;
	
	int first = 0;
	int second = 1;
	while (n-- > 1) {
		second += first;
		first = second - first;
	}
	return second;
}

void test1(int n) {
	// 汇编指令
	
	// 1
	if (n > 10) {
		std::cout<<"n > 10"<<std::endl;
	} else if (n > 5) { // 2
		std::cout<<"n > 5"<<std::endl;
	} else {
		std::cout<<"n <= 5"<<std::endl;
	}
	
	// 1 + 4 + 4 + 4
	for (int i = 0; i < 4; i++) {
		cout<<"test"<<endl;
	}
	
	// 140000
	// O(1)
	// O(1)
}

void test2(int n) {
	// O(n)
	// 1 + 3n
	for (int i = 0; i < n; i++) {
		cout<<"test"<<endl;
	}
}

void test3(int n) {
	// 1 + 2n + n * (1 + 3n)
	// 1 + 2n + n + 3n^2
	// 3n^2 + 3n + 1
	// O(n^2)
	
	// O(n)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<<"test"<<endl;
		}
	}
}

void test4(int n) {
	// 1 + 2n + n * (1 + 45)
	// 1 + 2n + 46n
	// 48n + 1
	// O(n)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 15; j++) {
			cout<<"test"<<endl;
		}
	}
}

void test5(int n) {
	// 8 = 2^3
	// 16 = 2^4
	
	// 3 = log2(8)
	// 4 = log2(16)
	
	// 执行次数 = log2(n)
	// O(logn)
	while ((n = n / 2) > 0) {
		cout<<"test"<<endl;
	}
}

void test6(int n) {
	// log5(n)
	// O(logn)
	while ((n = n / 5) > 0) {
		cout<<"test"<<endl;
	}
}

void test7(int n) {
	// 1 + 2*log2(n) + log2(n) * (1 + 3n)
	
	// 1 + 3*log2(n) + 2 * nlog2(n)
	// O(nlogn)
	for (int i = 1; i < n; i = i * 2) {
		// 1 + 3n
		for (int j = 0; j < n; j++) {
			cout<<"test"<<endl;
		}
	}
}

void test10(int n) {
	// O(n)
	int a = 10;
	int b = 20;
	int c = a + b;
	//定义一个int [] 数组 初始化每个元素为0
	int *array = new int[n]{0};
	for (int i = 0; i <n; i++) {
		cout<<array[i]+c<<endl;
	}
	delete [] array;
}


int main(int argc, const char * argv[]) {
	int n = 60;
	
	TimeTool::task("fib1", n,[](int n){
		cout<<fib1(n)<<endl;
	});
	
	TimeTool::task("fib2", n,[](int n){
		cout<<fib2(n)<<endl;
	});
	
	TimeTool::task("fub3",n,[](int n){
		cout<<fib3(n)<<endl;
	});
	
	return 0;
}


