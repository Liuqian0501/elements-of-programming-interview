#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 17 23:58:36 2017

@author: LiuQianKevin
"""
class ListNode:
    def __init__(self, data = 0, next_node = None):
        self.data = data;
        self.next = next_node;
        
        
def has_cycle(L):
    #base case
    if(not L): return None;
    
    #find the start of the cycle using the length
    slow = fast = L;
    while(slow.next and fast.next and fast.next.next):
        slow = slow.next;
        fast = fast.next.next;
        if(slow == fast):
            #find the length of the cycle
            len = 1;
            while(slow.next != fast):
                slow = slow.next;
                len += 1;
                
            #use slow node and fast node to find a node in cycle, 
            slow = fast = L;
            for _ in range(0, len):
                slow = slow.next;
            while(fast != slow):
                fast = fast.next;
                slow = slow.next;
            return slow;
    return None;

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
    
def find_length(L1, root):
    i = 1;
    while(L1 != root):
        L1 = L1.next;
        i += 1;
    return i;

def shink(L, len):
    for _ in range(0, len):
        L = L.next;
    return L;

def overlapping_lists(L1, L2):
    #case study:
    #   L1 and L2 have cycle
    #       case 1: different cycles -- return None
    #       case 2: some cycles
    #               case a: overlapping before cycle -- use overlapping without cycle
    #               case b: overlapping in cycle   -- return either root is ok
    #   one of L1 and L2 have cycle -- return None
    #   none of them have cycle  -- use overlapping without cycle
    root1, root2 = has_cycle(L1), has_cycle(L2);
    
    if((root1 and not root2) or (root2 and not root1)):
        return None
    
    if(not root1 and not root2):
        return overlapping_no_cycle_lists(L1, L2);
    
    #check whether same cycle
    temp = root1;
    while(temp.next != root1 and temp.next != root2):
        temp = temp.next;
    if(temp.next == root1 and root1 != root2):
        return None;
    else:
        #in same cycle
        if(root1 != root2):
            return root1;
        else:
            len1, len2 = find_length(L1, root1), find_length(L2, root2);
            if(len1 > len2):
                L1 = shink(L1, len1 - len2);
            else:
                L2 = shink(L2, len2 - len1);
            while(L1 != L2):
                L1 = L1.next;
                L2 = L2.next;
            return L1;
    

def small_test():
    # L1: 1->2->3->4->5->6-
    #              ^  ^    |
    #              |  |____|
    # L2: 7->8-----
    L1 = ListNode(1,
                  ListNode(2,
                           ListNode(3,
                                    ListNode(4, ListNode(5, ListNode(6,
                                                                     None))))))
    L1.next.next.next.next.next.next = L1.next.next.next.next

    L2 = ListNode(7, ListNode(8, None))
    L2.next.next = L1.next.next.next
    assert overlapping_lists(L1, L2).data == 4

    # L1: 1->2->3->4->5->6-
    #           ^     ^    |
    #           |     |____|
    # L2: 7->8---
    L2.next.next = L1.next.next
    assert overlapping_lists(L1, L2).data == 3


def main():
    small_test()
    # L1: 1->2->3->null
    L1 = ListNode(1, ListNode(2, ListNode(3, None)))
    L2 = L1.next.next
    assert overlapping_lists(L1, L2).data == 3
    # L2: 4->5->null
    L2 = ListNode(4, ListNode(5, None))
    assert not overlapping_lists(L1, L2)
    L1.next.next.next = L1
    assert not overlapping_lists(L1, L2)
    L2.next.next = L2
    assert not overlapping_lists(L1, L2)
    L2.next.next = L1
    assert overlapping_lists(L1, L2)


if __name__ == '__main__':
    main()
