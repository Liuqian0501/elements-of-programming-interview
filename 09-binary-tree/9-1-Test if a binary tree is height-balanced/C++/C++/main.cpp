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
#include <queue>
#include <memory>
#include <utility>

#include "./binary_tree_prototype.cpp"

using std::boolalpha;
using std::cout;
using std::endl;
using std::max;
using std::pair;
using std::tie;
using std::unique_ptr;
using std::queue;

namespace backtracking {
    struct BalancedStatusWithHeight;
    BalancedStatusWithHeight CheckBalanced(
                                           const unique_ptr<BinaryTreeNode<int>>&);
    
    // @include
    struct BalancedStatusWithHeight {
        bool balanced;
        int height;
    };
    
    bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
        return CheckBalanced(tree).balanced;
    }
    
    // First value of the return value indicates if tree is balanced, and if
    // balanced the second value of the return value is the height of tree.
    BalancedStatusWithHeight CheckBalanced(
                                           const unique_ptr<BinaryTreeNode<int>>& tree) {
        if (tree == nullptr) {
            return {true, -1};  // Base case.
        }
        
        auto left_result = CheckBalanced(tree->left);
        if (!left_result.balanced) {
            return {false, 0};  // Left subtree is not balanced.
        }
        auto right_result = CheckBalanced(tree->right);
        if (!right_result.balanced) {
            return {false, 0};  // Right subtree is not balanced.
        }
        
        bool is_balanced = abs(left_result.height - right_result.height) == 0;
//        bool is_balanced = abs(left_result.height - right_result.height) <= 1;
        int height = max(left_result.height, right_result.height) + 1;
        return {is_balanced, height};
    }
    // @exclude
}

namespace BFS {
    //this method only check whether the tree is full
    bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
        queue<BinaryTreeNode<int>*> queue_;
        queue_.push(tree.get());
        int expected = 1, kScaleFactor = 2;
        
        while(!queue_.empty() && queue_.size() == expected){
            queue<BinaryTreeNode<int>*> subqueue_;
            while(!queue_.empty()){
                auto front = queue_.front();
                if(front->left != nullptr){
                    subqueue_.push(front->left.get());
                }
                if(front->right != nullptr){
                    subqueue_.push(front->right.get());
                }
                queue_.pop();
            }
            expected *= kScaleFactor;
            queue_ = subqueue_;
        }
        return queue_.empty();
    }
}



int main(int argc, char* argv[]) {
    //  balanced binary tree test
    //      3
    //    2   5
    //  1    4 6
    unique_ptr<BinaryTreeNode<int>> tree =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->right->right =
    make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(backtracking::IsBalanced(tree) == false);
    cout << boolalpha << backtracking::IsBalanced(tree) << endl;
    assert(BFS::IsBalanced(tree) == false);
    cout << boolalpha << BFS::IsBalanced(tree) << endl;
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(backtracking::IsBalanced(tree) == true);
    cout << boolalpha << backtracking::IsBalanced(tree) << endl;
    assert(BFS::IsBalanced(tree) == true);
    cout << boolalpha << BFS::IsBalanced(tree) << endl;

    // Non-balanced binary tree test.
    tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    assert(backtracking::IsBalanced(tree) == false);
    cout << boolalpha << backtracking::IsBalanced(tree) << endl;
    assert(BFS::IsBalanced(tree) == false);
    cout << boolalpha << BFS::IsBalanced(tree) << endl;

    return 0;
}
