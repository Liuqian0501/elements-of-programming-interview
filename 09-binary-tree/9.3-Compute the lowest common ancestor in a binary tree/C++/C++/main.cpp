//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/11/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <memory>

#include "./binary_tree_prototype.cpp"

using std::cout;
using std::endl;
using std::unique_ptr;

// @include
struct NodeWithCount{
    int count;
    BinaryTreeNode<int>* node;
};
NodeWithCount LCAHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1){
    // if tree is nullptr return it
    // otherwise return nodecount
    if(tree == nullptr) return {0,nullptr};

    auto leftNode = LCAHelper(tree->left, node0, node1);
    if(leftNode.count == 2) return leftNode;
    auto rightNode = LCAHelper(tree->right, node0, node1);
    if(rightNode.count == 2) return rightNode;
    
    int count = leftNode.count + rightNode.count + (tree == node0) + (tree == node1);
    return {count, tree.get()};
}

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
    //result depend on children node only
    auto nodewithcount = LCAHelper(tree, node0,node1);
    return nodewithcount.count == 2 ? nodewithcount.node : nullptr;
}




// @exclude

int main(int argc, char* argv[]) {
    //      3
    //    2   5
    //  1    4 6
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(
                                                                            BinaryTreeNode<int>{3, nullptr, nullptr});
    tree->left = make_unique<BinaryTreeNode<int>>(
                                                  BinaryTreeNode<int>{2, nullptr, nullptr});
    tree->left->left = make_unique<BinaryTreeNode<int>>(
                                                        BinaryTreeNode<int>{1, nullptr, nullptr});
    tree->right = make_unique<BinaryTreeNode<int>>(
                                                   BinaryTreeNode<int>{5, nullptr, nullptr});
    tree->right->left = make_unique<BinaryTreeNode<int>>(
                                                         BinaryTreeNode<int>{4, nullptr, nullptr});
    tree->right->right = make_unique<BinaryTreeNode<int>>(
                                                          BinaryTreeNode<int>{6, nullptr, nullptr});
    // should output 3
    auto* x = LCA(tree, tree->left, tree->right);
    assert(x->data == 3);
    cout << x->data << endl;
    // should output 5
    x = LCA(tree, tree->right->left, tree->right->right);
    assert(x->data == 5);
    cout << x->data << endl;
    // should output 5
    x = LCA(tree, tree->right, tree->right->right);
    assert(x->data == 5);
    cout << x->data << endl;
    // should output 3
    x = LCA(tree, tree->left->left, tree->right->right);
    assert(x->data == 3);
    cout << x->data << endl;
    // should output 3
    x = LCA(tree, tree->left->left, tree);
    assert(x->data == 3);
    cout << x->data << endl;
    // should output 2
    x = LCA(tree, tree->left, tree->left);
    assert(x->data == 2);
    cout << x->data << endl;
    return 0;
}
