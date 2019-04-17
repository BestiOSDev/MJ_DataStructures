//
//  TimeTool.hpp
//  01_TheComplexity
//
//  Created by dzb on 2019/4/15.
//  Copyright © 2019年 dzb. All rights reserved.
//

#ifndef TimeTool_hpp
#define TimeTool_hpp

#include <stdio.h>

typedef void(*Func)(int n);

class TimeTool {
    
public:
    //C++类的静态方法
    static void task(char *title,int n,Func func);
};

#endif /* TimeTool_hpp */
