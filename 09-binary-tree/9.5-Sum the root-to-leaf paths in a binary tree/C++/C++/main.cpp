//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/11/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

#include "./binary_tree_prototype.h"

using std::cout;
using std::endl;
using std::equal;
using std::unique_ptr;

int Helper(const unique_ptr<BinaryTreeNode<int>>& tree, int x);
// @include
int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {
    //the output of node is depend on itself and depth, privious sum needs to go the next level;
    return Helper(tree, 0);
}

int Helper(const unique_ptr<BinaryTreeNode<int>>& tree, int x){
    x = x*2 + tree->data;
    
    if(tree->left == nullptr && tree->right == nullptr){
        return x;
    }
    
    int leftSum = tree->left == nullptr ? 0 : Helper(tree->left, x);
    int rightSum = tree->right == nullptr ? 0 : Helper(tree->right, x);
    return leftSum+rightSum;
    
};
// @exclude

int main(int argc, char** argv) {
    //      1
    //    1   0
    //  0    1 0
    unique_ptr<BinaryTreeNode<int>> root = make_unique<BinaryTreeNode<int>>(
                                                                            BinaryTreeNode<int>{1, nullptr, nullptr});
    assert(SumRootToLeaf(root) == 1);
    root->left = make_unique<BinaryTreeNode<int>>(
                                                  BinaryTreeNode<int>{1, nullptr, nullptr});
    assert(SumRootToLeaf(root) == 3);
    root->left->left = make_unique<BinaryTreeNode<int>>(
                                                        BinaryTreeNode<int>{0, nullptr, nullptr});
    assert(SumRootToLeaf(root) == 6);
    root->right = make_unique<BinaryTreeNode<int>>(
                                                   BinaryTreeNode<int>{0, nullptr, nullptr});
    assert(SumRootToLeaf(root) == 8);
    root->right->left = make_unique<BinaryTreeNode<int>>(
                                                         BinaryTreeNode<int>{1, nullptr, nullptr});
    assert(SumRootToLeaf(root) == 11);
    root->right->right = make_unique<BinaryTreeNode<int>>(
                                                          BinaryTreeNode<int>{0, nullptr, nullptr});
    assert(SumRootToLeaf(root) == 15);
    return 0;
}
