//
//  MTDictionary.h
//  CoreFoundation
//
//  Created by dzb on 2019/4/7.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
@class MTArray;

NS_ASSUME_NONNULL_BEGIN

@interface MTDictionary <KeyType,ObjectType> : NSObject
{
    @protected
    CFMutableDictionaryRef _dict;
}


+ (instancetype)dictionary;
+ (instancetype)dictionaryWithObject:(ObjectType)object forKey:(KeyType <NSCopying>)key;

+ (instancetype)dictionaryWithObjectsAndKeys:(id)firstObject, ...;

+ (instancetype)dictionaryWithObjects:(MTArray *)objects forKeys:(MTArray *)keys;

- (instancetype)initWithObjectsAndKeys:(id)firstObject, ... NS_REQUIRES_NIL_TERMINATION;
- (instancetype)initWithObjects:(MTArray *)objects forKeys:(MTArray *)keys;


@property (readonly) NSUInteger count;
- (nullable ObjectType)objectForKey:(KeyType)aKey;
@property (readonly, copy) MTArray *allKeys;
@property (readonly, copy) MTArray *allValues;
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(KeyType key, ObjectType obj, BOOL *stop))block;


@end

NS_ASSUME_NONNULL_END
