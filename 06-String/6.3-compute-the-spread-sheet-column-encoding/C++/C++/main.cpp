//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/7/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef ssDecode_H_
#define ssDecpde_H_
namespace ssDecode{
    int SsDecode(const string& s){
        //A-->1
        //AA --> 27
        unsigned long len = s.size();
        int result = 0;
        for(long i = len - 1; i >= 0; i--){
            result = 26*result + s[i] - 'A' + 1;
        }
        return result;
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest{
    void Test(const string& s, int x){
        int result = ssDecode::SsDecode(s);
        if(result == x){
            cout << "Success" << endl;
        }else{
            cout << "Fail" << endl;
        }
    }
}
#endif
int main(int argc, const char * argv[]) {
    // Test 1
    string s = "A";
    int x = 1;
    unitest::Test(s, x);
    
    // Test 2
    string s2 = "AA";
    int x2 = 27;
    unitest::Test(s2, x2);
    return 0;
}
