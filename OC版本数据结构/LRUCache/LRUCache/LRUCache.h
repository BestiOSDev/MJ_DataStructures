//
//  LRUCache.h
//  LRUCache
//
//  Created by dzb on 2019/3/18.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LRUCacheDelegate;

@interface LRUCache : NSObject

@property (nonatomic,strong,class) LRUCache *shareCache;
/**
 是否包含key
 */
- (BOOL)containsObjectForKey:(id)key;

/**
 根据键取对应值
 */
- (nullable id)objectForKey:(id)key;

/**
 通过键值来存储数据
 */
- (void)setObject:(nullable id)object forKey:(id)key;

/**
 删除缓存中指定键的值。
 
 key标识要删除的值的键。如果为nil，则此方法无效。
 */
- (void)removeObjectForKey:(id)key;

/**
 Empties the cache immediately.
 */
- (void)removeAllObjects;

/** The number of objects in the cache (read-only) */
@property (readonly) NSUInteger totalCount;

#pragma mark - Limit

/**
 default is 10 最大缓存10个对象
 */
@property (nonatomic,assign) NSUInteger countLimit;

/**
 间隔多少秒检查缓存情况 默认5秒间隔
 */
@property NSTimeInterval autoTrimInterval;

/**
 委托对象
 */
@property (nonatomic,weak) id<LRUCacheDelegate>delegate;

/**
 收到内存警告时 是否清理缓存
 */
@property (nonatomic,assign) BOOL shouldRemoveAllObjectsOnMemoryWarning;

@end

NS_ASSUME_NONNULL_END


@protocol LRUCacheDelegate <NSObject>

/**
 每次被淘汰的缓存 就会调用这个方法

 @param lru 缓存类
 @param obj 将要被淘汰的缓存对象
 */
- (void) lurcache:(LRUCache *_Nullable)lru willEvictObject:(id _Nullable )obj;

@end
