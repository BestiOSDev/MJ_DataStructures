//
//  ArrayQueue.m
//  ArrayList
//
//  Created by dzb on 2018/7/23.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import "ArrayList.h"
#import "ArrayQueue.h"

@interface ArrayQueue ()
{
	ArrayList *_array;
}

@end


@implementation ArrayQueue

+ (instancetype)arrayQueue {
	return [[ArrayQueue alloc] initWithCapacity:10];
}

+ (instancetype)arrayQueueWithCapacity:(NSInteger)capacity {
	return [[ArrayQueue alloc] initWithCapacity:capacity];
}

- (instancetype)initWithCapacity:(NSInteger)numItems {
	if (self = [super init]) {
		_array = [ArrayList arrayWithCapacity:numItems];
	}
	return self;
}

- (void)enqueue:(id)obj {
	[_array addObject:obj];
}

- (id)dequeue {
	[_array removeObjectAtIndex:0];
	return nil;
}

- (id)firstObject {
	return [_array firstObject];
}

- (void)removeAllObjects {
	[_array removeAllObjects];
}

- (NSInteger)size {
	return _array.count;
}
- (BOOL)isEmpty {
	return _array.count == 0;
}

- (NSString *)description {
	
	NSMutableString *res = [NSMutableString string];
	[res appendFormat:@"ArrayQueue: %p \n",self];
	[res appendString:@"front [ "];
	for (int i = 0; i<_array.count; i++) {
		id object = [_array objectAtIndex:i];
		[res appendFormat:@"%@",object];
		if (i != _array.count - 1) {
			[res appendString:@" , "];
		}
	}
	[res appendString:@" ] tail "];
	return res;
}

- (void)dealloc
{
	
}

@end
