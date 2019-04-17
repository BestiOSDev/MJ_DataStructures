//
//  MTMutableArray.h
//  CoreFoundation
//
//  Created by dzb on 2019/4/3.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#import "MTArray.h"

NS_ASSUME_NONNULL_BEGIN

@interface MTMutableArray <ObjectType >: MTArray <ObjectType>

- (void)addObject:(ObjectType)anObject;
- (void)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(ObjectType)anObject;

- (void)addObjectsFromArray:(NSArray<ObjectType> *)otherArray;
- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)removeAllObjects;
- (void)removeObject:(ObjectType)anObject;

@end

NS_ASSUME_NONNULL_END
