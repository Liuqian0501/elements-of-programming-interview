//
//  main.cpp
//  C++
//
//  Created by Qian Liu on 8/8/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include "./linkedList.cpp"

using namespace std;

#ifndef reversesublist_H_
#define reversesublist_H_
namespace reversesublist {
    shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start, int finish){
        /*
         1-2-3-6-5-4 start 3, finish 5 ---> 1-2-3-4-5-6
             H T
        */
        
        //find starting node and subtail
        shared_ptr<ListNode<int>> subhead(new ListNode<int>), subtail(new ListNode<int>), head = L;
        for(int i = 0; i < start; i++){
            subhead = L;
            L = L->next;
        }
        subtail = subhead->next;
        
        //delete tail's next and addd to head's next
        for(int i=start; i<finish;i++){
            //delete tail's next
            auto temp = subtail->next;
            subtail->next = temp->next;
            //add to head's next
            temp->next = subhead->next;
            subhead->next = temp;
        }
        
        return head;
    }
}
#endif

#ifndef unitest_H_
#define unitest_H_
namespace unitest {
    void Test(shared_ptr<ListNode<int>> L, shared_ptr<ListNode<int>> expected, int start, int finish){
        shared_ptr<ListNode<int>> result = reversesublist::ReverseSublist(L, start, finish);
        
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
                                        3, make_shared<ListNode<int>>(ListNode<int>{
                                        6, make_shared<ListNode<int>>(ListNode<int>{
                                        5, make_shared<ListNode<int>>(ListNode<int>{
                                        4, nullptr})})})})})});
    shared_ptr<ListNode<int>> expected = make_shared<ListNode<int>>(ListNode<int>{
                                        1, make_shared<ListNode<int>>(ListNode<int>{
                                        2, make_shared<ListNode<int>>(ListNode<int>{
                                        3, make_shared<ListNode<int>>(ListNode<int>{
                                        4, make_shared<ListNode<int>>(ListNode<int>{
                                        5, make_shared<ListNode<int>>(ListNode<int>{
                                        6, nullptr})})})})})});
    unitest::Test(L1, expected, 3, 5);
    return 0;
}
