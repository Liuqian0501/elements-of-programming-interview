//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/15/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
#include <unordered_set>

using std::string;
using std::unordered_set;

bool CanFormPalindrome(const string& s){
    unordered_set<char> char_with_odd_frequency;
    for(char c : s){
        if(char_with_odd_frequency.count(c)){
            char_with_odd_frequency.erase(c);
        }else{
            char_with_odd_frequency.insert(c);
        }
    }
    return char_with_odd_frequency.size()<=1;
}

int main(int argc, const char * argv[]) {
    // T1
    string s = "abcdcbaee";
    bool result = CanFormPalindrome(s);
    assert(result == true);
    return 0;
}
