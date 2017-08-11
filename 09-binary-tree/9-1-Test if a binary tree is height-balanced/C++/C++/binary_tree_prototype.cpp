// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#ifndef SOLUTIONS_CPP_BINARY_TREE_PROTOTYPE_H_
#define SOLUTIONS_CPP_BINARY_TREE_PROTOTYPE_H_

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
};
// @exclude
#endif  // SOLUTIONS_CPP_BINARY_TREE_PROTOTYPE_H_


