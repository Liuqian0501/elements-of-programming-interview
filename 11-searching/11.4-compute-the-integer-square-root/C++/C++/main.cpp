//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/15/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

int Sqrt(int A){
    int result = -1;
    if(A < 0) return result;
    int left = 0, right = A;
    while(left < right){
        int mid = left + (right - left)/2;
        int midsqr = mid*mid;
        if(midsqr < A){
            left = mid + 1;
        }else if(midsqr > A){
            right = mid - 1;
        }else{
            return mid;
        }
    }
    //if left*left > A, return left - 1;
    return left*left > A ? left - 1: left;
}


int main(int argc, const char * argv[]) {
    // T1;
    int a = 40001;
    int result = Sqrt(a);
    assert(result == 200);
    return 0;
}
