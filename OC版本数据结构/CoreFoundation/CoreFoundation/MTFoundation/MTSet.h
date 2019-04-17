//
//  MTSet.h
//  CoreFoundation
//
//  Created by dzb on 2019/4/7.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MTSet <ObjectType> : NSObject
{
    CFMutableStringRef *_set;
}

+ (instancetype)set;
+ (instancetype)setWithObject:(ObjectType)object;
+ (instancetype)setWithObjects:(ObjectType)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
+ (instancetype)setWithSet:(NSSet<ObjectType> *)set;
+ (instancetype)setWithArray:(NSArray<ObjectType> *)array;

- (instancetype)initWithObjects:(ObjectType)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
- (instancetype)initWithSet:(NSSet<ObjectType> *)set;
- (instancetype)initWithArray:(NSArray<ObjectType> *)array;
@end

NS_ASSUME_NONNULL_END
