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

class bsearch {
public:
    static int Bsearch(int i, const vector<int>& A){
        int left = 0, right = A.size();
        //keep searching until right is smaller than left
        while(left <= right){
            int mid = left + (right - left)/2;
            if(A[mid] < i){
                left = mid + 1;
            }else if(A[mid] > i){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A = {1,2,3,4,5,6};
    int e = 2;
    int result = bsearch::Bsearch(3, A);
    assert(e = result);
    return 0;
}
