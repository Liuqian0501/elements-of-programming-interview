//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/11/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <memory>

#include "./binary_tree_prototype.h"

using std::boolalpha;
using std::cout;
using std::endl;
using std::unique_ptr;


bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>>& left,
                    const unique_ptr<BinaryTreeNode<int>>& right);
// @include
bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
    
    return tree == nullptr ? true : CheckSymmetric(tree->left, tree->right);
}
bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>>& left,
                    const unique_ptr<BinaryTreeNode<int>>& right){
// if left tree and right tree are symmetric, then tree is symmetric
    if(left == nullptr && right == nullptr){
        return true;
    }else if((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr)){
        return false;
    }

    if(!CheckSymmetric(left->left, right->right)) return false;
    if(!CheckSymmetric(left->right, right->left)) return false;
    
    return true;
}


// @exclude

void SimpleTest() {
    auto symm_tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(IsSymmetric(symm_tree));
    symm_tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(!IsSymmetric(symm_tree));
    symm_tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(IsSymmetric(symm_tree));
    symm_tree->right->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(!IsSymmetric(symm_tree));
}

int main(int argc, char* argv[]) {
    SimpleTest();
    // Non symmetric tree test.
    //      x
    //    x   x
    //  x    x x
    auto non_symm_tree =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_symm_tree->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_symm_tree->left->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_symm_tree->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_symm_tree->right->left =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_symm_tree->right->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(!IsSymmetric(non_symm_tree));
    cout << boolalpha << IsSymmetric(non_symm_tree) << endl;
    // Symmetric tree test.
    unique_ptr<BinaryTreeNode<int>> symm_tree =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    symm_tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    symm_tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(IsSymmetric(symm_tree) == true);
    cout << boolalpha << IsSymmetric(symm_tree) << endl;
    // Empty tree test.
    symm_tree = nullptr;
    assert(IsSymmetric(symm_tree) == true);
    cout << boolalpha << IsSymmetric(symm_tree) << endl;
    return 0;
}
