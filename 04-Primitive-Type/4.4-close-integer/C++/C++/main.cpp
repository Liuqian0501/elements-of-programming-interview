//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/6/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdexcept>      // std::invalid_argument
#include <assert.h>

#ifndef close_integer_H_
#define close_integer_H_
namespace close_ineger{
    unsigned long ClosestIntSameBitCount(unsigned long x){
        const static int totalBitNumber = 64;
        for(int i = 0; i < totalBitNumber - 1; i++){
            //int firstBit = (x >> i) & 1;
            //int secontBit = (x >> (i+1)) & 1;
            if(((x >> i) & 1) != ((x >> (i+1)) & 1)){
                x ^= (1L << i | 1L << (i+1));
                return x;
            }
        }
        
        //Throw error is all bits of x are 0 or 1;
        throw std::invalid_argument("All bits are 0 or 1s");
    }
}

namespace unitest {
    void test(unsigned long x, unsigned long y){
        long result = close_ineger::ClosestIntSameBitCount(x);
        assert(result == y);
        printf("Made it\n");
        
    }
}
#endif
int main(int argc, const char * argv[]) {
    // insert code here...

    unitest::test(1L, 2);
    unitest::test(2L, 1);
    unitest::test(1L << 11, 1L << 10);
    return 0;
}
