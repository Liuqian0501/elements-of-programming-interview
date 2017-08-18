#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 17 23:22:43 2017

@author: LiuQianKevin
"""
class ListNode:
    def __init__(self,data = 0, next_node = None):
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

def main():
    L3 = ListNode(3, None)
    L2 = ListNode(2, L3)
    L1 = ListNode(1, L2)

    # Should output 'L1 does not have cycle.'
    assert has_cycle(L1) is None
    print('L1', 'has' if has_cycle(L1) else 'does not have', 'cycle.')

    # Make it a cycle
    L3.next = L2
    # Should output 'L1 has cycle, at node has value 2'
    assert has_cycle(L1) is not None
    assert has_cycle(L1).data == 2
    temp = has_cycle(L1)
    if temp:
        print('L1 has cycle, at node has value', temp.data)
    else:
        print('L1 does not have cycle')


if __name__ == '__main__':
    main()
