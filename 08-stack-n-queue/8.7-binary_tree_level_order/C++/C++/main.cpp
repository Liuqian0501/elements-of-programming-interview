//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/10/17.
//  Copyright © 2017 qianliu. All rights reserved.
//


#include <cassert>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "./Binary_tree_prototype.h"

using std::cout;
using std::endl;
using std::equal;
using std::move;
using std::queue;
using std::unique_ptr;
using std::vector;

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// @include
vector<vector<int>> BinaryTreeDepthOrder(
                                         const unique_ptr<BinaryTreeNode<int>>& tree) {
    queue<BinaryTreeNode<int>*> queue1;
    queue1.push(tree.get());
    vector<vector<int>> result;
    
    
    while (!queue1.empty()) {
        vector<int> subVector;
        queue<BinaryTreeNode<int>*> queue2;

        //store queue1's value in vector and children in queue2
        while(!queue1.empty()){
            auto curr = queue1.front();
            subVector.push_back(curr->data);
            
            if(curr->left != nullptr){
                queue2.push(curr->left.get());
            }
            if(curr->right != nullptr){
                queue2.push(curr->right.get());
            }
            queue1.pop();
        }
        result.push_back(subVector);
        //set queue1 = queue2, and do iteration again
        queue1 = queue2;
    }
    
    return result;
    
}
// @exclude

int main(int argc, char* argv[]) {
    //      3
    //    2   5
    //  1    4 6
    // 10
    // 13
    
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(
                                                                            BinaryTreeNode<int>{3, nullptr, nullptr});
    tree->left = make_unique<BinaryTreeNode<int>>(
                                                  BinaryTreeNode<int>{2, nullptr, nullptr});
    tree->left->left = make_unique<BinaryTreeNode<int>>(
                                                        BinaryTreeNode<int>{1, nullptr, nullptr});
    tree->left->left->left = make_unique<BinaryTreeNode<int>>(
                                                              BinaryTreeNode<int>{10, nullptr, nullptr});
    tree->left->left->left->right = make_unique<BinaryTreeNode<int>>(
                                                                     BinaryTreeNode<int>{13, nullptr, nullptr});
    tree->right = make_unique<BinaryTreeNode<int>>(
                                                   BinaryTreeNode<int>{5, nullptr, nullptr});
    tree->right->left = make_unique<BinaryTreeNode<int>>(
                                                         BinaryTreeNode<int>{4, nullptr, nullptr});
    tree->right->right = make_unique<BinaryTreeNode<int>>(
                                                          BinaryTreeNode<int>{6, nullptr, nullptr});
    // should output 3
    //               2 5
    //               1 4 6
    //               10
    //               13
    auto result = BinaryTreeDepthOrder(tree);
    vector<vector<int>> golden_res = {{3}, {2, 5}, {1, 4, 6}, {10}, {13}};
    assert(std::equal(golden_res.begin(), golden_res.end(), result.begin()));
    return 0;
}
