//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/10/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>

#ifndef queue_with_max_h_
#define queue_with_max_h_

#include <algorithm>
#include <deque>
#include <queue>
#include <stdexcept>
#include <cassert>

using std::deque;
using std::length_error;
using std::queue;

template <typename T>
class QueueWithMax{
public:
    void Enqueue(const T& x){
        entries_.push(x);
        
        //update candidates_max: delete privious elements(<x)
        while(!candidates_for_max_.empty() && candidates_for_max_.back() < x){
            candidates_for_max_.pop_back();
        }
        candidates_for_max_.push_back(x);
    }
    
    T Max(){
        if (!candidates_for_max_.empty()) {
            return candidates_for_max_.front();
        }
        throw length_error("empty queue");
    }
    
    T Dequeue(){
        T result = entries_.front();
        entries_.pop();
        
        //update candidates_for_max: delete front if front is equal to T
        if(result == candidates_for_max_.front()){
            candidates_for_max_.pop_front();
        }
        return result;
    }
    
private:
    queue<T> entries_;
    deque<T> candidates_for_max_;
};
    

#endif
int main(int argc, const char * argv[]) {
    // insert code here...
    QueueWithMax<int> queue_;
    queue_.Enqueue(3);
    queue_.Enqueue(2);
    queue_.Enqueue(3);
    queue_.Enqueue(4);
    assert(4==queue_.Max());
    assert(3==queue_.Dequeue());
    assert(4==queue_.Max());
    
    queue_.Enqueue(1);
    queue_.Enqueue(5);
    assert(5==queue_.Max());
    
    std::cout << "Success!" << std::endl;

    return 0;
}
