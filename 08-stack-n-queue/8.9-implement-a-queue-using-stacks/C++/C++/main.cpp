//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/10/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <limits>
#include <stack>
#include <stdexcept>

using std::cout;
using std::endl;
using std::exception;
using std::length_error;
using std::numeric_limits;
using std::stack;

// @include
class Queue {
public:
    void Enqueue(int x) {
        //push the element to enqueue_
        enqueue_.push(x);
    }
    
    int Dequeue() {
        //if dequeue is empty, push elements in enqueue to dequeue
        if(dequeue_.empty()){
            while(!enqueue_.empty()){
                dequeue_.push(enqueue_.top());
                enqueue_.pop();
            }
        }

        //if dequeue is not empty pop element from dequeue
        //else throw empty error
        if(!dequeue_.empty()){
            int result = dequeue_.top();
            dequeue_.pop();
            return result;
        }else{
            throw length_error("empty queue");
        }
    }
    
private:
    stack<int> enqueue_, dequeue_;
};
// @exclude

int main(int argc, char* argv[]) {
    Queue Q;
    Q.Enqueue(1);
    Q.Enqueue(2);
    assert(1 == Q.Dequeue());
    assert(2 == Q.Dequeue());
    Q.Enqueue(3);
    assert(3 == Q.Dequeue());
    try {
        Q.Dequeue();
        assert(false);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    Q.Enqueue(-1);
    Q.Enqueue(123);
    Q.Enqueue(numeric_limits<int>::max());
    Q.Enqueue(numeric_limits<int>::min());
    Q.Enqueue(0);
    assert(-1 == Q.Dequeue());
    Q.Enqueue(0);
    assert(123 == Q.Dequeue());
    assert(numeric_limits<int>::max() == Q.Dequeue());
    assert(numeric_limits<int>::min() == Q.Dequeue());
    assert(0 == Q.Dequeue());
    assert(0 == Q.Dequeue());
    try {
        Q.Dequeue();
        assert(false);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
