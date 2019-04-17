//
//  ArrayList.h
//  ArrayList
//
//  Created by dzb on 2018/7/19.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 自实现一个动态数组
 */
@interface ArrayList < ObjectType > : NSObject <NSCopying,NSMutableCopying,NSFastEnumeration>

NS_ASSUME_NONNULL_BEGIN

+ (instancetype)array; //默认容量是10 会动态的扩容和缩减数组长度
+ (instancetype)arrayWithCapacity:(NSUInteger)numItems;
- (instancetype)initWithCapacity:(NSUInteger)numItems;

- (ObjectType)objectAtIndex:(NSUInteger)index;
- (NSUInteger)indexOfObject:(ObjectType)anObject;
- (BOOL)containsObject:(ObjectType)anObject;

- (void)addObject:(ObjectType)anObject;
- (void)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(ObjectType)anObject;

- (void)removeAllObjects;
- (void)removeLastObject;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeObject:(ObjectType)anObject;

@property (readonly) NSUInteger count;
@property (nullable, nonatomic, readonly) ObjectType firstObject;
@property (nullable, nonatomic, readonly) ObjectType lastObject;

NS_ASSUME_NONNULL_END

@end
