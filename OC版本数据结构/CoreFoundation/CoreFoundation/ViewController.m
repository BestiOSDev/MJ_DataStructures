//
//  ViewController.m
//  CoreFoundation
//
//  Created by dzb on 2019/4/3.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#import "ViewController.h"
#import "MTArray.h"
#import "MTMutableDictionary.h"
#import "MTDictionary.h"
#import "MTMutableArray.h"
#import <CoreFoundation/CoreFoundation.h>

@interface ViewController ()
{
	CFArrayRef _array;
}
@end

@implementation ViewController

void callBack(const void *value, void *context) {
	NSLog(@"%@",value);
}

- (void)viewDidLoad {
	[super viewDidLoad];
    NSSet *s = [NSSet set];
//  [self testArray];
    [self performSelector:@selector(testDictionary) withObject:nil afterDelay:3.0f];
}

- (void) testArray {
 
    CFAbsoluteTime startTime =CFAbsoluteTimeGetCurrent();
    NSMutableArray *array1 = [NSMutableArray array];
//    MTMutableArray *array2 = [MTMutableArray array];
    for (int i = 0; i<1000000; i++) {
        [array1 addObject:@(i)];
//        [array2 addObject:@(i)];
    }
    CFAbsoluteTime linkTime = (CFAbsoluteTimeGetCurrent() - startTime);
    NSLog(@"Linked in %f ms", linkTime *1000.0);

}

- (void) testDictionary {
    //    NSDictionary *dict1 = [NSDictionary dictionaryWithObjectsAndKeys:@100,@"age",@200, nil];
 
    
    CFAbsoluteTime startTime =CFAbsoluteTimeGetCurrent();
//    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    MTMutableDictionary *dict1 = [MTMutableDictionary dictionary];

    //    MTMutableArray *array2 = [MTMutableArray array];
    for (int i = 0; i<1000000; i++) {
        NSString *key = [NSString stringWithFormat:@"%d",i];
        NSNumber *value = @(i);
        [dict1 setObject:value forKey:key];
//        [dict setObject:value forKey:key];
        //        [array2 addObject:@(i)];
    }
    CFAbsoluteTime linkTime = (CFAbsoluteTimeGetCurrent() - startTime);
    NSLog(@"Linked in %f ms", linkTime *1000.0);
    
    //    MTDictionary *dict2 = [MTDictionary dictionary];
//    NSLog(@"%@",dict2);
//
//    MTDictionary *dict3 = [MTDictionary dictionaryWithObject:@"dzb" forKey:@"name"];
//    NSLog(@"%@",dict3);
//
//    MTDictionary *dict4 = [MTDictionary dictionaryWithObjects:[MTArray arrayWithObjects:@"dzb",@20, nil] forKeys:[MTArray arrayWithObjects:@"name",@"age", nil]];
//    NSLog(@"%@",dict4);
//
//    MTDictionary *dict5 = [[MTDictionary alloc] initWithObjectsAndKeys:@"dzb",@"name" ,nil];
//    NSLog(@"%@",dict5);
//
//    MTDictionary *dict6 = [[MTDictionary alloc] initWithObjects:[MTArray arrayWithObjects:@"dzb",@20, nil] forKeys:[MTArray arrayWithObjects:@"name",@"age", nil]];
//    NSLog(@"%@",dict6);
    
//    NSNumber *age = [dict1 objectForKey:@"score"];
//    NSLog(@"age = %@",age);
//
//    [dict1 enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
//        NSLog(@"%@  %@ %p",key,obj,stop);
//    }];
//
//    NSLog(@"%@",dict1.allValues);
//    NSLog(@"%@",dict1.allKeys);
//
//    [dict1 setObject:@33 forKey:@"age"];
//    NSLog(@"dict1 = %@",dict1);
//
//    [dict1 removeAllObjects];
//
//    NSLog(@"dict1 = %@",dict1);

}


@end
