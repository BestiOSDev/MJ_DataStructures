//
//  TimeTool.cpp
//  01_TheComplexity
//
//  Created by dzb on 2019/4/15.
//  Copyright © 2019年 dzb. All rights reserved.
//

#include "TimeTool.hpp"
#include <iostream>


void TimeTool::task(char *title,int n,Func func) {
    if (func == nullptr) {
        return;
    }
    std::cout<<title<<std::endl;
    std::cout << "开始："<<std::endl;
    clock_t startTime = clock();
    (*func)(n);
    clock_t endTime = clock();
    std::cout<< "结束" << std::endl;
    std::cout << title << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<std::endl;
}
