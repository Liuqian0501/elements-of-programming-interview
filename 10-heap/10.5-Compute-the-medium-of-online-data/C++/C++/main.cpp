//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/12/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::greater;
using std::istringstream;
using std::less;
using std::priority_queue;
using std::random_device;
using std::string;
using std::stringstream;
using std::uniform_int_distribution;
using std::vector;

vector<double> global_result;

// @include
void OnlineMedian(istringstream* sequence) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    
    int x = 0;
    while(*sequence >> x){
        
        //first push to maxHeap,then to minHeap. if(minHeap,size - maxHeap.size == 2) push one back to maxHeap.
        maxHeap.push(x);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() - maxHeap.size() == 1){
            global_result.push_back(minHeap.top());
        }else{
            maxHeap.push(minHeap.top());
            minHeap.pop();
            global_result.push_back((minHeap.top()+maxHeap.top())*0.5);
        }
    }
}
// @exclude

void SmallTest() {
    istringstream sequence("5 4 3 2 1");
    OnlineMedian(&sequence);
    vector<double> golden = {5, 4.5, 4, 3.5, 3};
    
    assert(equal(golden.begin(), golden.end(), global_result.begin()));
    
    global_result.clear();
    istringstream sequence1("1 2 3 4 5");
    OnlineMedian(&sequence1);
    golden = {1, 1.5, 2, 2.5, 3};
    assert(equal(golden.begin(), golden.end(), global_result.begin()));
    
    
    global_result.clear();
    istringstream sequence2("1 0 3 5 2 0 1");
    OnlineMedian(&sequence2);
    golden = {1, 0.5, 1, 2, 2, 1.5, 1};
    assert(equal(golden.begin(), golden.end(), global_result.begin()));
    
    
    global_result.clear();
    istringstream sequence3("-1");
    OnlineMedian(&sequence3);
    golden = {-1.0};
    assert(equal(golden.begin(), golden.end(), global_result.begin()));
}

int main(int argc, char* argv[]) {
    SmallTest();
    default_random_engine gen((random_device())());
    int num;
    if (argc == 2) {
        num = atoi(argv[1]);
    } else {
        uniform_int_distribution<int> dis(1, 100000);
        num = dis(gen);
    }
    vector<int> stream;
    for (int i = 0; i < num; ++i) {
        uniform_int_distribution<int> dis(1, 10000);
        stream.emplace_back(dis(gen));
    }
    string s;
    for (int i = 0; i < stream.size(); ++i) {
        cout << stream[i] << endl;
        stringstream ss;
        ss << stream[i];
        s += ss.str();
        s += ' ';
    }
    cout << endl;
    istringstream sequence(s);
    OnlineMedian(&sequence);
    return 0;
}
