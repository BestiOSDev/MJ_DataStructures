//
//  TestStack.m
//  iOS-DataStructuresTests
//
//  Created by dzb on 2018/8/7.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "LinkedListStack.h"
#import "ArrayStack.h"
#import "Person.h"

@interface TestStack : XCTestCase
{
	NSMutableArray *_timeArray;
}
@end

@implementation TestStack

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

- (void) testStack {

	
	_timeArray = [NSMutableArray array];
	
	///10万次对比 NSMutableArray 和 ArrayList
	int number = 100000;
	Person *p = [Person new];
	for (int i = 0; i<10; i++) {
		CFAbsoluteTime startTime = CFAbsoluteTimeGetCurrent();
		LinkedListStack <Person *> *linkStack = [LinkedListStack linkedListStack];
		for (int i = 0; i<number; i++) {
			[linkStack push:p];
		}
		CFAbsoluteTime linkTime = (CFAbsoluteTimeGetCurrent() - startTime);
		CFTimeInterval duration = linkTime * 1000.0f;
		[self->_timeArray addObject:@(duration)];
		[NSThread sleepForTimeInterval:0.3f];
	}
	
	NSLog(@"LinkedListStack time is %@",[_timeArray valueForKeyPath:@"@avg.self"]);
	
	NSLog(@"********************************");
	
	[_timeArray removeAllObjects];
	
	for (int i = 0; i<10; i++) {
		CFAbsoluteTime startTime = CFAbsoluteTimeGetCurrent();
		ArrayStack <Person *> *arrayStack = [ArrayStack arrayStack];
		for (int i = 0; i<number; i++) {
			[arrayStack push:p];
		}
		CFAbsoluteTime linkTime = (CFAbsoluteTimeGetCurrent() - startTime);
		CFTimeInterval duration = linkTime * 1000.0f;
		[self->_timeArray addObject:@(duration)];
		[NSThread sleepForTimeInterval:0.3f];
	}
	
	NSLog(@"ArrayStack time is %@",[_timeArray valueForKeyPath:@"@avg.self"]);

	
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
