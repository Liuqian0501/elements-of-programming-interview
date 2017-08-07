//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/6/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <assert.h>

#ifndef Multiply_H_
#define Multiply_H_
namespace multiply {
    unsigned Add(unsigned x, unsigned y){
        //bit by bit
        unsigned carry_in = 0, k = 1, sum = 0, tempx = x, tempy = y;

        while(tempx || tempy){
            unsigned kx = x & k, ky = y & k;
            sum = sum | (kx ^ ky ^ carry_in);
            unsigned carry_out = (kx & ky) | (ky & carry_in) | (kx & carry_in);
            carry_in = carry_out << 1,k <<= 1, tempy >>= 1, tempx >>= 1;
        }
        return sum;
    }
    unsigned Multiply(unsigned x, unsigned y){
        //   y
        // X x
        //-----
        // x*y
        unsigned result = 0;
        
        while(x){
            if(x & 1){
                result = Add(result, y);
            }
            x >>= 1;
            y <<= 1;
        }
        return result;
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest {
    void Test(unsigned x, unsigned y, unsigned expected){
        unsigned result = multiply::Multiply(x, y);
        assert(result == expected);
        printf("Made it \n");
    }
}
#endif
int main(int argc, const char * argv[]) {
    // insert code here...
    unitest::Test(7, 8, 56);
    return 0;
}
