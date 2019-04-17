//
//  MTMutableDictionary.h
//  CoreFoundation
//
//  Created by dzb on 2019/4/7.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import "MTDictionary.h"

NS_ASSUME_NONNULL_BEGIN

@interface MTMutableDictionary <KeyType,ObjectType> : MTDictionary <KeyType,ObjectType>
{
    NSMutableDictionary *dc;
}

- (void)removeObjectForKey:(KeyType)aKey;
- (void)setObject:(ObjectType)anObject forKey:(KeyType <NSCopying>)aKey;

- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray<KeyType> *)keyArray;
- (void)setDictionary:(MTDictionary<KeyType, ObjectType> *)otherDictionary;

@end

NS_ASSUME_NONNULL_END
