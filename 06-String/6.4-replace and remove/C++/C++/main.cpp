//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/7/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
using namespace std;

#ifndef replaceNremove_H_
#define replaceNremove_H_
namespace replaceNremove{
    char* ReplaceAndRemove(int size, char s[]){
        int countA = 0, writeIndex = 0;
        //remove 'b's and count 'a's
        for(int i = 0; i < size && s[i] != 0;i++){
            if(s[i] != 'b'){
                s[writeIndex] = s[i];
                writeIndex ++;
                if(s[i] == 'a'){
                    countA ++;
                }
            }
        }
        
        //ask for more space and rewrite the array inplace
        int totalSize = writeIndex + countA;
        writeIndex -= 1;
        while(totalSize >= 0 && writeIndex >= 0){
            if(s[writeIndex] == 'a'){
                s[totalSize--] = 'd';
                s[totalSize--] = 'd';
            }else{
                s[totalSize--] = s[writeIndex];
            }
            writeIndex--;
        }
        return s;
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest{
    void Test(char s[], const int size,char e[]){
        char * result = replaceNremove::ReplaceAndRemove(size, e);
        for(int i = 0; i < size; i++){
            if(e[i] != *(result+i)){
                cout << "Fail" << endl;
                return;
            };
        }
        cout << "Success" << endl;

    }
}
#endif
int main(int argc, const char * argv[]) {
    const int size = 6;
    // Test 1
    char s[size] = {'a','a','a'};
    char e[] = {'d','d','d','d','d','d'};
    unitest::Test(s,size ,e);
    
    // Test 2
    char s1[size] = {'b','b','b'};
    char e1[] = {};
    unitest::Test(s1,size,e1);
    
    // Test 3
    char s2[size] = {'a','a','a','b','b','b'};
    char e2[] = {'d','d','d','d','d','d'};
    unitest::Test(s2,size,e2);
    
    return 0;
}
