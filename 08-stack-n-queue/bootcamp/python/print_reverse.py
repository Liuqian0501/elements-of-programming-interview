#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 18 09:58:48 2017

@author: LiuQianKevin
"""

class ListNode:
    def __init__(self, data = 0, next_node = None):
        self.data = data;
        self.next = next_node;
      
# @include
def print_linked_list_in_reverse(L):
    #First we store data in list in original order
    a = [];
    while(L):
        a.append(L.data);
        L = L.next;
    #Secont we print the data stroed in reverse orfer
    while(a):
        print(a.pop());
# @exclude

def main():
    print_linked_list_in_reverse(ListNode(1, ListNode(2, ListNode(3, None))))


if __name__ == '__main__':
    main()