//
//  main.m
//  LRUCache
//
//  Created by dzb on 2019/3/18.
//  Copyright © 2019年 大兵布莱恩特. All rights reserved.
//

#import "Person.h"
#include "LRUCache.h"
//#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        LRUCache *cache = [LRUCache shareCache];
        cache.countLimit = 10;
      
        for (int i = 0; i<100; i++) {
            NSString *key = [NSString stringWithFormat:@"key_%d",i];
            Person *p = [[Person alloc] initWithName:key];
            [cache setObject:p forKey:key];
        }
        
        for (int i = 90; i<100; i++) {
            NSString *key = [NSString stringWithFormat:@"key_%d",i];
            Person *p = [cache objectForKey:key];
            NSLog(@"%@",p.name);
        }
        
        [cache removeAllObjects];

    }
    
    while (1) {
        
        usleep(1000.0f);
    }
    
    
    return 0;
}
