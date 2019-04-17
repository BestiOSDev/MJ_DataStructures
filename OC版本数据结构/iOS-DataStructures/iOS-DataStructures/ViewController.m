//
//  ViewController.m
//  ArrayList
//
//  Created by dzb on 2018/7/19.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import "ViewController.h"
#import "ArrayList.h"
#import "Person.h"
#import "ArrayQueue.h"
#import "ArrayStack.h"
#import "LoopQueue.h"
#import "LinkedListStack.h"
#import "LinkedList.h"

@interface ViewController ()
{
	ArrayList <Person *> *_array;
	ArrayQueue <Person *> *_queue;
	LinkedList * _linkedList;
	NSTimer *_timer;
	NSMutableArray *_timeArray;
}
@end

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	
//	[self testArray];
	
	LoopQueue *queue = [LoopQueue loopQueueWithCapacity:10];
	[queue enqueue:@"dzb"];
	
	
//	LinkedList <Person *> *linked = [[LinkedList alloc] init];
//
//	Person *p1 = [Person new];
//	Person *p2 = [Person new];
//	Person *p3 = [Person new];
//	NSLog(@"p1 = %p p2 = %p p3 = %p",p1,p2,p3);
//
//	[linked addObjectAtFirst:p1];
//	[linked addObjectAtFirst:p2];
//	[linked addObjectAtFirst:p3];
//
//	NSLog(@"%@",linked);
//
//	[linked removeFirstObject];
//	[linked removeFirstObject];
//	[linked removeFirstObject];
//
//	NSLog(@"%@",linked);

}


/**
 编译器匹配 {} [] ()
 
 @param string 字符串
 @return 匹配字符串是否正常关闭
 */
- (BOOL) isValid:(NSString *)string {
	
	ArrayStack <NSString *> *stack = [ArrayStack stackWithCapacity:10];
	NSString *tmp;
	for (int i = 0; i<string.length; i++) {
		tmp = [string substringWithRange:NSMakeRange(i, 1)];
		if ([tmp isEqualToString:@"{"] || [tmp isEqualToString:@"["] || [tmp isEqualToString:@"("]) {
			[stack push:tmp];
		} else {
			if (stack.isEmpty) return NO;
			NSString *popStr = [stack pop];
			if ([tmp isEqualToString:@")"] && ![popStr isEqualToString:@"("]) {
				return NO;
			} else if ([tmp isEqualToString:@"]"] && ![popStr isEqualToString:@"["]) {
				return NO;
			} else if ([tmp isEqualToString:@"}"] && ![popStr isEqualToString:@"{"]) {
				return NO;
			}
		}
	}
	
	return stack.isEmpty;
}

- (void) testArray {
	
	NSTimer *timer = [NSTimer timerWithTimeInterval:3.0f target:self selector:@selector(test) userInfo:nil repeats:YES];
	[[NSRunLoop currentRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
	_timer = timer;
	_timeArray = [NSMutableArray array];
	
}

- (void) testStack {
	ArrayStack <NSNumber *> *stack = [ArrayStack stackWithCapacity:10];
	for (int i = 0; i<10; i++) {
		[stack push:@(i)];
	}
	NSLog(@"%ld",(long)stack.size);
	NSLog(@"%ld",(long)stack.isEmpty);
	NSLog(@"%@",stack);
	
	id obj = [stack pop];
	NSLog(@"%@",obj);
	
	NSLog(@"%@",stack);
	
	[stack removeAllObjects];
	
	NSLog(@"%@",stack);
	
}

- (void) testQueue {
	
	CFAbsoluteTime startTime =CFAbsoluteTimeGetCurrent();
	int count = 100;
	Person *p = [Person new];
	ArrayQueue <Person *> *queue = [ArrayQueue arrayQueue];
	for (int i = 0; i<count; i++) {
		[queue enqueue:p];
	}
	for (int i = 0; i<count; i++) {
		[queue dequeue];
	}
	CFAbsoluteTime linkTime = (CFAbsoluteTimeGetCurrent() - startTime);
	NSLog(@"%s Linked in %f s",__func__ ,linkTime);
	
}

- (void) testLoopQueue {
	
	
	
}

- (void) test {
	static int count = 0;
	if (count > 9) {
		[_timer invalidate];
		_timer = nil;
		NSLog(@"time is %@",[_timeArray valueForKeyPath:@"@avg.self"]);
		return;
	}
	
	dispatch_async(dispatch_get_global_queue(0, 0), ^{
		CFAbsoluteTime startTime = CFAbsoluteTimeGetCurrent();
		int number = 100000;
		Person *p = [Person new];
		LinkedListStack <Person *> *linked = [LinkedListStack new];
		for (int i = 0; i<number; i++) {
			[linked push:p];
		}
		CFAbsoluteTime linkTime = (CFAbsoluteTimeGetCurrent() - startTime);
		CFTimeInterval duration = linkTime * 1000.0f;
		NSLog(@"Linked in %f ms",duration);
		[self->_timeArray addObject:@(duration)];
		count++;
	});
	
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	_array = nil;
}

@end
