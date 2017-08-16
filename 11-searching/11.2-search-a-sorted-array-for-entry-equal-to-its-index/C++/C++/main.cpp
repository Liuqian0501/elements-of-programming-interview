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


int SearchIndex(vector<int>& A){
    int left = 0, right = A.size() - 1;
    
    //if mid < A[mid], have to go right
    //if mid > A[mid], have to go left
    //if mid == A[mid], return
    
    while(left <= right){
        int mid = left + (right - left)/2;
        if(mid < A[mid]){
            left = mid + 1;
        }else if(mid > A[mid]){
            right = mid - 1;
        }else{
            return mid;
        }
    }
    
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A = {-1,0,1,3,5,6,7};
    int result = SearchIndex(A);
    assert(result == 3);
    return 0;
}
