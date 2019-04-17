//
//  TestArray.m
//  iOS-DataStructuresTests
//
//  Created by dzb on 2018/8/5.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ArrayList.h"
#import "Person.h"

@interface TestArray : XCTestCase
{
	NSMutableArray *_timeArray;
}
@end

@implementation TestArray

- (void)setUp {
    [super setUp];
	
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {


}

- (void) testArray {
	
	ArrayList <NSString *> *array = [ArrayList arrayWithCapacity:10];
	[array addObject:@"A"];
	[array addObject:@"B"];
	[array addObject:@"C"];
	[array addObject:@"D"];
	[array addObject:@"E"];
	[array addObject:@"F"];
	[array addObject:@"G"];
	
	NSLog(@"array = %@",array);
	
	[array insertObject:@"666" atIndex:5];

	NSLog(@"array = %@",array);
	
	[array replaceObjectAtIndex:1 withObject:@"123"];
	
	NSLog(@"array = %@",array);

	NSLog(@"firstObject  = %@",[array firstObject]);
	NSLog(@"lastObject  = %@",[array lastObject]);
	NSLog(@"array[3] = %@",[array objectAtIndex:3]);
	
	[array removeLastObject];
	
	NSLog(@"array = %@",array);

	[array removeObjectAtIndex:0];
	NSLog(@"array = %@",array);

	NSLog(@"array Count = %lu",(unsigned long)[array count]);
	
	///快速便利
	for (NSString *str in array) {
		NSLog(@"%@",str);
	}
	
}


/**
 测试用例 对比 NSMutableArray 比 ArrayList 性能提升 2.42倍
 ArrayList 16.90701246261597ms
 NSMutableArray 6.979000568389893ms
 */
- (void) testArrayListAndNSArray {
	_timeArray = [NSMutableArray array];
	
	///10万次对比 NSMutableArray 和 ArrayList
	int number = 100000;
	Person *p = [Person new];
	for (int i = 0; i<10; i++) {
		CFAbsoluteTime startTime = CFAbsoluteTimeGetCurrent();
		ArrayList <Person *> *array = [ArrayList arrayWithCapacity:number];
		for (int i = 0; i<number; i++) {
			[array addObject:p];
		}
		[array removeAllObjects];
		CFAbsoluteTime linkTime = (CFAbsoluteTimeGetCurrent() - startTime);
		CFTimeInterval duration = linkTime * 1000.0f;
		//		NSLog(@"Linked in %f ms",duration);
		[self->_timeArray addObject:@(duration)];
		[NSThread sleepForTimeInterval:0.3f];
	}
	
	NSLog(@"ArrayList time is %@",[_timeArray valueForKeyPath:@"@avg.self"]);

	NSLog(@"********************************");
	
	[_timeArray removeAllObjects];
	
	for (int i = 0; i<10; i++) {
		CFAbsoluteTime startTime = CFAbsoluteTimeGetCurrent();
		NSMutableArray <Person *> *array = [NSMutableArray arrayWithCapacity:number];
		for (int i = 0; i<number; i++) {
			[array addObject:p];
		}
		[array removeAllObjects];
		CFAbsoluteTime linkTime = (CFAbsoluteTimeGetCurrent() - startTime);
		CFTimeInterval duration = linkTime * 1000.0f;
		[self->_timeArray addObject:@(duration)];
		[NSThread sleepForTimeInterval:0.3f];
	}

	NSLog(@"NSMutableArray time is %@",[_timeArray valueForKeyPath:@"@avg.self"]);

	
	
}


- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
