//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/9/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cassert>

using std::stack;
using std::make_shared;
using std::shared_ptr;

struct PostingListNode {
    int order;
    shared_ptr<PostingListNode> next;
    shared_ptr<PostingListNode> jump;
};

using std::make_shared;
using std::shared_ptr;

namespace recursion {
    void SetJumpOrderHelper(const shared_ptr<PostingListNode>& L, int* order);
    
    // @include
    void SetJumpOrder(const shared_ptr<PostingListNode>& L) {
        SetJumpOrderHelper(L, new int(0));
    }
    
    void SetJumpOrderHelper(const shared_ptr<PostingListNode>& L, int* order) {
        if (L && L->order == -1) {
            L->order = (*order)++;
            SetJumpOrderHelper(L->jump, order);
            SetJumpOrderHelper(L->next, order);
        }
    }
    // @exclude
}

namespace stack_iteration {
    // @include
    void SetJumpOrder(const shared_ptr<PostingListNode>& L) {
        stack<shared_ptr<PostingListNode>> s;
        int order = 0;
        s.emplace(L);
        while (!s.empty()) {
            auto curr = s.top();
            s.pop();
            if (curr && curr->order == -1) {
                curr->order = order++;
                // Stack is last-in, first-out, and we want to process
                // the jump node first, so push next, then push jump.
                s.emplace(curr->next);
                s.emplace(curr->jump);
            }
        }
    }
    // @exclude
}

int main(int argc, char* argv[]) {
    shared_ptr<PostingListNode> L = nullptr, curr;
    curr = L;
    // build a linked list L->1->2->3->4->5->nullptr
    for (size_t i = 0; i < 5; ++i) {
        shared_ptr<PostingListNode> temp =
        make_shared<PostingListNode>(PostingListNode{-1, nullptr, nullptr});
        if (curr) {
            curr->next = temp;
            curr = temp;
        } else {
            curr = L = temp;
        }
    }
    L->jump = nullptr;  // no jump from 1
    L->next->jump = L->next->next->next;  // 2's jump points to 4
    L->next->next->jump = L;  // 3's jump points to 1
    L->next->next->next->jump = nullptr;  // no jump from 4
    L->next->next->next->next->jump =
    L->next->next->next->next;  // 5's jump points to 5
    shared_ptr<PostingListNode> temp = L;
    //recursion::SetJumpOrder(L);
    stack_iteration::SetJumpOrder(L);
    
    // output the jump-first order, it should be 0, 1, 4, 2, 3
    assert(temp->order == 0);
    temp = temp->next;
    assert(temp->order == 1);
    temp = temp->next;
    assert(temp->order == 4);
    temp = temp->next;
    assert(temp->order == 2);
    temp = temp->next;
    assert(temp->order == 3);
    std::cout << "Success" << std::endl;
    return 0;
}
