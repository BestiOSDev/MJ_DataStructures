//
//  MTMutableDictionary.m
//  CoreFoundation
//
//  Created by dzb on 2019/4/7.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import "MTArray.h"
#import "MTMutableDictionary.h"

@implementation MTMutableDictionary

- (void)removeAllObjects {
    if (self.count == 0) return;
    MTArray *keys = self.allKeys;
    for (NSString *Key in keys) {
        [self removeObjectForKey:Key];
    }
}

- (void)removeObjectForKey:(id)aKey {
    if (!aKey) return;
    CFDictionaryRemoveValue(_dict, (__bridge const void *)(aKey));
}

- (void)setObject:(id)anObject forKey:(id<NSCopying>)aKey {
    if (!anObject || !aKey) {
        return;
    }
    CFDictionarySetValue(_dict, (__bridge const void *)(aKey), (__bridge const void *)(anObject));
}

- (void)removeObjectsForKeys:(NSArray *)keyArray {
    for (NSString *key in keyArray) {
        [self removeObjectForKey:key];
    }
}

- (void)setDictionary:(MTDictionary *)otherDictionary {
    [otherDictionary enumerateKeysAndObjectsUsingBlock:^(NSString *key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        [self setObject:obj forKey:key];
    }];
}

@end
