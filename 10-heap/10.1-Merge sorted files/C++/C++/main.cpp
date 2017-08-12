//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/11/17.
//  Copyright © 2017 qianliu. All rights reserved.
//


#include <vector>
#include <cassert>
#include <queue>

using std::vector;
using std::equal;
using std::greater;
using std::priority_queue;

struct elementwithindex{
    int value;
    int index1;//index of vector in vector<vector<int>>
    int index2;//index of int in vector<int>
};

struct mycomparison{
    bool operator() (const elementwithindex& lhs, const elementwithindex&rhs) const
    {
        return lhs.value > rhs.value;
    }
};


vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
    priority_queue<int, vector<elementwithindex>, mycomparison> queue_;
    int len = 0;
    //push first element of each vector to queue
    for(int i = 0; i < sorted_arrays.size(); i++){
        elementwithindex e = {sorted_arrays[i][0], i, 0};
        queue_.push(e);
        len += sorted_arrays[i].size();//total len
    }
    
    //push value to result
    vector<int> result(len, 0);
    for(int i = 0; i<len; i++){
        elementwithindex top = queue_.top();
        queue_.pop();
        result[i] = top.value;
        int index1 = top.index1, index2 = top.index2;
        
        if(index2 + 1 < sorted_arrays[index1].size()){
            queue_.push({sorted_arrays[index1][index2+1], index1, index2+1});
        }
    }
    return result;
    
}
int main(int argc, const char * argv[]) {
    // Test 1
    vector<vector<int>> v1 = {{1,2,3},{2,3,4},{2,5,6}};
    vector<int> expect1 = {1,2,2,2,3,3,4,5,6};
    vector<int> result = MergeSortedArrays(v1);
    
    assert(equal(expect1.begin(), expect1.end(), result.begin()));
    return 0;
}
