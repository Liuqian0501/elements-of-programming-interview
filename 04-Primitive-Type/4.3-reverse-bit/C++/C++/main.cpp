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
#include <array>
using std::array;

#ifndef Reverse_H_
#define Reverse_H_
namespace Reverse {
    // @include
    long SwapBits(long& x, int i, int j) {
        //swap when ith bit and jth bit are different
        if((x & (1L << i)) != (x & (1L << j))){
            x ^= (1L << i | 1L << j);
            //std::cout << j << std::endl;
        }
        return x;
    }
    // @exclude
    
    long reverse(long x) {
        long result = x;
        for(int i = 0; i < 32; i++){
            SwapBits(result, i, 63-i);
        }
        return result;
    }
}
#endif

#ifndef Reverse2_H_
#define Reverse2_H_
namespace Reverse2 {
    long reverse_16(long x) {
        long result = x;
        for(int i = 0; i < 8; i++){
            Reverse::SwapBits(result, i, 15-i);
        }
        return result;
    }
    
    array<long, 1 << 16> BuildTable(){
        array<long, 1 << 16> table;
        for(int i = 0; i < (1 << 16); i++){
            table[i] = reverse_16(i);
        }
        return table;
    }
    
    static array<long, 1 << 16> precomputed_reverse = BuildTable();
    
    long reverse(long x) {
        const int bitNum = 16;
        const int bitMask = 0xFFFF;
        return precomputed_reverse[x&bitMask] << (3*bitNum) |
        precomputed_reverse[(x >> bitNum) & bitMask] << (2*bitNum) |
        precomputed_reverse[(x >> 2*bitNum) & bitMask] << (bitNum) |
        precomputed_reverse[(x >> 3*bitNum) & bitMask];
        
    }
    
}  // namespace Reverse2
#endif //Reverse2


#ifndef Unittest_H_
#define Unittest_H_
namespace Unittest {
    void unittest(long x, long y) {
        long result = Reverse::reverse(x);
        long result2 = Reverse2::reverse(x);
        //std::cout<< result2 << " " << y << std::endl;
        assert(result == y);
        assert(result2 == y);
        printf("made it\n");
    }
    
}
#endif
int main(int argc, const char * argv[]) {
    // insert code here...
    Unittest::unittest(1L, 1L<<63);
    Unittest::unittest(1L<<10, 1L<<53);
    Unittest::unittest(1L<<10 | 1L << 20, 1L<<53 | 1L << 43);
    
    return 0;
}
