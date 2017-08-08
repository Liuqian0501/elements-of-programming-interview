//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/7/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef baseConversion_H_
#define baseConversion_H_
namespace baseConversion{
    string ConvertBase(string& num_as_string, int num1, int num2){
        //negtive or positive. First to decimal
        int decimal = 0, power = 1,digit = 0;
        for(int i = num_as_string.length() - 1; i > (num_as_string[0] == '-' ? 0:-1); i--){
            if(num_as_string[i] < 'A'){
                digit = num_as_string[i] - '0';
            }else{
                digit = num_as_string[i] - 'A' + 10;
            }
            decimal += digit*power;
            power *= num1;
        }
        //cout << decimal;
        
        //decimal to num2 base
        string result = "";
        while(decimal){
            if(decimal % num2 < 10){
                result += ('0'+ (decimal % num2));
            }else{
                result += ('A'+ (decimal % num2) - 10);
            }
            decimal /= num2;
        }
        //add sign
        if(num_as_string[0] == -1) result += '-';
        return {result.rbegin(), result.rend()};
    };
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest{
    void Test(string& num_as_string, int num1, int num2, string expected){
        string result = baseConversion::ConvertBase(num_as_string, num1, num2);
        //cout << result;
        if(result == expected){
            cout << "Success" << endl;
        }else{
            cout << "Fail" << endl;
        }
    }
}
#endif
int main(int argc, const char * argv[]) {
    // Test 1
    string s = "10", expected = "5";
    int num1 = 5, num2 = 10;
    unitest::Test(s, num1, num2, expected);
    
    // Test 2
    string s1 = "1A", expected1 = "21";
    int num3 = 11, num4 = 10;
    unitest::Test(s1, num3, num4, expected1);
    
    // Test 3
    string s2 = "21", expected2 = "1A";
    int num5 = 10, num6 = 11;
    unitest::Test(s2, num5, num6, expected2);

    return 0;
}
