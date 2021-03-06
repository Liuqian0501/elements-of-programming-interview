#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 17 22:29:12 2017

@author: LiuQianKevin
"""
class ListNode:
    def __init__(self, data = 0, next_node = None):
        self.data = data;
        self.next = next_node;
        
def reverse_sublist(L, start, end):
    # base case
    if(L == None):
        return None;
    

    dummyHead = subList_head = ListNode(0, L);
    
    #1 find the privious node of start, define as pre, node at start as tail
    for _ in range(1, start):
        subList_head = subList_head.next;
    tail = subList_head.next;
    #2 delete the node behide tail and put it behind pre
    for _ in range(0, end - start):
        temp = tail.next;
        tail.next = temp.next;
        temp.next = subList_head.next
        subList_head.next = temp;

    return dummyHead.next; 
    #3 keep doing 2 until put end behind pre
    
    
    
        

def simple_test():
    L = None
    result = reverse_sublist(L, 0, 0)
    assert result is None

    L = ListNode(1, None)
    result = reverse_sublist(L, 0, 0)
    assert result is L and result.next is None

    L = ListNode(1, ListNode(2, ListNode(3, None)))
    result = reverse_sublist(L, 0, 1)
    assert result.data == 2 and result.next.data == 1 and result.next.next.data == 3 and result.next.next.next is None

    L = ListNode(1, ListNode(2, ListNode(3, None)))
    result = reverse_sublist(L, 0, 2)
    assert result.data == 3 and result.next.data == 2 and result.next.next.data == 1 and result.next.next.next is None


def main():
    simple_test()
    L = ListNode(1, ListNode(2, ListNode(3, None)))
    result = reverse_sublist(L, 3, 3)
    assert (result.data == 1 and result.next.data == 2 and
            result.next.next.data == 3 and not result.next.next.next)
    while result:
        print(result.data)
        result = result.next

    result = reverse_sublist(L, 2, 3)
    assert (result.data == 1 and result.next.data == 3 and
            result.next.next.data == 2 and not result.next.next.next)
    while result:
        print(result.data)
        result = result.next

    L = ListNode(3, ListNode(5, None))
    result = reverse_sublist(L, 1, 2)
    assert result.data == 5 and result.next.data == 3 and not result.next.next
    while result:
        print(result.data)
        result = result.next


if __name__ == '__main__':
    main()
