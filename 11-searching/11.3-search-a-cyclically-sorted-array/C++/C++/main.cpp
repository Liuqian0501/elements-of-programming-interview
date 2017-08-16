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

int FindSmallest(vector<int> A){
    int left = 0, right = A.size() - 1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(A[mid] < A[right]){
            right = mid;
        }else if(A[mid] > right){
            left = mid + 1;
        }else{
            break;
        }
    }
    return left;
}
int main(int argc, const char * argv[]) {
    //T1
    vector<int> A = {4,5,6,1,2,3};
    int result = FindSmallest(A);
    assert(result == 3);
    return 0;
}
