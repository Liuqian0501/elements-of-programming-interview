//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/7/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef int_string_H_
#define int_string_H_
namespace intstring{
    string IntToString(int x){
        //start from head to end then reverse
        string result = "";
        string sign = "";
        
        if(x<0){
            sign = "-";
            x *= -1;
        }
        
        while(x){
            int digit = x%10;
            result += ('0'+digit);
            x /= 10;
        }
        result += sign;
        
        //reverse
        return {result.rbegin(), result.rend()};
    }
    
    int StringToInt(const string s){
        int result = 0;
        for(int i = s[0] == '-' ? 1:0; i < s.length(); i++){
            result = 10*result + s[i] - '0';
        }
        if(s[0] == '-') result *= -1;
        return result;
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest{
    void Test(const string s, int x){
        int intResult = intstring::StringToInt(s);
        string stringResult = intstring::IntToString(x);
        
        if(intResult == x && stringResult == s){
            cout << "Success" << endl;
        }else{
            cout << "Fail" << endl;
        }
    }
}
#endif

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "123";
    int x = 123;
    unitest::Test(s, x);
    
    string s2 = "-123";
    int x2 = -123;
    unitest::Test(s2, x2);

    return 0;
}
