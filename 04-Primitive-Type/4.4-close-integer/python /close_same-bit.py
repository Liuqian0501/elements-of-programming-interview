#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Aug 16 16:33:06 2017

@author: LiuQianKevin
"""
import sys
import random

def swap_bits(x, i, j):
    if (x >> i) & 1 != (x >> j) & 1:
        bit_mask = (1 << i) | (1 << j)
        x ^= bit_mask
    return x
    

def closest_int_same_bit_count(x):
    i, j = 0, 1;
    while(j < 64):
        if(x == swap_bits(x, i, j)):
            i += 1;
            j += 1;
        else:
            return swap_bits(x, i, j);
    
    raise ValueError('All bits are 0 or 1')

def small_test():
    assert closest_int_same_bit_count(6) == 5
    assert closest_int_same_bit_count(7) == 11
    assert closest_int_same_bit_count(2) == 1
    assert closest_int_same_bit_count(32) == 16
    assert closest_int_same_bit_count(2**64 - 2) == 2**64 - 3

    try:
        closest_int_same_bit_count(2**64 - 1)
        assert False
    except ValueError as e:
        print(e)
    try:
        closest_int_same_bit_count(0)
        assert False
    except ValueError as e:
        print(e)


def main():
    small_test()
    x = int(sys.argv[1]) if len(sys.argv) == 2 else random.randint(0,
                                                                   sys.maxsize)
    try:
        res = closest_int_same_bit_count(x)
        print(x, res)
        assert count_bits_set_to1(x) == count_bits_set_to1(res)
    except ValueError as e:
        print(x, e)


if __name__ == '__main__':
    main()
