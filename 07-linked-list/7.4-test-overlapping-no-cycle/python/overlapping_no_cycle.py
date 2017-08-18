#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 17 23:39:34 2017

@author: LiuQianKevin
"""
class ListNode:
    def __init__(self, data = 0, next_node = None):
        self.data = data;
        self.next = next_node;
        
def overlapping_no_cycle_lists(L1, L2):
    #need length of both lists, 
    def find_length(L):
        i = 0;
        while(L):
            L = L.next;
            i += 1;
        return i;
    
    len1, len2 = find_length(L1), find_length(L2);

    #shrink longer list and 
    def shink(L, lenght):
        for _ in range(0, lenght):
            L = L.next;
        return L;
    
    if(len1 > len2):
        L1 = shink(L1, len1 - len2);
    else:
        L2 = shink(L2, len2 - len1);
    
    len1, len2 = find_length(L1), find_length(L2);
    
    #compare l1 and l2 for shorter length
    while(L1 != L2):
        L1 = L1.next;
        L2 = L2.next;
    
    if(L1 == L2):
        return L1;
    else:
        return None;


def main():
    # L1: 1->2->3->None
    L1 = ListNode(1, ListNode(2, ListNode(3, None)))
    L2 = L1.next.next
    assert overlapping_no_cycle_lists(L1, L2).data == 3
    # L2: 4->5->None
    L2 = ListNode(4, ListNode(5, None))
    assert not overlapping_no_cycle_lists(L1, L2)


if __name__ == '__main__':
    main()
