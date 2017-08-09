//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/9/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <stack>

using std::stack;
using std::string;
using std::getline; // same as split
using std::stringstream; // string to stringsteam
using std::stoi;//string to int

namespace eval {
    int Eval(const string& RPN_expression){
        stack<int> stored_int;
        stringstream ss(RPN_expression);
        string token;
        const char kDelimiter = ',';
        
        while(getline(ss,token, kDelimiter)){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                const int x = stored_int.top();
                stored_int.pop();
                const int y = stored_int.top();
                stored_int.pop();
                switch (token.front()) {
                    case '+':
                        stored_int.push(x+y);
                        break;
                    case '-':
                        stored_int.push(y-x);
                        break;
                    case '*':
                        stored_int.push(x*y);
                        break;
                    case '/':
                        stored_int.push(y/x);
                        break;
                }
            }else{
                
                stored_int.push(stoi(token));
            }
        }
        
        return stored_int.top();
    }
}

int main(int argc, const char * argv[]) {
    assert(0 == eval::Eval("2,-10,/"));
    assert(-5 == eval::Eval("-10,2,/"));
    assert(5 == eval::Eval("-10,-2,/"));
    assert(-5 == eval::Eval("5,10,-"));
    assert(6 == eval::Eval("-10,-16,-"));
    assert(12 == eval::Eval("10,2,+"));
    assert(15 == eval::Eval("1,2,+,3,4,*,+"));
    assert(42 == eval::Eval("1,2,3,4,5,+,*,+,+,3,4,*,+"));
    assert(-6 == eval::Eval("1,2,3,4,5,+,*,+,+,3,4,*,+,-7,/"));
    return 0;
}
