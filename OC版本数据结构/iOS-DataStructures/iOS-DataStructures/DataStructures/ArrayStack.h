//
//  ArrayStack.h
//  ArrayList
//
//  Created by dzb on 2018/7/23.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ArrayStack <ObjectType> : NSObject

+ (instancetype) arrayStack; ///默认容量10
+ (instancetype) stackWithCapacity:(NSInteger)numItems;
- (instancetype) initWithCapacity:(NSInteger)numItems;

- (void) push:(ObjectType)obj; ///入栈一个元素
- (ObjectType) pop; ///出栈一个元素
- (void) removeAllObjects; ///移除栈里边所有元素

///size
@property (nonatomic,assign,readonly) NSInteger size;
///isEmpty
@property (nonatomic,assign,getter=isEmpty) BOOL empty;

@end

NS_ASSUME_NONNULL_END
