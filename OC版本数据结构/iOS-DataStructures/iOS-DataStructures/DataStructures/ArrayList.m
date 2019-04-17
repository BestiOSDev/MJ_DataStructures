//
//  ArrayList.m
//  ArrayList
//
//  Created by dzb on 2018/7/19.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import "ArrayList.h"

static NSInteger const defaultCapacity = 10;
typedef id _Nullable (*RFUNC)(id _Nonnull, SEL _Nonnull,...);
typedef void * AnyObject;

@interface ArrayList ()
{
@private
	AnyObject *_array;
	NSInteger _size;
	NSInteger _capacity;
}
@end

@implementation ArrayList

#pragma mark - init

- (instancetype)init
{
	self = [super init];
	if (self) {
		_size = 0;
		_capacity = defaultCapacity;
		_array = (AnyObject*)calloc(_capacity, sizeof(AnyObject));
	}
	return self;
}

+ (instancetype)array {
	return [[ArrayList alloc] initWithCapacity:defaultCapacity];
}

+ (instancetype)arrayWithCapacity:(NSUInteger)numItems {
	return [[ArrayList alloc] initWithCapacity:numItems];
}

- (instancetype)initWithCapacity:(NSUInteger)numItems {
	_capacity = numItems;
	_array = (AnyObject*)calloc(_capacity,sizeof(AnyObject));
	_size = 0;
	return self;
}

#pragma mark - 增加操作

- (void)addObject:(id)anObject {
	[self insertObject:anObject atIndex:_size];
}

- (void)insertObject:(id)anObject atIndex:(NSUInteger)index {
	if (!anObject) {
		@throw [NSException exceptionWithName:@"add object null." reason:@"object must be not null ." userInfo:nil];
		return;
	}
	///判越界
	if ((index > _size)) {
		@throw [NSException exceptionWithName:@"Array is out of bounds" reason:@"out of bounds" userInfo:nil];
		return;
	}
	if (_size == _capacity) { ///判断原来数组是否已经满了 如果满了就需要增加数组长度
		[self resize:2 * _capacity];
	}
	///交换索引位置
	if (self.count > 0 ) {
		for(NSInteger i = _size - 1 ; i >= index ; i--)
			_array[i + 1] = _array[i];
	}
	self->_array[index] = (__bridge_retained AnyObject)(anObject);
	_size++;
}

#pragma mark - 删除操作
- (void)removeAllObjects {
	AnyObject *oldArray = _array;
	NSInteger i = _size - 1;
	while (i >= 0) {
		AnyObject *obj = oldArray[i];
		CFRelease(obj);
		i--;
	}
	if (oldArray != NULL) {
		free(oldArray);
		oldArray = NULL;
	}
	_size = 0;
	_capacity = defaultCapacity;
	_array = (AnyObject*)calloc(_capacity,sizeof(AnyObject));
}

- (void)removeObjectAtIndex:(NSUInteger)index {
	///判断越界
	if ((index > _size)) {
		@throw [NSException exceptionWithName:@"Array is out of bounds" reason:@"out of bounds" userInfo:nil];
		return;
	}
	AnyObject object =(_array[index]);
	CFRelease(object);
	for(NSInteger i = index + 1 ; i < _size ; i ++)
		_array[i - 1] = _array[i];
	_size--;
	_array[_size] = NULL;
	///对数组空间缩减
	if (_size == _capacity * 0.25 && (_capacity*0.25 != 0)) {
		[self resize:_capacity/2];
	}
}

- (void)removeObject:(id)anObject {
	NSInteger index = [self indexOfObject:anObject];
	if (index == NSNotFound) return;
	[self removeObjectAtIndex:index];
}

- (void)removeLastObject {
	if ([self isEmpty]) return;
	[self removeObjectAtIndex:_size-1];
}

#pragma mark - 修改操作

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject {
	if (!anObject) {
		@throw [NSException exceptionWithName:@"add object null." reason:@"object must be not null ." userInfo:nil];
		return;
	}
	///判断越界
	if ((index > _size)) {
		@throw [NSException exceptionWithName:@"Array is out of bounds" reason:@"out of bounds" userInfo:nil];
		return;
	}
	_array[index] = (__bridge AnyObject)(anObject);
}

#pragma mark - 查询操作

- (BOOL) isEmpty {
	return (self->_size == 0);
}

- (BOOL) isFull {
	return (self->_size == self->_capacity-1);
}

