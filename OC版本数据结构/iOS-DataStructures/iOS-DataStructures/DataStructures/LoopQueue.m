//
//  LoopQueue.m
//  ArrayList
//
//  Created by dzb on 2018/7/24.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import "LoopQueue.h"

static NSInteger const defaultCapacity = 10;
typedef void * AnyObject;

@interface LoopQueue ()
{
@private
	AnyObject *_array;
	NSInteger _front , _tail;
	NSInteger _size;
}

///capacity
@property (nonatomic,assign) NSInteger capacity;

@end

@implementation LoopQueue

- (instancetype)initWithCapacity:(NSInteger)capacity {
	if (self = [super init]) {
		_capacity = capacity + 1;
		size_t size = sizeof(AnyObject) * _capacity;
		_array = calloc(_capacity, size);
		_front = 0;
		_size = 0;
		_tail = 0;
	}
	return self;
}

+ (instancetype)loopQueue {
	return [[LoopQueue alloc] initWithCapacity:defaultCapacity];
}

+ (instancetype)loopQueueWithCapacity:(NSInteger)capacity {
	return [[LoopQueue alloc] initWithCapacity:capacity];
}


- (id)dequeue {
	if (self.isEmpty) {
		@throw [NSException exceptionWithName:@"queue empty" reason:@"Cannot dequeue from an empty queue." userInfo:nil];
		return nil;
	}
	id object = (__bridge_transfer id)(_array[_front]);
	_array[_front] = NULL;
	_front = (_front + 1) % (_size);
	_size--;
	if (_size == self.size * 0.25 && self.size * 0.5 != 0) {
		[self resize:self.size * 0.5];
	}
	return object;
}

- (void)enqueue:(id)obj {
	if (!obj) {
		@throw [NSException exceptionWithName:@"Object empty" reason:@"Object cannot a null object" userInfo:nil];
		return;
	}
	if ((_tail + 1) % self.capacity == _front ) {
		[self resize:self.capacity * 2];
	}
	_array[_tail] = (__bridge_retained AnyObject)obj;
	_tail = (_tail + 1) % self.capacity;
	_size ++;
}

- (void)removeAllObjects {
	
}

/**
 对数组扩容
 
 @param capacity 新的容量
 */
- (void) resize:(NSInteger)capacity {
	
	_capacity = capacity + 1;
	AnyObject *oldArray = _array;
	AnyObject *newArray = calloc(_capacity,sizeof(AnyObject));
	size_t size = sizeof(AnyObject) * self.size;
	memcpy(newArray,oldArray,size); ///对旧的数组进行值的拷贝
	_array = newArray;
	_front = 0;
	_tail = self.size;
	if (oldArray != NULL) {
		free(oldArray);
		oldArray = NULL;
	}
	
}

- (NSInteger)size {
	return _size;
}

- (BOOL)isEmpty {
	return (_front == _tail);
}

- (id)firstObject {
	if (self.isEmpty) {
		@throw [NSException exceptionWithName:@"queue empty" reason:@"Cannot dequeue from an empty queue." userInfo:nil];
		return nil;
	}
	AnyObject obj = _array[_front];
	return (__bridge id)obj;
}


- (NSString *)description {
	NSMutableString *res = [NSMutableString string];
	[res appendFormat:@"ArrayQueue: %p \n",self];
	[res appendString:@"front [ "];
	for (NSInteger i = 0; i <self.size;i++) {
		id object = (__bridge id)(_array[i]);
		if (!object) continue;
		[res appendFormat:@"%@",object];
		if (i < self.size - 1) {
			[res appendString:@" , "];
			continue;
		}
	}
	[res appendString:@" ] tail "];
	return res;
}

- (void)dealloc
{
	if (_array != NULL) {
		NSInteger i = self.capacity - 1;
		while (i >= 0) {
			AnyObject *obj = _array[i];
			if (obj != NULL)
				CFRelease(obj);
			i--;
		}
		free(_array);
	}
}

@end
