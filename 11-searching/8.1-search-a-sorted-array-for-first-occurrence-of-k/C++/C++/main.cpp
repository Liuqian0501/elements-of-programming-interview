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

int SearchFirstofK(vector<int> A, int k){
    //find one of k
    int left = 0, right = A.size() - 1, result = -1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(A[mid] < k){
            left = mid + 1;
        }else if(A[mid] > k){
            right = mid - 1;
        }else{
            result = mid;
            break;
        }
    }
    
    //find first index
    while(result >= 0 && A[result - 1] == A[result]){
        result --;
    }
    
    return result;
}
int main(int argc, const char * argv[]) {
    // Test
    vector<int> T1 = {1,2,2,3,4,5};
    int e1 = SearchFirstofK(T1, 2);
    assert(e1 == 1);
    e1 = SearchFirstofK(T1, 6);
    assert(e1 == -1);
    std::cout << "Success";
    return 0;
}
