//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/7/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#ifndef deleteDuplcate_H_
#define deleteDuplcate_H_
namespace deleteDuplicate{
    int DeliteDuplicates(vector<int>* A_ptr){
        vector<int>& A = *A_ptr;
        int writeIndex = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[writeIndex] != A[i]){
                writeIndex++;
                A[writeIndex] = A[i];
            }
        }
        
        return writeIndex;
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest{
    void Test(vector<int>* A_ptr, vector<int> expected){
        int index = deleteDuplicate::DeliteDuplicates(A_ptr);
        vector<int> A = *A_ptr;

        if(index == expected.size()-1 && equal(A.begin(), A.begin()+index+1, expected.begin())){
            cout << "Success" << endl;
        }else{
            cout << "Fail" << endl;
        }
    }
}
#endif

int main(int argc, const char * argv[]) {
    // Test 1
    vector<int> A = {1,1,2,2,3,3};
    vector<int>* A_ptr = &A;
    vector<int> A_ = {1,2,3};
    unitest::Test(A_ptr, A_);
    
    // Test 2
    vector<int> A2 = {1,1,2,2,3,3,4,4,4};
    vector<int>* A2_ptr = &A2;
    vector<int> A2_ = {1,2,3,4};
    unitest::Test(A2_ptr, A2_);
    return 0;
}
