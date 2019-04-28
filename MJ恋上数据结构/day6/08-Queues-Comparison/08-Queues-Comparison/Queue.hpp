//
//  Queue.hpp
//  05-Array-Queue
//
//  Created by dzb on 2019/3/4.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
///MARK: Queue虚基类

template <typename E>
class Queue {
	
public:
	virtual int getSize() {
		return 0;
	}
	virtual bool isEmpty() {
		return false;
	}
	virtual void enqueue(E e) {
		
	}
	virtual E dequeue() {
		return (E)0;
	}
	virtual E getFront() {
		return (E)0;
	}
};

#endif /* Queue_hpp */
