//
//  MTArray.m
//  CoreFoundation
//
//  Created by dzb on 2019/4/3.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#import "MTArray.h"
#import <CoreFoundation/CoreFoundation.h>
typedef id _Nullable (*RFUNC)(id _Nonnull, SEL _Nonnull,...);

@interface MTArray ()

@end

@implementation MTArray


+ (instancetype)array {
	return [[self alloc] init];
}

+ (instancetype)arrayWithObject:(id)anObject {
	return [[self array] initWithObjects:anObject, nil];
}

+(instancetype)arrayWithObjects:(id)firstObj, ... {
	
	MTArray *arr = [self array];
	va_list ap;
	va_start(ap, firstObj);
	
	id obj = firstObj;
	while (obj != nil) {
		CFArrayAppendValue(arr->_array,(__bridge const void *)(obj));
		obj = va_arg(ap, id);
	}
	va_end(ap);
	return arr;
}

+ (instancetype)arrayWithArray:(NSArray *)array {
	return [[MTArray alloc] initWithArray:array];
}

- (instancetype)init {
	if (self = [super init]) {
		_array = CFArrayCreateMutable(kCFAllocatorDefault,0, &kCFTypeArrayCallBacks);
	}
	return self;
}

- (instancetype)initWithObjects:(id)firstObj, ... {
	if (self = [super init]) {
		_array = CFArrayCreateMutable(kCFAllocatorDefault,0, &kCFTypeArrayCallBacks);
		va_list ap;
		va_start(ap, firstObj);
		id obj = firstObj;
		while (obj != nil) {
			CFArrayAppendValue(_array,(__bridge const void *)(obj));
			obj = va_arg(ap, id);
		}
		va_end(ap);
	}
	return self;
}

- (instancetype)initWithArray:(NSArray *)array {
	if (self = [super init]) {
		_array = CFArrayCreateMutable(kCFAllocatorDefault,0, &kCFTypeArrayCallBacks);
		for (id obj in array) {
			CFArrayAppendValue(_array,(__bridge const void *)(obj));
		}
	}
	return self;
}

- (BOOL)containsObject:(id)anObject {
	return CFArrayContainsValue(_array,CFRangeMake(0,self.count), (__bridge const void *)(anObject));
}

- (id)objectAtIndex:(NSUInteger)index {
	return (__bridge id)CFArrayGetValueAtIndex(_array,index);
}

- (NSUInteger)count {
	return CFArrayGetCount(_array);
}

- (id)firstObject {
	if (self.count == 0) {
		return nil;
	}
	return [self objectAtIndex:0];
}

- (id)lastObject {
	if (self.count == 0) {
		return nil;
	}
	return [self objectAtIndex:self.count-1];
}

- (NSInteger)indexOfObject:(id)anObject {
	CFIndex index =  CFArrayGetFirstIndexOfValue(_array,CFRangeMake(0, self.count), (__bridge const void *)(anObject));
	if (index != kCFNotFound) {
		return index;
	} else {
		return NSNotFound;
	}
}

- (NSString *)description {
	return [NSString stringWithFormat:@"%@",_array];
}

- (MTArray *)subarrayWithRange:(NSRange)range {
    if (range.location < 0 || range.location > self.count-1) {
        return nil;
    }
    if (range.location + range.length > self.count) {
        return nil;
    }
    const void **values = malloc(sizeof(void*)*range.length);
    CFArrayGetValues(_array,CFRangeMake(range.location, range.length), values);
    CFMutableArrayRef newArr = CFArrayCreateMutable(kCFAllocatorDefault,0, &kCFTypeArrayCallBacks);
   
    for (int i = 0; i<range.length;i++) {
        const void *obj = values[i];
        CFArrayAppendValue(newArr,obj);
    }
    
    MTArray *array = [MTArray arrayWithArray:(__bridge NSArray * _Nonnull)(newArr)];
    CFRelease(newArr);
    free(values);

    return array;
}

- (void)dealloc {
	if (_array != NULL) {
		CFRelease(_array);
		_array = NULL;
	}
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
