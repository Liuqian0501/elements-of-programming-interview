//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/11/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

#include "./Binary_tree_with_parent_prototype.h"

using std::cout;
using std::endl;
using std::swap;
using std::unique_ptr;

int GetLen(const BinaryTreeNode<int>* ptr);
// @include
BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& node_0,
                         const unique_ptr<BinaryTreeNode<int>>& node_1) {
    //Same as overlapped list, need same len
    // to manipulate nuique_ptr, use new pointer
    BinaryTreeNode<int>* iter_0 = node_0.get();
    BinaryTreeNode<int>* iter_1 = node_1.get();
    int len0 = GetLen(iter_0), len1 = GetLen(iter_1);
    
    //swap so as to manipulate the longer
    if(len0 < len1) swap(iter_0, iter_1);
    for(int i = 0; i < abs(len1 - len0); i++){
        iter_0 = iter_0->parent;
    }
    
    while(iter_0 != iter_1){
        iter_0 = iter_0->parent;
        iter_1 = iter_1->parent;
    }
    return iter_0;
}
int GetLen(const BinaryTreeNode<int>* ptr){
    int result = 0;
    while(ptr != nullptr){
        ptr = ptr->parent;
        result++;
    }
    return result;
};
// @exclude

int main(int argc, char* argv[]) {
    //      3
    //    2   5
    //  1    4 6
    auto root = make_unique<BinaryTreeNode<int>>(
                                                 BinaryTreeNode<int>{3, nullptr, nullptr, nullptr});
    root->left = make_unique<BinaryTreeNode<int>>(
                                                  BinaryTreeNode<int>{2, nullptr, nullptr, root.get()});
    root->left->left = make_unique<BinaryTreeNode<int>>(
                                                        BinaryTreeNode<int>{1, nullptr, nullptr, root->left.get()});
    root->right = make_unique<BinaryTreeNode<int>>(
                                                   BinaryTreeNode<int>{5, nullptr, nullptr, root.get()});
    root->right->left = make_unique<BinaryTreeNode<int>>(
                                                         BinaryTreeNode<int>{4, nullptr, nullptr, root->right.get()});
    root->right->right = make_unique<BinaryTreeNode<int>>(
                                                          BinaryTreeNode<int>{6, nullptr, nullptr, root->right.get()});
    
    // should output 3
    assert(LCA(root->left, root->right)->data == 3);
    cout << LCA(root->left, root->right)->data << endl;
    // should output 5
    assert(LCA(root->right->left, root->right->right)->data == 5);
    cout << LCA(root->right->left, root->right->right)->data << endl;
    // should output 3
    assert(LCA(root->left, root->right->left)->data == 3);
    cout << LCA(root->left, root->right->left)->data << endl;
    // should output 2
    assert(LCA(root->left, root->left->left)->data == 2);
    cout << LCA(root->left, root->left->left)->data << endl;
    return 0;
}
