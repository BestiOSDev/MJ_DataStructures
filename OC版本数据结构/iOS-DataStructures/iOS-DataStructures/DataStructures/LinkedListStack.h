//
//  LinkedListStack.h
//  iOS-DataStructures
//
//  Created by dzb on 2018/8/7.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LinkedListStack <ObjectType> : NSObject

+ (instancetype) linkedListStack;

- (void) push:(ObjectType)obj; ///入栈一个元素
- (ObjectType) pop; ///出栈一个元素
- (void) removeAllObjects; ///移除栈里边所有元素
///size
@property (nonatomic,assign,readonly) NSInteger size;
///isEmpty
@property (nonatomic,assign,getter=isEmpty) BOOL empty;

@end
