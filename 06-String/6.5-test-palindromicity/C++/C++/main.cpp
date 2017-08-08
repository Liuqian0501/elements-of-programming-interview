//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/7/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef isPalindrome_H_
#define isPalindrome_H_
namespace isPalindrome {
    bool IsAlpha(char c){
        //cout << "called" << endl;
        if( c - 'A' >= 0 && c - 'z' <=0){
            return true;
        }else{
            return false;
        }
    }
    bool IsPalindrome(const string& s){
        int len = s.length();
        //use two pointers
        int i = 0, j = len - 1;
        while( i < j){
            while(!IsAlpha(s[i]) && i<j){
                i++;
            }
            while(!IsAlpha(s[j]) && i<j){
                j--;
            }
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest {
    void Test(const string& s, bool x){
        bool result = isPalindrome::IsPalindrome(s);
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
    string s = "a ,b,c,b,a";
    bool s_ = true;
    unitest::Test(s,s_);
    
    // Test 2
    string s2 = "a ,b,,,c,c,b,a";
    bool s2_ = true;
    unitest::Test(s2,s2_);
    
    // Test 3
    string s3 = "a ,,c,b,a";
    bool s3_ = false;
    unitest::Test(s3,s3_);
//    cout << isPalindrome::IsAlpha('Z');
    return 0;
}
