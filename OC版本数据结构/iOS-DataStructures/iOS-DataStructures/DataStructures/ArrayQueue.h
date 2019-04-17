//
//  ArrayQueue.h
//  ArrayList
//
//  Created by dzb on 2018/7/23.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ArrayQueue <ObjectType> : NSObject

+ (instancetype) arrayQueue;
+ (instancetype) arrayQueueWithCapacity:(NSInteger)capacity;
- (instancetype) initWithCapacity:(NSInteger)capacity;

- (void) enqueue:(ObjectType)obj; ///入队列
- (id) dequeue; ///出队列
- (void) removeAllObjects; ///移除队列里边所有元素

///firstObject
@property (nonatomic,weak) ObjectType firstObject;
///size
@property (nonatomic,assign,readonly) NSInteger size;
///isEmpty
@property (nonatomic,assign,getter=isEmpty) BOOL empty;

@end
