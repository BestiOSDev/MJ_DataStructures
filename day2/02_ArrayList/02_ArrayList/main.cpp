//
//  main.cpp
//  02_ArrayList
//
//  Created by dzb on 2019/4/15.
//  Copyright © 2019年 dzb. All rights reserved.
//

#include <iostream>
#include "Array.hpp"
#include "ArrayList.hpp"

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
    ArrayList<Person *> *persons = new ArrayList<Person *>();
    persons->add(new Person(10,"Jack"));
    persons->add(new Person(15,"Rose"));
    persons->add(new Person(12,"James"));
    persons->clear();
    persons->add(new Person(22,"abc"));
    persons->toString();
    
    ArrayList<NSNumber<int>*> *ints = new ArrayList<NSNumber<int>*>();
    ints->add(new NSNumber<int>(10));
    ints->add(new NSNumber<int>(10));
    ints->add(new NSNumber<int>(22));
    ints->add(new NSNumber<int>(33));

    ints->toString();
    
    ints->clear();
    
    delete ints;
    
}

void test2() {
    
    ArrayList<Person *> *persons = new ArrayList<Person *>();
    persons->add(new Person(10,"Jack"));
    
    persons->add(nullptr);
    persons->add(new Person(15,"Rose"));
    persons->add(nullptr);
    persons->add(new Person(12,"James"));
    persons->add(nullptr);
    
    persons->toString();
    
    delete persons;
    
}

int main(int argc, const char * argv[]) {

    test1();
    test2();
    
    return 0;
}

