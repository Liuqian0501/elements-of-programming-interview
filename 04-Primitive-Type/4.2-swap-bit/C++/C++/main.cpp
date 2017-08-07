//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/6/17.
//  Copyright © 2017 qianliu. All rights reserved.
//




#include <iostream>
#include <stdio.h>
#include <assert.h>     /* assert */

#ifndef Swap_H_
#define Swap_H_
namespace Swap {
    
    // @include
    long SwapBits(long x, int i, int j) {
        //swap when ith bit and jth bit are different
        if((x & (1L << i)) != (x & (1L << j))){
            x ^= (1L << i | 1L << j);
        }
        return x;
    }
    // @exclude
    
}  // namespace Swap
#endif  // Swap_H_

#ifndef Unittest_H_
#define Unittest_H_
namespace Unittest {
    void unittest(long x, int i, int j, long y) {
        long result = Swap::SwapBits(x, i, j);
        assert(result == y);
        printf("made it");
    }
    
}
#endif 

int main(int argc, const char * argv[]) {
    // insert code here...
    Unittest::unittest(1L, 0, 1, 2L);
    return 0;
}
