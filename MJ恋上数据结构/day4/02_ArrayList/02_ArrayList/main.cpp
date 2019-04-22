//
//  main.cpp
//  02_ArrayList1
//
//  Created by dzb on 2019/4/15.
//  Copyright © 2019年 dzb. All rights reserved.
//

#include <iostream>
#include "Array.hpp"
#include "ArrayList1.hpp"
#include "ArrayList2.hpp"

using namespace std;

//Person类
class Person {
 private:
    int m_age;
    char *m_name;
    
 public:
    Person(int age,char *name) : m_age(age),m_name(name) {
        
    }
    ~Person() {
        cout << "~Person()" << endl;
    }
    void toString();
};

//基本类型包装类
template <typename T>
class NSNumber {
    private:
    T _data;
    public:
    NSNumber(T data) : _data(data) {
        
    }
    ~NSNumber() {
        cout << "~NSNumber()" << endl;
    }
    int intValue() {
        return (int)_data;
    }
    double doubleValue() {
        return (double)_data;
    }
    bool boolValue() {
        return (bool)_data;
    }
    
};


void test1() {
    // int -> Integer
    
    // 所有的类，最终都继承java.lang.Object
    
    // new是向堆空间申请内存
    ArrayList1<Person *> *persons = new ArrayList1<Person *>();
    persons->add(new Person(10,"Jack"));
    persons->add(new Person(15,"Rose"));
    persons->add(new Person(12,"James"));
	persons->clear_with_completion([](Person *p){
		delete p;
	});
    persons->add(new Person(22,"abc"));
    persons->toString();
    
    ArrayList1<NSNumber<int>*> *ints = new ArrayList1<NSNumber<int>*>();
    ints->add(new NSNumber<int>(10));
    ints->add(new NSNumber<int>(10));
    ints->add(new NSNumber<int>(22));
    ints->add(new NSNumber<int>(33));

    ints->toString();
    
	ints->clear_with_completion([](NSNumber<int> *number){
		delete number;
	});

    delete ints;
    
}

void test2() {
    
    ArrayList1<Person *> *persons = new ArrayList1<Person *>();
    persons->add(new Person(10,"Jack"));
    
    persons->add(nullptr);
    persons->add(new Person(15,"Rose"));
    persons->add(nullptr);
    persons->add(new Person(12,"James"));
    persons->add(nullptr);
    
    persons->toString();
    
    delete persons;
    
}

void test3() {
	
	ArrayList2<int> *list2 = new ArrayList2<int>();
	for (int i = 0; i<100; i++) {
		list2->add(i);
	}
	
	for (int i = 0; i<100; i++) {
		int ret = list2->remove(0);
		cout << ret << endl;
	}
	
	delete list2;
	
}

int main(int argc, const char * argv[]) {
//
//    test1();
//    test2();
//
	test3();
	
    return 0;
}

