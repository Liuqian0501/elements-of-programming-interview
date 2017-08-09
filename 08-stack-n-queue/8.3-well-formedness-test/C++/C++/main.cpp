//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/9/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <stack>

using std::string;
using std::stack;
using std::unordered_map;
using std::cout;
using std::endl;


bool IsWellFormed(const string& s){
    stack<char> stored;
    //define look up map
    const unordered_map<char, char> lookup_map = {
        {'{','}'},{'(',')'},{'[',']'}
    };
    
    //check formation
    for(char c : s){
        //if(lookup_map.find(c) != lookup_map.end()){
        if(lookup_map.count(c)){
            stored.push(lookup_map.find(c)->second);
        }else{
            if (c == stored.top()) {
                stored.pop();
            }
        }
    }
    return stored.empty();
}

void small_test() {
    assert(IsWellFormed("()"));
    assert(IsWellFormed("()[]{}"));
    assert(IsWellFormed("[()[]]{}"));
    assert(IsWellFormed("(()[]{()[]{}{}})"));
    assert(!IsWellFormed("([)]"));
    assert(!IsWellFormed("["));
    assert(!IsWellFormed("(()[]{()[]{})({}})"));
    cout<<"Success"<<endl;
}

int main(int argc, char** argv) {
    small_test();
    return 0;
}