- (id)objectAtIndex:(NSUInteger)index {
	if ((index > _size)) {
		@throw [NSException exceptionWithName:@"Array is out of bounds" reason:@"out of bounds" userInfo:nil];
		return nil;
	}
	if ([self isEmpty]) { return nil; }
	AnyObject obj = _array[index];
	if (obj == NULL) return nil;
	return (__bridge id)(obj);
}

- (NSUInteger)indexOfObject:(id)anObject {
	for (int i = 0; i<_size; i++) {
		id obj = (__bridge id)(_array[i]);
		if ([anObject isEqual:obj]) return i;
	}
	return NSNotFound;
}

- (BOOL)containsObject:(id)anObject {
	for (int i = 0; i<_size; i++) {
		id obj = (__bridge id)(_array[i]);
		if ([anObject isEqual:obj]) return YES;
	}
	return NO;
}

- (id)firstObject {
	if ([self isEmpty]) return nil;
	return (__bridge id _Nullable)(_array[0]);
}

- (id)lastObject {
	if ([self isEmpty]) return nil;
	return (__bridge id _Nullable)(_array[_size-1]);
}

- (NSUInteger)count {
	return _size;
}

/**
 对数组扩容
 
 @param capacity 新的容量
 */
- (void) resize:(NSInteger)capacity {
	
	_capacity = capacity;
	AnyObject *oldArray = _array;
	AnyObject *newArray = (AnyObject *)calloc(_capacity,sizeof(AnyObject));
	size_t size = sizeof(AnyObject) * self.count;
	memcpy(newArray,oldArray,size); ///对旧的数组进行值的拷贝
	_array = newArray;
	if (oldArray != NULL) {
		free(oldArray);
		oldArray = NULL;
	}

}

/**
 拷贝一个新的数组 使新数组内容 和 原来数组内容一样
 
 @return ArrayList
 */
- (ArrayList *)copyNewArray {
	AnyObject *oldArray = _array;
	ArrayList *newArray = [ArrayList arrayWithCapacity:_capacity];
	size_t size = sizeof(AnyObject) * _capacity;
	memcpy(newArray->_array,oldArray, size);
	return newArray;
}

- (void)dealloc
{
	if (_array != NULL) {
		NSInteger i = _size - 1;
		while (i >= 0) {
			AnyObject *obj = _array[i];
			if (obj != NULL)
				CFRelease(obj);
			i--;
		}
		free(_array);
	}
}

- (NSString *)description {
	NSMutableString *string = [NSMutableString stringWithFormat:@"\nArrayList %p : [ \n" ,self];
	for (int i = 0; i<_size; i++) {
		AnyObject obj = _array[i];
		[string appendFormat:@"%@",(__bridge id)obj];
		if (i<_size-1) {
			[string appendString:@" , \n"];
		}
	}
	[string appendString:@"\n]\n"];
	return string;
}

- (id)copyWithZone:(NSZone *)zone {
	return self;
}

- (id)mutableCopyWithZone:(NSZone *)zone {
	return self;
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id __unsafe_unretained _Nullable [_Nonnull])buffer count:(NSUInteger)len {
	
	NSInteger count;
	
	/* In a mutable subclass, the mutationsPtr should be set to point to a
	 * value (unsigned long) which will be changed (incremented) whenever
	 * the container is mutated (content added, removed, re-ordered).
	 * This is cached in the caller at the start and compared at each
	 * iteration.   If it changes during the iteration then
	 * objc_enumerationMutation() will be called, throwing an exception.
	 * The abstract base class implementation points to a fixed value
	 * (the enumeration state pointer should exist and be unchanged for as
	 * long as the enumeration process runs), which is fine for enumerating
	 * an immutable array.
	 */
	state->mutationsPtr = (unsigned long *)&state->mutationsPtr;
	count = MIN(len, [self count] - state->state);
	/* If a mutation has occurred then it's possible that we are being asked to
	 * get objects from after the end of the array.  Don't pass negative values
	 * to memcpy.
	 */
	if (count > 0)
	{
		IMP	imp = [self methodForSelector: @selector(objectAtIndex:)];
		int	p = (int)state->state;
		int	i;
		
		for (i = 0; i < count; i++, p++)
		{
			RFUNC funcPt =(RFUNC)imp;
			id objc = funcPt(self,@selector(objectAtIndex:),p);
			buffer[i] = objc;
		}
		state->state += count;
	}
	else
	{
		count = 0;
	}
	state->itemsPtr = buffer;
	return count;
	
}
@end
