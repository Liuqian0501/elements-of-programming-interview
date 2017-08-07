//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/6/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <vector> //std::vector
#include <stdio.h>

using namespace std;

#ifndef dutchFlagPartition_H_
#define dutchFlagPartition_H_

namespace dutchFlagPartition {
    typedef enum { RED, WHITE, BLUE} Color;
    
    void Swap(vector<Color>& A, int x, int y){
        Color temp = A[x];
        A[x] = A[y];
        A[y] = temp;
    }
    //pivot_index is set as pivote
    void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr){
        vector<Color>& A = *A_ptr;
        Color pivot = A[pivot_index];
        /**
         Keep in mind
         
         small_set(< pivot): [0, small];
         middle_set(= pivot): [small+1, middle];
         larger_set(> pivot): [middle+1, large-1];
         untouched_set : [large, A.size()-1]
         
         init: small = -1, middle = -1, large = 0
         **/
        int small = -1, middle = -1, large = 0;
        while(large < A.size()){
            if(A[large] < pivot){
                //add to small_set and shift middle and large
                Swap(A, middle+1, large), Swap(A,small+1, middle+1);
                small++, middle++, large++;
            }else if (A[large] == pivot){
                Swap(A, middle+1, large);
                middle++, large++;
            }else{
                large++;
            }
        }
    }
}

#endif

#ifndef unitest
#define unitest
namespace unitest {
    void Test(vector<dutchFlagPartition::Color> A,
         vector<dutchFlagPartition::Color> expected, unsigned n, unsigned p){
        dutchFlagPartition::DutchFlagPartition(p, &A);
        if (std::equal(A.begin(), A.begin() + n-1, expected.begin())){
            std::cout << "success" << std::endl;
        }else{
            std::cout << "Fail" << std::endl;
        }
    }
}
#endif
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<dutchFlagPartition::Color> A(6, dutchFlagPartition::Color::RED);
    A[2] = dutchFlagPartition::Color::WHITE,A[3] = dutchFlagPartition::Color::WHITE;
    A[4] = dutchFlagPartition::Color::BLUE, A[5] = dutchFlagPartition::Color::BLUE;
    
    vector<dutchFlagPartition::Color> B(6, dutchFlagPartition::Color::RED);
    B[2] = dutchFlagPartition::Color::BLUE,B[3] = dutchFlagPartition::Color::BLUE;
    B[4] = dutchFlagPartition::Color::WHITE, B[5] = dutchFlagPartition::Color::WHITE;
    
    vector<dutchFlagPartition::Color> C(6, dutchFlagPartition::Color::RED);
    C[1] = dutchFlagPartition::Color::BLUE,C[3] = dutchFlagPartition::Color::BLUE;
    C[2] = dutchFlagPartition::Color::WHITE, C[4] = dutchFlagPartition::Color::WHITE;
    
    unitest::Test(B, A, 6, 4);
    unitest::Test(C, A, 6, 2);
    return 0;
}
