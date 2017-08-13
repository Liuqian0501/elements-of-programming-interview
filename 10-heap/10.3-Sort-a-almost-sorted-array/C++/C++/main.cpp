//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/12/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using std::vector;
using std::priority_queue;
using std::greater;
using std::equal;

vector<int> SortApproximatelySortedData(vector<int> sequence, int k){
    priority_queue<int, vector<int>, greater<int>> queue_;
    for(int i = 0; i < k && i < sequence.size(); i++){
        queue_.push(sequence[i]);
    }
    vector<int> result;
    for(int i = k; i < sequence.size(); i++){
        queue_.push(sequence[i]);
        result.push_back(queue_.top());
        queue_.pop();
    }
    while(!queue_.empty()){
        result.push_back(queue_.top());
        queue_.pop();
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // Test 1
    vector<int> v1 = {1,2,1,3,4,4,3,4,5,6};
    vector<int> e1 = {1,1,2,3,3,4,4,4,5,6};
    vector<int> r1 = SortApproximatelySortedData(v1, 2);
    assert(equal(e1.begin(), e1.end(), r1.begin()));
    
    // Test 2
    // Test 1
    vector<int> v2 = {1,2,1,3,4,1,3,4,5,6};
    vector<int> e2 = {1,1,1,2,3,3,4,4,5,6};
    vector<int> r2 = SortApproximatelySortedData(v2, 3);
    assert(equal(e2.begin(), e2.end(), r2.begin()));
    return 0;
}
