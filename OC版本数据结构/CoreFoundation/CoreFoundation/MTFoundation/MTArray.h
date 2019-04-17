//
//  MTArray.h
//  CoreFoundation
//
//  Created by dzb on 2019/4/3.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MTArray <__covariant ObjectType> : NSObject <NSFastEnumeration>
{
@protected
	CFMutableArrayRef _array;
}

+ (instancetype)array;
+ (instancetype)arrayWithObject:(ObjectType)anObject;
+ (instancetype)arrayWithObjects:(ObjectType)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
+ (instancetype)arrayWithArray:(NSArray<ObjectType> *)array;

- (instancetype)initWithObjects:(ObjectType)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
- (instancetype)initWithArray:(NSArray<ObjectType> *)array;

- (BOOL)containsObject:(ObjectType)anObject;
- (ObjectType)objectAtIndex:(NSUInteger)index;
- (NSInteger) indexOfObject:(ObjectType)anObject;
@property (readonly) NSUInteger count;
@property (nullable, nonatomic, readonly) ObjectType firstObject;
@property (nullable, nonatomic, readonly) ObjectType lastObject;

- (MTArray<ObjectType> *)subarrayWithRange:(NSRange)range;

@end

NS_ASSUME_NONNULL_END
