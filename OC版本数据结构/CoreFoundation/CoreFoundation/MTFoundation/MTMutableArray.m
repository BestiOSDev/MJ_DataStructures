//
//  MTMutableArray.m
//  CoreFoundation
//
//  Created by dzb on 2019/4/3.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#import "MTMutableArray.h"

@implementation MTMutableArray

- (void)addObject:(id)anObject {
	CFArrayAppendValue(_array,(__bridge const void *)(anObject));
}

- (void)insertObject:(id)anObject atIndex:(NSUInteger)index {
	CFArrayInsertValueAtIndex(_array,index, (__bridge const void *)(anObject));
}

- (void)removeObjectAtIndex:(NSUInteger)index {
	CFArrayRemoveValueAtIndex(_array, index);
}

- (void)removeLastObject {
	if (self.count == 0) { return; }
	[self removeObjectAtIndex:self.count-1];
}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject {
	if (index > self.count-1) {
		return;
	}
	CFArraySetValueAtIndex(_array, index, (__bridge const void *)(anObject));
}

- (void)addObjectsFromArray:(NSArray *)otherArray {
	for (id  obj in otherArray) {
		[self addObject:obj];
	}
}

- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2 {
	CFArrayExchangeValuesAtIndices(_array,idx1, idx2);
}

- (void)removeAllObjects {
	CFArrayRemoveAllValues(_array);
}

- (void)removeObject:(id)anObject {
	NSInteger index = [self indexOfObject:anObject];
	if (index != NSNotFound) {
		[self removeObjectAtIndex:index];
	}
}



@end
