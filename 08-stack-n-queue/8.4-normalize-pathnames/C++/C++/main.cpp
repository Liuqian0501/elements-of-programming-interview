//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/9/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <stack>

using std::stack;
using std::string;
using std::exception;
using std::invalid_argument;
using std::stringstream;
using std::cout;
using std::endl;

string ShortestEquivalentPath(const string& path){
    stack<string> foldStack;
    //check first '/'
    if(path[0] == '/') foldStack.push("/");
    
    stringstream ss(path);
    string token;
    const char kDelimiter = '/';
    while(getline(ss,token,kDelimiter)){
        if(token == ".."){
            if(foldStack.empty()||foldStack.top() == ".."){
                foldStack.push(token);
            }else{
                if(foldStack.top() == "/"){
                    throw invalid_argument("Path error");
                }else{
                    foldStack.pop();
                }
            }
        }else if(token == "." || token == ""){
            continue;
        }else{
            foldStack.push(token);
        }
    }
    
    //build newPath
    string newPath = "";
    
    while(!foldStack.empty()){
        if(foldStack.top()!="/"){
            newPath = "/" + foldStack.top() + newPath;
        }else{
            newPath = foldStack.top() + newPath;
        }
        foldStack.pop();
    }

    return newPath.length() ==1 ? newPath : newPath.substr(1);
}

int main(int argc, char* argv[]) {
    assert(ShortestEquivalentPath("123/456") == string("123/456"));
    assert(ShortestEquivalentPath("/123/456") == string("/123/456"));
    assert(ShortestEquivalentPath("usr/lib/../bin/gcc") ==
           string("usr/bin/gcc"));
    assert(ShortestEquivalentPath("./../") == string(".."));
    assert(ShortestEquivalentPath("../../local") == string("../../local"));
    assert(ShortestEquivalentPath("./.././../local") == string("../../local"));
    assert(ShortestEquivalentPath("/foo/../foo/./../") == string("/"));
    try {
        ShortestEquivalentPath("/foo.txt");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    try {
        ShortestEquivalentPath("");
        assert(false);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    try {
        ShortestEquivalentPath("/..");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    try {
        ShortestEquivalentPath("/cpp_name/bin/");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    assert(ShortestEquivalentPath("scripts//./../scripts/awkscripts/././") ==
           string("scripts/awkscripts"));
    if (argc == 2) {
        cout << ShortestEquivalentPath(argv[1]) << endl;
    }
    return 0;
}
