//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/10/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;
using std::endl;
using std::exception;
using std::length_error;
using std::vector;
class Queue {
public:
    explicit Queue(size_t capacity)
        : entries_(capacity){
        };
    
    void Enqueue(int x){
        //if vector is full store elements in new vector
        if(num_queue_elements == entries_.size()){
            vector<int> newVector(entries_.size()*kScaleFactor,0);
            for(int i = 0; i < num_queue_elements; i++){
                newVector[i] = entries_[head_++];
                head_ %= num_queue_elements;
            }
            //update vector, head and tail
            entries_ = newVector;
            head_ = 0;
            tail_ = num_queue_elements;
        }
        
        //add element to tail and update tail
        num_queue_elements++;
        entries_[tail_++] = x;
        tail_ %= entries_.size();
    }
    
    int Dequeue(){
        if(num_queue_elements == 0){
            throw length_error("no element");
        }else{
            //return entries_[head] and updata head
            int result = entries_[head_++];
            head_ %= entries_.size();
            num_queue_elements--;
            return result;
        }
    }
    
    size_t size(){
        return num_queue_elements;
    }
private:
    const int kScaleFactor = 2;
    //queue elements are between head_->tail-1
    size_t head_ = 0, tail_ = 0, num_queue_elements = 0;
    vector<int> entries_;
};
void Test() {
    Queue q(8);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(8);
    // Now head = 0 and tail = 0
    
    assert(1 == q.Dequeue());
    assert(2 == q.Dequeue());
    assert(3 == q.Dequeue());
    // Now head = 3 and tail = 0
    
    q.Enqueue(11);
    q.Enqueue(12);
    q.Enqueue(13);
    // Ok till here. Now head = 3 and tail = 3
    
    q.Enqueue(14);  // now the vector (data) is resized; but the head and tail.
    // (or elements) does not change accordingly.
    q.Enqueue(15);
    q.Enqueue(16);
    q.Enqueue(17);
    q.Enqueue(18);
    // The elements starting from head=3 are over-written!
    
    assert(4 == q.Dequeue());
    assert(5 == q.Dequeue());
    assert(6 == q.Dequeue());
    assert(7 == q.Dequeue());
    assert(8 == q.Dequeue());
    assert(11 == q.Dequeue());
    assert(12 == q.Dequeue());
}

int main(int argc, char* argv[]) {
    Test();
    Queue q(8);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    assert(1 == q.Dequeue());
    q.Enqueue(4);
    assert(2 == q.Dequeue());
    assert(3 == q.Dequeue());
    assert(4 == q.Dequeue());
    try {
        q.Dequeue();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    // test resize().
    q.Enqueue(4);
    q.Enqueue(4);
    q.Enqueue(4);
    q.Enqueue(4);
    q.Enqueue(4);
    q.Enqueue(4);
    q.Enqueue(4);
    q.Enqueue(4);
    q.Enqueue(4);
    assert(q.size() == 9);
    return 0;
}
