/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <chrono>
#include "parity1.h"
#include "parity2.h"
#include "parity3.h"
#include "parity4.h"

using namespace std;

int main()
{
    printf("Hello World");
    cout << "" << endl;
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    cout << Parity1::Parity(0) << endl;
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    std::cout << "Time difference 1 = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - begin).count() <<std::endl;
    

    cout << Parity2::Parity(0) << endl;
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    std::cout << "Time difference 2 = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - end1).count() <<std::endl;
    

    cout << Parity3::Parity(0) << endl;
    std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
    std::cout << "Time difference 3 = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end3 - end2).count() <<std::endl;
    

    cout << Parity4::Parity(0) << endl;
    std::chrono::steady_clock::time_point end4 = std::chrono::steady_clock::now();
    std::cout << "Time difference 4 = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end4 - end3).count() <<std::endl;
    return 0;
}

