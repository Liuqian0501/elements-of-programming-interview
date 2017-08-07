//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/7/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#ifndef advancingthrough_H_
#define advancingthrough_H_
namespace advancingthrough {
    bool CanReachEnd(const vector<int>& max_advance_steps){
        int lastIndex = max_advance_steps.size() - 1;
        int reachable = 0;
        //be careful about when to stop
        for(int i=0; i<= reachable && reachable < lastIndex; i++){
            int temp = i+max_advance_steps[i];
            reachable = reachable > temp ? reachable : temp;
        }
        
        return reachable >= lastIndex;
        
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest{
    void Test(const vector<int>& max_advance_steps, bool expected){
        bool result = advancingthrough::CanReachEnd(max_advance_steps);
        if(result == expected){
            cout << "Success" <<endl;
        }else{
            cout << "Fail" << endl;
        }
    }
}
#endif

int main(int argc, const char * argv[]) {
    // insert code here...
    const vector<int> A = {3,3,3,0,0,1,1};
    const vector<int> B = {3,3,3,0,0,0,1};
    bool A_ = true, B_ = false;
    unitest::Test(A, A_);
    unitest::Test(B, B_);
    return 0;
}
