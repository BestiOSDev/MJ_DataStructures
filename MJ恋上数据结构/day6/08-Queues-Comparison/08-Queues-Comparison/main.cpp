//
//  main.cpp
//  05-Array-Queue
//
//  Created by dzb on 2019/3/4.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#include <iostream>
#include "Queue.hpp"
#include "ArrayQueue.hpp"
#include "LoopQueue.hpp"
#include <stdlib.h>
#include <time.h>

static double testQueue(Queue<int> &q, int opCount){
	
	clock_t startTime = clock();
	int random = rand();
	for(int i = 0 ; i < opCount ; i ++) {
		q.enqueue(random);
		random++;
	}
	for(int i = 0 ; i < opCount ; i ++) {
		q.dequeue();
	}
	
	clock_t endTime = clock();
	
	return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
	
	int opCount = 100000;
	ArrayQueue<int> arrayQueue;
	double time1 = testQueue(arrayQueue, opCount);
	std::cout<<"ArrayQueue, time: " << time1 << " s" << endl;
	
	LoopQueue<int> loopQueue;
	double time2 = testQueue(loopQueue, opCount);
	std::cout<<"LoopQueue, time: " << time2 << " s" << endl;
	
	return 0;
}
