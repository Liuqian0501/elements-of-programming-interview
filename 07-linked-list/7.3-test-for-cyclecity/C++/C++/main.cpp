//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/8/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <iostream>
#include "./linkedList.cpp"

using namespace std;

#ifndef test_for_cyclicity_h_
#define test_for_cyclicity_h_
namespace test_for_cyclicity {
    shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head){
        /*
         use fast node and slow node, if fast jump over slow, slow will equal fast in the next step.
         
         Test 1
         
         1->2->3->4->5->6
               ^________/
         
        */
    
        shared_ptr<ListNode<int>> fast = head, slow = head;
        
        //keep running until fast meet slow
        while(fast && fast->next){
            slow = slow->next, fast = fast->next->next;
            
            if(slow == fast){
                //need cycle length to find cycle root
                int cycleLen = 1;
                while(fast->next != slow){
                    cycleLen++;
                    fast = fast->next;
                }
                // find cycle root
                auto firstTemp = head, secondTemp = head;
                while(cycleLen){
                    firstTemp = firstTemp->next;
                    cycleLen--;
                }
                while(firstTemp!=secondTemp){
                    firstTemp = firstTemp->next;
                    secondTemp = secondTemp->next;
                }
                
                return firstTemp;
                
            }
        }
        return nullptr;
    }
}
#endif

#ifndef unitest_h_
#define unitest_h_
namespace unitest {
    void Test(const shared_ptr<ListNode<int>>& head, shared_ptr<ListNode<int>>& expected){
        shared_ptr<ListNode<int>> result = test_for_cyclicity::HasCycle(head);
        if(result == expected){
            cout << "Success!" << endl;
        }else{
            cout << "Keep calm and keep coding" << endl;
        }
    }
}
#endif
int main(int argc, const char * argv[]) {
    // Test 1
    /*
    1->2->3->4->5->6
          ^________/
    */
    shared_ptr<ListNode<int>> L6 = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});
    shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{5,L6});
    shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{4,L5});
    shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,L4});
    shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,L3});
    shared_ptr<ListNode<int>> head = make_shared<ListNode<int>>(ListNode<int>{1,L2});
    L6->next = L3;
    shared_ptr<ListNode<int>> expected = L3;
    cout << "Test 1 ";
    unitest::Test(head, expected);
    
    
    // Test 1
    /*
     1->2->3->4->5->6
              ^_____/
     */
    shared_ptr<ListNode<int>> L6_ = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});
    shared_ptr<ListNode<int>> L5_ = make_shared<ListNode<int>>(ListNode<int>{5,L6_});
    shared_ptr<ListNode<int>> L4_ = make_shared<ListNode<int>>(ListNode<int>{4,L5_});
    shared_ptr<ListNode<int>> L3_ = make_shared<ListNode<int>>(ListNode<int>{3,L4_});
    shared_ptr<ListNode<int>> L2_ = make_shared<ListNode<int>>(ListNode<int>{2,L3_});
    shared_ptr<ListNode<int>> head_ = make_shared<ListNode<int>>(ListNode<int>{1,L2_});
    L6_->next = L4_;
    shared_ptr<ListNode<int>> expected_ = L4_;
    cout << "Test 2 ";
    unitest::Test(head_, expected_);
    return 0;
}
