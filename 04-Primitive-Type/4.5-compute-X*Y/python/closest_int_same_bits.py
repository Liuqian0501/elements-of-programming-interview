#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Aug 16 16:52:10 2017

@author: LiuQianKevin
"""
import sys
import random

# @include
def multiply(x, y):
    sum = 0;
    while(y != 0):
        if(y & 1):
            sum += x;
        y >>= 1;
        x <<= 1;
    return sum;
        
            
        
 
# @exclude
def main():
    if len(sys.argv) == 3:
        x, y = int(sys.argv[1]), int(sys.argv[2])
        res = multiply(x, y)
        assert res == x * y
        print('x = %d, y = %d, prod = %d' % (x, y, res))
    else:
        for _ in range(100000):
            x, y = random.randint(0, 65534), random.randint(0, 65534)
            prod = multiply(x, y)
            assert prod == x * y
            print('x = %d, y = %d, prod = %d' % (x, y, prod))


if __name__ == '__main__':
    main()