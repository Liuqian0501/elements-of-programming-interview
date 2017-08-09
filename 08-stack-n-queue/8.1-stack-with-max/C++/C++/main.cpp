//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/9/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cassert>

using std::stack;
using std::length_error;
using std::cout;
using std::endl;
using std::exception;

class Stack {
/*
 I use stack element_ to store all element and cached)max_with_count to store max element's value and counts
 The extral storage needed is O(n)(worst case), O(1)(best case). Better than O(n);
*/
public:
    bool Empty() const {
        return element_.empty();
    };
    int Max() const {
        //check empty
        if(Empty()){
            throw length_error("Max(): empty stack");
        }
        return cached_max_with_count_.top().max;
    }
    int Pop() {
        //check empty
        if(Empty()){
            throw length_error("Max(): empty stack");
        }
        int result = element_.top();
        element_.pop();
        
        //update cached max information
        if(result == cached_max_with_count_.top().max){
            cached_max_with_count_.top().count--;
            if(cached_max_with_count_.top().count == 0){
                cached_max_with_count_.pop();
            };
        }
        return result;
    }
    void Push(int x){
        element_.push(x);
        
        //update cached max information
        if(cached_max_with_count_.empty()){
            cached_max_with_count_.push(MaxWithCount{x,1});
        }else{
            if (cached_max_with_count_.top().max == x) {
                cached_max_with_count_.top().count++;
            }else if(x > cached_max_with_count_.top().max){
                cached_max_with_count_.push(MaxWithCount{x,1});
            }
        }
    }

private:
    stack<int> element_;
    struct MaxWithCount {
        int max, count;
    };
    
    stack<MaxWithCount> cached_max_with_count_;
    
    
};

int main(int argc, const char * argv[]) {
    Stack s;
    s.Push(1);
    s.Push(2);
    assert(s.Max() == 2);
    cout << s.Max() << endl;  // 2
    cout << s.Pop() << endl;  // 2
    assert(s.Max() == 1);
    cout << s.Max() << endl;  // 1
    s.Push(3);
    s.Push(2);
    assert(s.Max() == 3);
    cout << s.Max() << endl;  // 3
    s.Pop();
    assert(s.Max() == 3);
    cout << s.Max() << endl;  // 3
    s.Pop();
    assert(s.Max() == 1);
    cout << s.Max() << endl;  // 1
    s.Pop();
    try {
        s.Max();
        s.Pop();
        s.Pop();
        s.Pop();
        s.Pop();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
