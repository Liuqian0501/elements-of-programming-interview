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

#ifndef plusone_H_
#define plusone_H_
namespace plusone {
    
    vector<int> PlusOne(vector<int> A){
        for(int i = A.size() - 1; i >= 0; --i){
            if(A[i] == 9){
                A[i] = 0;
            }else{
                A[i] += 1;
                return A;
            }
        }
        A.insert(A.begin(), 1);
        return A;
    }
}

#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest {
    void Test(vector<int> A, vector<int> expected, const int n){
        vector<int> result = plusone::PlusOne(A);
        if (std::equal(result.begin(), result.begin() + n, expected.begin())){
            std::cout << "success" << std::endl;
        }else{
            std::cout << "Fail" << std::endl;
        }
    }
}

#endif


int main(int argc, const char * argv[]) {
    // insert code here...
    const int n = 10;
    vector<int> A(n, 0);
    A[9] = 1;
    vector<int> expected(n, 0);
    expected[9] = 2;
    unitest::Test(A, expected, n);
    
    
    vector<int> A2(n, 9);
    vector<int> expected2(n+1, 0);
    expected2[0] = 1;
    unitest::Test(A2, expected2, n+1);
    
    return 0;
}
