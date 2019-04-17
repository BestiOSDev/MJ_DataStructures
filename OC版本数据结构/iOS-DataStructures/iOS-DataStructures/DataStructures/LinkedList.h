//
//  LinkedList.h
//  ArrayList
//
//  Created by dzb on 2018/8/3.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LinkedList <ObjectType> : NSObject

- (void) addObjectAtFirst:(ObjectType)object;

- (void) addObjectAtLast:(ObjectType)object;

- (void) addObject:(ObjectType)object atIndex:(NSInteger)index;

- (void) updateObject:(ObjectType)object atIndex:(NSInteger)index;

- (BOOL) containObject:(ObjectType)object;

- (ObjectType) objectAtIndex:(NSInteger)index;

- (ObjectType) removeObjectAtIndex:(NSInteger)index;

- (ObjectType) removeFirstObject;

- (ObjectType) removeLastObject;

- (void) removeAllObjects;

///count
@property (nonatomic,assign) NSInteger count;
///empty
@property (nonatomic,assign,getter=isEmpty,readonly) BOOL empty;
///firstObject
@property (nonatomic,strong,readonly) ObjectType firstObject;
///lastObject
@property (nonatomic,strong,readonly) ObjectType lastObject;

@end
