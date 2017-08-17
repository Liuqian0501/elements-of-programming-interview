#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Aug 16 16:13:02 2017

@author: LiuQianKevin
"""

import sys

def swap_bits(x, i, j):
    # Extract the i-th and j-th bits, and see if they differ.
    if (x >> i) & 1 != (x >> j) & 1:
        # i-th and j-th bits differ. We will swap them by flipping their values.
        # Select the bits to flip with bit_mask. Since x^1 = 0 when x = 1 and 1
        # when x = 0, we can perform the flip XOR.
        bit_mask = (1 << i) | (1 << j)
        x ^= bit_mask
    return x;



def reverse_x(x, n):
    left ,right = 0, n;
    while(left < right):
            x = swap_bits(x,left, right);
            left += 1;
            right -= 1;
    return x;


PRECOMPUTED_REVERSE  = [reverse_x(x, 15) for x in range(1 << 16)]

# @include
def reverse_bits(x):
    MASK_SIZE = 16;
    MASK = 0xFFFF;
    return (PRECOMPUTED_REVERSE[ x & MASK] << (3*MASK_SIZE) |
           PRECOMPUTED_REVERSE[ x >> MASK_SIZE & MASK] << (2*MASK_SIZE) |
           PRECOMPUTED_REVERSE[ x >> (MASK_SIZE*2) & MASK] << MASK_SIZE |
           PRECOMPUTED_REVERSE[ x >> (MASK_SIZE*3) & MASK])
# @exclude
def main():
    if len(sys.argv) == 2:
        x = int(sys.argv[1])
        print('x = %#x, reverse x = %#x' % (x, reverse_bits(x)))
        print('%#x' % reverse_x(x, 63))
        assert reverse_bits(x) == reverse_x(x, 63)
    else:
        for _ in range(1000):
            x = random.randint(0, sys.maxsize)
            print('x = %#x, reverse x = %#x' % (x, reverse_bits(x)))
            assert reverse_bits(x) == reverse_x(x, 63)


if __name__ == '__main__':
    main()

    