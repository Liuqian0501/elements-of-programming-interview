//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/8/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include "./linkedList.cpp"
using std::make_shared;

using namespace std;

#ifndef merge_H_
#define merge_H_
namespace merge {
    void append(shared_ptr<ListNode<int>>& L1, shared_ptr<ListNode<int>>& L2){
        L1->next = L2;
        L1 = L2;//keep update
        L2 = L2->next;
    }
    
    shared_ptr<ListNode<int>> MergeTwoSortedList(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2){
        shared_ptr<ListNode<int>> head(new ListNode<int>);
        auto temp = head;
        

        //append
        while(L1 && L2){
            if(L1->data < L2->data){
                append(temp, L1);
            }else{
                append(temp, L2);
            }
        }
        
        
        //append rest
        if(L1){
            temp->next = L1;
        }else{
            temp->next = L2;
        }
        
        return head->next;
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest {
    void Test(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2, shared_ptr<ListNode<int>> expected){
        
        shared_ptr<ListNode<int>> result = merge::MergeTwoSortedList(L1,L2);
        while(result && expected && result->data == expected->data){
   
            result = result->next;
            expected = expected->next;
        }
        if(!result && !expected){
            cout << "Success" << endl;
        }else{
            cout << "Fail" << endl;
        }
    }
}
#endif

int main(int argc, const char * argv[]) {
    // Test 1
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{
                                    1, make_shared<ListNode<int>>(ListNode<int>{
                                    2, make_shared<ListNode<int>>(ListNode<int>{
                                    3, nullptr})})});

    shared_ptr<ListNode<int>> L1_ = make_shared<ListNode<int>>(ListNode<int>{
                                    1, make_shared<ListNode<int>>(ListNode<int>{
                                    2, make_shared<ListNode<int>>(ListNode<int>{
                                    3, nullptr})})});
    
    shared_ptr<ListNode<int>> expected = make_shared<ListNode<int>>(ListNode<int>{
                                    1, make_shared<ListNode<int>>(ListNode<int>{
                                    1, make_shared<ListNode<int>>(ListNode<int>{
                                    2, make_shared<ListNode<int>>(ListNode<int>{
                                    2, make_shared<ListNode<int>>(ListNode<int>{
                                    3, make_shared<ListNode<int>>(ListNode<int>{
                                    3, nullptr})})})})})});
    unitest::Test(L1, L1_, expected);
    
    return 0;
}
