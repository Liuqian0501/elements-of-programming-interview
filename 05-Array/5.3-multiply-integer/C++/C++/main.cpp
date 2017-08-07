//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/7/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <vector> //use std::vector

using namespace std;

#ifndef multiply_H_
#define multiply_H_
namespace multiply {
    vector<int> Multiply(vector<int> num1, vector<int> num2){
        vector<int> result(num1.size()+num2.size(),0);
        const int n = result.size();
        
        for(int i = num1.size() -1; i >= 0; --i){
            for(int j = num2.size() -1; j >= 0; --j){
                result[i+j+1] += num1[i] * num2[j];
                result[i+j] += result[i+j+1] / 10;
                result[i+j+1] %= 10;
            }
        }

        
        //remove front 0
        int index = n;
        for(int i = 0; i < n; i++){
            
            if(result[i] != 0){
                index = i;
                break;
            }
        }
        
        if(index == n) return {0};
        else{
            vector<int> newVec;
            for(int i = index; i<n;i++){
                newVec.push_back(result[i]);
                //cout << result[i];
            }
            return newVec;
        }
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest {
    void Test(vector<int> num1, vector<int> num2, vector<int> expected, const int n){
        vector<int> result = multiply::Multiply(num1, num2);

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
    const int n = 5;
    vector<int> num1(n,0);
    vector<int> num2(n,0);
    vector<int> expected(1,0);
    
    num1[n-1] = 0;
    num2[n-1] = 0;
    expected[0] = 0;
    unitest::Test(num1, num2, expected, 1);
    
    
    vector<int> num3(n,0);
    vector<int> num4(n,0);
    vector<int> expected2(1,0);
    
    num3[n-1] = 1;
    num4[n-1] = 2;
    expected2[0] = 2;
    unitest::Test(num3, num4, expected2, 1);
    
    vector<int> num5(n,0);
    vector<int> num6(n,0);
    vector<int> expected3(2,0);
    
    num5[n-1] = 4;
    num6[n-1] = 6;
    expected3[0] = 2,expected3[1] = 4;
    unitest::Test(num5, num6, expected3, 2);
    
    vector<int> num7(n,9);
    vector<int> num8(n,9);
    vector<int> expected4 = {9,9,9,9,8,0,0,0,0,1} ;
    
    unitest::Test(num7, num8, expected4, 10);
    
    return 0;
}
