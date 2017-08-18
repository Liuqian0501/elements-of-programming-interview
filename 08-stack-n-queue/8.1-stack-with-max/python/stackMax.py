#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 18 10:08:25 2017

@author: LiuQianKevin
"""
class Stack:
    class cache:
        def __init__(self, _max = -float('inf'), count = 0):
            self.max = _max;
            self.count =  count;
            
    def __init__(self):
        self._element = [];
        self._maxCache =[];
        
    def push(self, x):
        
        #update elemetn
        self._element.append(x);
        
        #update cache
        #if x larger than maxchache[-1], or maxcheche empty, add 
        if(not self._maxCache or x > self._maxCache[-1].max):
            self._maxCache.append(self.cache(x, 1));
        #if x equal to maxcache[-1].max, cout += 1
        elif(x == self._maxCache[-1].max):
            self._maxCache[-1].count += 1;
        #if x larger than maxchache[-1].max, do nothing
            
        
    def pop(self):
        #update element
        result = self._element.pop();
        
        #update cache
        #if result < maxCache[-1].max, no update
        #if result == ---------------, cout -= 1, if cout == 0, pop it
        if(result == self.max()):
            self._maxCache[-1].count -= 1;
            if(self._maxCache[-1].count == 0):
                self._maxCache.pop();
        
        return result;
        
        
    def empty(self):
        return not self._element;
        
        
    def max(self):
        return self._maxCache[-1].max;
        

def main():
    s = Stack()
    s.push(1)
    s.push(2)
    assert s.max() == 2
    print(s.max())  # 2
    print(s.pop())  # 2
    assert s.max() == 1
    print(s.max())  # 1
    s.push(3)
    s.push(2)
    assert s.max() == 3
    print(s.max())  # 3
    s.pop()
    assert s.max() == 3
    print(s.max())  # 3
    s.pop()
    assert s.max() == 1
    print(s.max())  # 1
    s.pop()
    try:
        s.max()
        s.pop()
        s.pop()
        s.pop()
        s.pop()
    except IndexError as e:
        print(e)


if __name__ == '__main__':
    main()