//
//  main.m
//  iOS-DataStructures
//
//  Created by dzb on 2018/8/5.
//  Copyright © 2018 大兵布莱恩特. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import <iostream>

class Car {
	
private:
	
	void copy(const char *name = NULL) {
		if (name == NULL) return;
		size_t len = strlen(name) + 1;
		_name = new char[len]{};
		strcpy(_name,name);
	}
	
public:
	int _price;
	char *_name;
	Car(int price = 0,const char *name = NULL) :_price(price) {
		copy(name);
	}
	Car(const Car &car) : _price(car._price)  {
		copy(car._name);
	}
	void display() {
		std::cout << "price is " << this->_price << " name is " <<this->_name << std::endl;
	}
	~Car() {
		if (_name != NULL) {
			delete[] _name;
			_name = NULL;
		}
	}
};



int main(int argc, char * argv[]) {
	@autoreleasepool {

		char *name = new char[7]{'b','r','y','a','n','t','\0'};
		Car car = Car(100,name);
		car.display();
		
		Car car2 = Car(car);
		car2.display();
		
		car._name = (char *)"hellow";
		car.display();
		car2.display();

		delete[] name;
		
//		Car c1 = Car(100);
//		Car c2 = Car(c1);
//		c2.display();
//
//		BuleCar blueCar = BuleCar(10,100,30);
//		BuleCar c3 = BuleCar(blueCar);
		
	    return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
	}
}
