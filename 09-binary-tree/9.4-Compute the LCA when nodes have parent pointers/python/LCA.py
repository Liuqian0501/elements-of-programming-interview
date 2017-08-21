#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 18 17:14:59 2017

@author: LiuQianKevin
"""
import collections

class BinaryTreeNode:
    def __init__(self, data = 0, left = None, right = None):
        self.data = data;
        self.left = left;
        self.right = right;

# @include
def lca(root, node1, node2):    
    def Help(node, node1, node2):
        Status = collections.namedtuple('Status', ('count', 'node'));
        #base case
        if(not node):
            return Status(0, None);
        #countL node1 and node2 in left child, if count = 2, return node. need {2,node}
        left = Help(node.left, node1, node2);
        if(left.count == 2): return left;
        #countR node1 and node2 in right child
        right = Help(node.right, node1, node2);
        if(right.count == 2): return right;
        
        #return count = countL + coutR + int(currentNode in (node1, node2)) 
        count = left.count + right.count + int(node in (node1, node2));
        return Status(count, node);
    
    result = Help(root, node1, node2);
    if(result.count == 2): return result.node;
    else: return None; 
# @exclude    

def main():
    #      3
    #    2   5
    #  1    4 6
    tree = BinaryTreeNode(3)
    tree.left = BinaryTreeNode(2)
    tree.left.left = BinaryTreeNode(1)
    tree.right = BinaryTreeNode(5)
    tree.right.left = BinaryTreeNode(4)
    tree.right.right = BinaryTreeNode(6)
    # should output 3
    x = lca(tree, tree.left, tree.right)
    assert x.data == 3
    print(x.data)
    # should output 5
    x = lca(tree, tree.right.left, tree.right.right)
    assert x.data == 5
    print(x.data)
    # should output 5
    x = lca(tree, tree.right, tree.right.right)
    assert x.data == 5
    print(x.data)
    # should output 3
    x = lca(tree, tree, tree.left.left)
    assert x.data == 3
    print(x.data)
    # should output 2
    x = lca(tree, tree.left, tree.left.left)
    assert x.data == 2
    print(x.data)


if __name__ == '__main__':
    main()
