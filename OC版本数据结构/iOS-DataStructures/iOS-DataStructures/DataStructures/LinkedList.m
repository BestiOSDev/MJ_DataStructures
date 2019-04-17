//
//  LinkedList.m
//  ArrayList
//
//  Created by dzb on 2018/8/3.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import "LinkedList.h"

typedef void* AnyObject;
typedef struct node {
	AnyObject data;
	struct node *next;
} Node;

@interface LinkedList ()

///head
@property (nonatomic,assign) Node *dummyHead;
///size
@property (nonatomic,assign) NSInteger size;

@end

@implementation LinkedList

- (instancetype)init
{
	self = [super init];
	if (self) {
		Node * dummyHead = (Node*)malloc(sizeof(Node));
		dummyHead->data = nil;
		dummyHead->next = nil;
		self.dummyHead = dummyHead;
		self.size = 0;
	}
	return self;
}

- (void)addObjectAtFirst:(id)object {
	[self addObject:object atIndex:0];
}

- (void)addObjectAtLast:(id)object {
	[self addObject:object atIndex:self.size];
}

- (void)addObject:(id)object atIndex:(NSInteger)index {
	if (index < 0 || index > self.count) {
		@throw [NSException exceptionWithName:@"LinkedList is out of bounds" reason:@"Add failed. Illegal index." userInfo:nil];
		return;
	}
	Node *prev = self.dummyHead;
	for (int i = 0; i< index; i++) {
		prev = prev->next;
	}
	Node *cur = (Node*)malloc(sizeof(Node));
	cur->data = (__bridge_retained AnyObject)object;
	cur->next = prev->next;
	prev->next = cur;
	self.size++;
}

- (id)objectAtIndex:(NSInteger)index {
	if (index < 0 || index >= self.count) {
		@throw [NSException exceptionWithName:@"LinkedList is out of bounds" reason:@"Add failed. Illegal index." userInfo:nil];
		return nil;
	}
	Node *cur = self.dummyHead->next;
	for (int i = 0; i<index; i++) {
		cur = cur->next;
	}
	return (__bridge_transfer id)cur->data;
}

- (id)firstObject {
	return [self objectAtIndex:0];
}

- (id)lastObject {
	return [self objectAtIndex:self.count-1];
}

- (void)updateObject:(id)object atIndex:(NSInteger)index {
	if (index < 0 || index >= self.count) {
		@throw [NSException exceptionWithName:@"LinkedList is out of bounds" reason:@"Add failed. Illegal index." userInfo:nil];
		return;
	}
	Node *cur = self.dummyHead->next;
	for (int i = 0; i<index; i++) {
		cur = cur->next;
	}
	CFRelease(cur->data);
	cur->data = (__bridge_retained AnyObject)object;
}

- (BOOL)containObject:(id)object {
	Node *cur = self.dummyHead->next;
	while (cur != NULL) {
		id data = (__bridge_transfer id)cur->data;
		if ([data isEqual:object])
			return YES;
		cur = cur->next;
	}
	return NO;
}


- (id) removeObjectAtIndex:(NSInteger)index {
	if (index < 0 || index >= self.count) {
		@throw [NSException exceptionWithName:@"LinkedList is out of bounds" reason:@"Add failed. Illegal index." userInfo:nil];
		return nil;
	}
	Node *prev = self.dummyHead;
	for (int i = 0; i<index; i++) {
		prev = prev->next;
	}
	Node *deleteNode = prev->next;
	prev->next = deleteNode->next;
	id object = (__bridge_transfer id)deleteNode->data;
	free(deleteNode);
	deleteNode = NULL;
	self.size--;
	return object;
}

- (id) removeFirstObject {
	return [self removeObjectAtIndex:0];
}

- (id) removeLastObject {
	return [self removeObjectAtIndex:self.count-1];
}

- (void) removeAllObjects {
	while (self.count != 0) {
		[self removeFirstObject];
	}
}

- (NSInteger)count {
	return self.size;
}

- (NSString *)description {
	
	NSMutableString *string = [NSMutableString stringWithFormat:@"\nLinkedList %p : [ \n" ,self];
	Node *cur = self.dummyHead->next;
	while (cur != nil) {
		[string appendFormat:@"%@ -> \n",cur->data];
		cur = cur->next;
	}
	[string appendString:@"NULL\n"];
	[string appendString:@"]\n"];
	
	return string;
}

- (BOOL)isEmpty {
	return self.count == 0;
}

- (void)dealloc
{
	[self removeAllObjects];
}

@end
