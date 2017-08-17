# -*- coding: utf-8 -*-
"""
Spyder Editor

@author: LiuQianKevin
"""
import sys
import random

# don't use carry if you don't have to
# @include
def plus_one(A):
    index = len(A) - 1;
    A[index] += 1;
    while(index > 0 and A[index] > 9):
        A[index - 1] += A[index]/10;
        A[index] %= 10;
        index -= 1;
    
    if(A[0] > 9):
        A[0] = 0;
        A.insert(0, 1);
    return A;
# @exclude


def rand_vector(length):
    if not length:
        return [0]
    return [random.randint(1, 9)] + [random.randint(0, 9)
                                     for _ in range(length - 1)]


def small_test():
    result = plus_one([9, 9])
    assert result == [1, 0, 0]
    result = plus_one([3, 1, 4])
    assert result == [3, 1, 5]


def main():
    small_test()
    n = int(sys.argv[1]) if len(sys.argv) == 2 else random.randint(0, 1000)
    A = rand_vector(n)
    print()
    print(*A, sep='')
    result = plus_one(A)
    print(*result, sep='')
    print()
    print(*result)
    print()
    print(result)


if __name__ == '__main__':
    main()
