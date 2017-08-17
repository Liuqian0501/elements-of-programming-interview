//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/16/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

using std::boolalpha;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
using std::unordered_map;
using std::vector;

string RandString(int len) {
    string ret;
    default_random_engine gen((random_device())());
    while (len--) {
        uniform_int_distribution<int> dis(0, 26);
        int x = dis(gen);
        ret += (x < 26) ? 'a' + x : ' ';
    }
    return ret;
}

// @include
bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
    //store chars in letter_text to hashtable (char, int)
    unordered_map<char, int> charTable;
    for(char c : letter_text){
        charTable[c]++;
    }
    
    //go throught magazin text,
    for(char c : magazine_text){
        if(charTable.count(c) > 0){
            charTable[c]--;
            if(charTable[c] == 0){
                charTable.erase(c);
                if(charTable.empty()){
                    break;
                }
            }
        }
    }
    
    //if charTable is empty return
    return charTable.empty();
    
}
// @exclude

void SimpleTest() {
    assert(!IsLetterConstructibleFromMagazine("123", "456"));
    assert(!IsLetterConstructibleFromMagazine("123", "12222222"));
    assert(IsLetterConstructibleFromMagazine("123", "1123"));
    assert(IsLetterConstructibleFromMagazine("123", "123"));
    assert(!IsLetterConstructibleFromMagazine("12323", "123"));
    assert(
           IsLetterConstructibleFromMagazine("GATTACA", "A AD FS GA T ACA TTT"));
    assert(!IsLetterConstructibleFromMagazine("a", ""));
    assert(IsLetterConstructibleFromMagazine("aa", "aa"));
    assert(IsLetterConstructibleFromMagazine("aa", "aaa"));
    assert(IsLetterConstructibleFromMagazine("", "123"));
    assert(IsLetterConstructibleFromMagazine("", ""));
}

int main(int argc, char* argv[]) {
    SimpleTest();
    default_random_engine gen((random_device())());
    string L, M;
    if (argc == 3) {
        L = argv[1], M = argv[2];
    } else {
        uniform_int_distribution<int> L_dis(1, 1000);
        uniform_int_distribution<int> M_dis(1, 100000);
        L = RandString(L_dis(gen)), M = RandString(M_dis(gen));
    }
    cout << L << endl;
    cout << M << endl;
    cout << boolalpha << IsLetterConstructibleFromMagazine(L, M) << endl;
    return 0;
}
