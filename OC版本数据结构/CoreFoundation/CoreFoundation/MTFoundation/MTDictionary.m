//
//  MTDictionary.m
//  CoreFoundation
//
//  Created by dzb on 2019/4/7.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import "MTArray.h"
#import "MTDictionary.h"
#import "MTMutableArray.h"

@implementation MTDictionary

static inline CFMutableDictionaryRef _createDictionary() {
    CFMutableDictionaryRef dict = CFDictionaryCreateMutable(kCFAllocatorDefault,0, NULL, NULL);
    return dict;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _dict = _createDictionary();
    }
    return self;
}
+ (instancetype)dictionaryWithObject:(id)object forKey:(id<NSCopying>)key {
    return [self dictionaryWithObjectsAndKeys:object,key];
}

+ (instancetype)dictionary {
    return [[self alloc] init];
}

+ (instancetype)dictionaryWithObjects:(MTArray *)objects forKeys:(MTArray<NSCopying> *)keys {
    
    if (objects.count != keys.count) {
        @throw [NSException exceptionWithName:@"objects.cout != keys.count" reason:nil userInfo:nil];
    }
    NSInteger foreachCount = objects.count;
    MTDictionary *dictionary = [self dictionary];
    for (NSInteger i = 0; i<foreachCount; i++) {
        NSString *key = [keys objectAtIndex:i];
        id value = [objects objectAtIndex:i];
        if (![key isKindOfClass:[NSString class]]) {
            @throw [NSException exceptionWithName:@"key type must NSString *" reason:nil userInfo:nil];
        }
        CFDictionarySetValue(dictionary->_dict, (__bridge const void *)(key), (__bridge const void *)(value));
    }
    
    return dictionary;
}

+ (instancetype)dictionaryWithObjectsAndKeys:(id)firstObject, ... {
    MTDictionary *dictionary = [self dictionary];
    MTMutableArray *objects = [MTMutableArray array];
    va_list ap;
    va_start(ap, firstObject);
    id obj = firstObject;
    while (obj != nil) {
        [objects addObject:obj];
        obj = va_arg(ap, id);
    }
    va_end(ap);
    
    NSInteger argCount = objects.count;
    if (argCount == 0) return nil;
    if (argCount % 2 != 0) {
        [objects removeAllObjects];
        @throw [NSException exceptionWithName:@"key不能为空" reason:@"key must be not null" userInfo:nil];
    }
    _dictionaryWithObjectsAndKeys(dictionary,objects);
    return dictionary;
}

static inline MTDictionary *_dictionaryWithObjectsAndKeys(MTDictionary *self,MTArray *objects) {
    
    //键值对数量
    CFIndex forEachCount = objects.count/2;
    for (NSInteger i = 0; i<forEachCount; i++) {
        MTArray *subArray = [objects subarrayWithRange:NSMakeRange(i, 2)];
        for (int j = 0; j<2; j++) {
            NSString *key = [subArray lastObject];
            id value = [subArray firstObject];
            if (![key isKindOfClass:[NSString class]]) {
                @throw [NSException exceptionWithName:@"key type must NSString *" reason:nil userInfo:nil];
            }
            CFDictionarySetValue(self->_dict, (__bridge const void *)(key), (__bridge const void *)(value));
        }
    }
    
    return self;
}

- (instancetype)initWithObjectsAndKeys:(id)firstObject, ... {
    
    if (self = [super init]) {
        _dict = _createDictionary();
        MTMutableArray *objects = [MTMutableArray array];
        va_list ap;
        va_start(ap, firstObject);
        id obj = firstObject;
        while (obj != nil) {
            [objects addObject:obj];
            obj = va_arg(ap, id);
        }
        va_end(ap);
        
        NSInteger argCount = objects.count;
        if (argCount == 0) return nil;
        if (argCount % 2 != 0) {
            [objects removeAllObjects];
            @throw [NSException exceptionWithName:@"key不能为空" reason:@"key must be not null" userInfo:nil];
        }
        _dictionaryWithObjectsAndKeys(self,objects);
    }
    
    return self;
    
}

- (instancetype)initWithObjects:(MTArray *)objects forKeys:(MTArray *)keys {
    if (objects.count != keys.count) {
        @throw [NSException exceptionWithName:@"objects.cout != keys.count" reason:nil userInfo:nil];
    }
    if (self = [super init]) {
        _dict = _createDictionary();
        NSInteger foreachCount = objects.count;
        for (NSInteger i = 0; i<foreachCount; i++) {
            NSString *key = [keys objectAtIndex:i];
            id value = [objects objectAtIndex:i];
            if (![key isKindOfClass:[NSString class]]) {
                @throw [NSException exceptionWithName:@"key type must NSString *" reason:nil userInfo:nil];
            }
            CFDictionarySetValue(self->_dict, (__bridge const void *)(key), (__bridge const void *)(value));
        }
    }
    return self;
}

- (id)objectForKey:(id)aKey {
    if (!aKey) {
        return nil;
    }
    id obj = (__bridge id)CFDictionaryGetValue(_dict,(__bridge const void *)(aKey));
    return obj;
}

- (NSUInteger)count {
    return CFDictionaryGetCount(_dict);
}

- (MTArray *)allKeys {
    NSInteger dictCount = self.count;
    const void **keys = malloc(sizeof(void*)*dictCount);
    CFDictionaryGetKeysAndValues(_dict,keys,NULL);
    CFMutableArrayRef newArr = CFArrayCreateMutable(kCFAllocatorDefault,0, &kCFTypeArrayCallBacks);
    for (int i = 0; i<dictCount;i++) {
        const void *obj = keys[i];
        CFArrayAppendValue(newArr,obj);
    }
    MTArray *array = [MTArray arrayWithArray:(__bridge NSArray * _Nonnull)(newArr)];
    CFRelease(newArr);
    free(keys);
    return array;
}

- (MTArray *)allValues {
    NSInteger dictCount = self.count;
    const void **values = malloc(sizeof(void*)*dictCount);
    CFDictionaryGetKeysAndValues(_dict,NULL,values);
    CFMutableArrayRef newArr = CFArrayCreateMutable(kCFAllocatorDefault,0, &kCFTypeArrayCallBacks);
    for (int i = 0; i<dictCount;i++) {
        const void *obj = values[i];
        CFArrayAppendValue(newArr,obj);
    }
    MTArray *array = [MTArray arrayWithArray:(__bridge NSArray * _Nonnull)(newArr)];
    CFRelease(newArr);
    free(values);
    return array;
}

- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(NSString *key, id obj, BOOL *stop))block {

    NSInteger dictCount = self.count;
    const void **keys = malloc(sizeof(void*)*dictCount);
    const void **values = malloc(sizeof(void*)*dictCount);
    CFDictionaryGetKeysAndValues(_dict,keys, values);
    BOOL stop = NO;
    for (int i = 0; i<dictCount; i++) {
        if (stop) {
            return;
        }
        id key = (__bridge id)(keys[i]);
        id value = (__bridge id)(values[i]);
        if (block) {
            block(value,key,&stop);
        }
    }
    free(keys);
    free(values);
}


- (NSString *)description
{
    if (_dict != NULL) {
        return [NSString stringWithFormat:@"%@",_dict];
    } else {
        return @"{ }";
    }
}

- (void)dealloc
{
    if (_dict != NULL) {
        CFRelease(_dict);
        _dict = NULL;
    }
}

@end

