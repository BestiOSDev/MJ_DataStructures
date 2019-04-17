//
//  Person.h
//  LRUCache
//
//  Created by dzb on 2019/3/18.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject
@property (nonatomic,strong) NSString *name;

-(id)initWithName:(NSString *)aName;

@end

NS_ASSUME_NONNULL_END
