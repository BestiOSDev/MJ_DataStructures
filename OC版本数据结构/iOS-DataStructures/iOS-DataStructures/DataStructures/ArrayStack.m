//
//  ArrayStack.m
//  ArrayList
//
//  Created by dzb on 2018/7/23.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import "ArrayList.h"
#import "ArrayStack.h"

@interface ArrayStack ()
{
	ArrayList *_array;
}
@end

@implementation ArrayStack

- (instancetype)initWithCapacity:(NSInteger)numItems {
	if (self = [super init]) {
		_array = [ArrayList arrayWithCapacity:numItems];
	}
	return self;
}

+ (instancetype)stackWithCapacity:(NSInteger)numItems {
	return [[ArrayStack alloc] initWithCapacity:numItems];
}

+ (instancetype)arrayStack {
	return [[ArrayStack alloc] initWithCapacity:10];
}

- (void)push:(id)obj {
	[_array addObject:obj];
}

- (id)pop {
	id object = [_array lastObject];
	[_array removeObject:object];
	return object;
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
	[res appendFormat:@"ArrayStack: %p \n",self];
	[res appendString:@" [ "];
	for (int i = 0; i<_array.count; i++) {
		id object = [_array objectAtIndex:i];
		[res appendFormat:@"%@",object];
		if (i != _array.count - 1) {
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
