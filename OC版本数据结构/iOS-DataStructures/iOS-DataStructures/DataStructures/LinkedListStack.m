//
//  LinkedListStack.m
//  iOS-DataStructures
//
//  Created by dzb on 2018/8/7.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import "LinkedList.h"
#import "LinkedListStack.h"

@interface LinkedListStack ()
{
	LinkedList *_linkedList;
}
@end

@implementation LinkedListStack

- (instancetype)init
{
	self = [super init];
	if (self) {
		_linkedList = [[LinkedList alloc] init];
	}
	return self;
}

+ (instancetype)linkedListStack {
	return [[LinkedListStack alloc] init];
}

- (void)push:(id)obj {
	[_linkedList addObjectAtFirst:obj];
}

- (id)pop {
	return [_linkedList removeFirstObject];
}

- (void)removeAllObjects {
	[_linkedList removeAllObjects];
}

- (NSInteger)size {
	return _linkedList.count;
}

- (BOOL)isEmpty {
	return _linkedList.count == 0;
}

- (NSString *)description {
	
	NSMutableString *res = [NSMutableString string];
	[res appendFormat:@"ArrayStack: %p \n",self];
	[res appendString:@" [ "];
	for (int i = 0; i<_linkedList.count; i++) {
		id object = [_linkedList objectAtIndex:i];
		[res appendFormat:@"%@",object];
		if (i != _linkedList.count - 1) {
			[res appendString:@" , "];
		}
	}
	[res appendString:@" ] top "];
	return res;
}

- (void)dealloc
{
	
}

@end
