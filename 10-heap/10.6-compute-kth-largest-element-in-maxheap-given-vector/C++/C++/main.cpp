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
using std::equal;
using std::priority_queue;
using std::less;

struct element{
    int value;
    int index;
    bool operator < (const element& that) const{
        return value < that.value;
    }
};

vector<int> KthMax(vector<int>& v, int k){
    vector<int> result;
    //while pop out element, push into two child
    priority_queue<element, vector<element>> pqueue;
    
    if(k == 0) return result; //base case
    
    pqueue.push({v[0],0});

    while(result.size() < k){
        //pop out
        auto top = pqueue.top();
        pqueue.pop();
        result.push_back(top.value);
        //push in
        int left = top.index * 2 + 1;
        int right = left + 1;
        if(left < v.size()){
            pqueue.push({v[left], left});
        }
        if(right < v.size()){
            pqueue.push({v[right], right});
        }
    }
    
    return result;
}
int main(int argc, const char * argv[]) {
    // Test 1
    /*
            6
         4     5
       1  2   3  0
    */
    vector<int> v1 = {6, 4, 5, 1, 2, 3, 0};
    vector<int> e1 = {6,5,4,3,2,1,0};
    vector<int> result = KthMax(v1, 7);
    assert(equal(e1.begin(), e1.end(), result.begin()));
    
    /*
                     10
                  2          9
                2   2      8   8
              2 2  2 2    7 7  7 7
     */
    vector<int> max_heap = {10, 2, 9, 2, 2, 8, 8, 2, 2, 2, 2, 7, 7, 7, 7};
    result = KthMax(max_heap, 3);
    
    vector<int> expected_result = {10, 9, 8};
    assert(equal(result.begin(), result.end(), expected_result.begin()));
    result = KthMax(max_heap, 5);
    expected_result = {10, 9, 8, 8, 7};
    assert(equal(result.begin(), result.end(), expected_result.begin()));
    
    max_heap = {97, 84, 93, 83, 81, 90, 79, 83, 55, 42, 21, 73};
    result = KthMax(max_heap, 3);
    expected_result = {97, 93, 90};
    assert(equal(result.begin(), result.end(), expected_result.begin()));
    
    max_heap = {100, 1, 5, 0, 0};
    result = KthMax(max_heap, 1);
    expected_result = {100};
    assert(equal(result.begin(), result.end(), expected_result.begin()));
    return 0;
}
