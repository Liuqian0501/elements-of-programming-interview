//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/12/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "./sortKvector.h"

using std::vector;
using std::equal;
using std::cout;
using std::endl;
using sortKvectors::MergeSortedArrays;

vector<vector<int>> toSortedVectors(const vector<int>& A){
    /*
     input = {1,2,3,4,3,2,1,2,3,4,3,2,1}
     output = {{1,2,3,4},{1,2,3},{2,3,4},{1,2,3}};
     */
    vector<vector<int>> result;
    vector<int> subvector;
    subvector.push_back(A[0]);
    bool increasing = true;
    for(int i = 1; i < A.size(); i++){
        if((A[i] >= A[i-1] && increasing)||(A[i] <= A[i-1] && !increasing)){
            subvector.push_back(A[i]);
        }
        else{
            if(!increasing){
                subvector = {subvector.rbegin(), subvector.rend()};
            };
            result.push_back(subvector);
            
            subvector = {};
            subvector.push_back(A[i]);
            increasing = !increasing;
        }
    }
    if(!increasing){
        subvector = {subvector.rbegin(), subvector.rend()};
    };
    result.push_back(subvector);
    return result;
};

vector<int> SortKIncreasingDecreasingArray(const vector<int>& A){
    vector<vector<int>> sortedVector = toSortedVectors(A);
    vector<int> result = MergeSortedArrays(sortedVector);
    
    return result;
};


int main(int argc, const char * argv[]) {
    //Test 1
    vector<int> v1 = {1,2,3,4,3,2,1,2,3,4,3,2,1};
    vector<vector<int>> int1 = {{1,2,3,4},{1,2,3},{2,3,4},{1,2,3}};
    vector<vector<int>> r_int1 = toSortedVectors(v1);
    assert(equal(int1.begin(), int1.end(),r_int1.begin()));
    
    vector<int> e1 = {1,1,1,2,2,2,2,3,3,3,3,4,4};
    vector<int> result = SortKIncreasingDecreasingArray(v1);

    assert(equal(e1.begin(), e1.end(), result.begin()));
    return 0;
}
