//
//  Person.m
//  LRUCache
//
//  Created by dzb on 2019/3/18.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import "Person.h"

@implementation Person

-(id)initWithName:(NSString *)aName {
    if (self = [super init]) {
        self.name = aName;
    }
    return self;
}

- (void)dealloc
{
    NSLog(@"Person dealloc");
}

@end
