//
//  Binary_tree_with_parent_prototype.cpp
//  C++
//
//  Created by 刘谦 on 8/11/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <memory>

using std::unique_ptr;

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// @include
template <typename T>
struct BinaryTreeNode {
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
    BinaryTreeNode<T>* parent;
};
// @exclude
