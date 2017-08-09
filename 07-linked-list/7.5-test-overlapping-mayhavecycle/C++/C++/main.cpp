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

#ifndef overlapping_with_cycle_list_h_
#define overlapping_with_cycle_list_h_
namespace overlapping_with_cycle_list {
    void shrink(shared_ptr<ListNode<int >>& L, int len){
        for(int i = 0; i < len; i++){
            L = L->next;
        }
    }
    
    shared_ptr<ListNode<int>> OverlappingNoCycleList(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2){
        //base case
        if(!L1 || !L2) return nullptr;
        
        //need len1 and len2 to find the longer list.
        int len1 = 0, len2 = 0;
        shared_ptr<ListNode<int>> temp1 = L1, temp2 = L2;
        while(temp1 || temp2){
            if(temp1){
                len1++;
                temp1 = temp1->next;
            }
            if(temp2){
                len2++;
                temp2 = temp2->next;
            }
        }
        
        //make sure two list are same length
        if(len1>len2){
            shrink(L1, len1-len2);
        }else{
            shrink(L2, len2-len1);
        }
        
        //find the overlapping root node
        while(L1 != L2){
            L1 = L1->next;
            L2 = L2->next;
        }
        return L1;
    }
    
    shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>> head){

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

    
    int Distance(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2){
        int result = 0;
        while(L1 != L2){
            L1 = L1->next;
            result++;
        }
        return result;
    }
    
    shared_ptr<ListNode<int>> OverlappingWithCycleList(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2){
        /*
         case study:
                case 1: both cycle, share cycle;
                case 2: one with cycle, one no
                case 3: both no cycle
         
         Test 1
         1->2->3->4->5->6
               /     \  |
         7->8->       <-
         */
        
        shared_ptr<ListNode<int>> root1 = HasCycle(L1), root2 = HasCycle(L2);

        //case 1
        if(root1 && root2){
            //if share cycle, root1 and root2 must be in same cycle
            auto temp = root1->next;
            while(temp != root2 && temp != root1){
                temp = temp->next;
            }
            if(temp != root2){
            //not in same cycle
                return nullptr;
            }else{
            //in same cycle,
                if(root1 != root2){
                // roots are different, overlapping in cycle
                    return root1;
                }else{
                // overlapping before root.
                    //need distance to root
                    int len1 = Distance(L1, root1), len2 = Distance(L2,root2);
                    //make sure two list are same length
                    if(len1>len2){
                        shrink(L1, len1-len2);
                    }else{
                        shrink(L2, len2-len1);
                    }
                    //find the overlapping root node
                    while(L1 != L2){
                        L1 = L1->next;
                        L2 = L2->next;
                    }
                    return L1;
                }
            }
        }else if(!root1 && !root2){
            return OverlappingNoCycleList(L1,L2);
        }else{
            return nullptr;
        }
    }
}
#endif

#ifndef unitest_h_
#define unitest_h_
namespace unitest {
    
    void Test(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2, shared_ptr<ListNode<int>> e){
        shared_ptr<ListNode<int>> result = overlapping_with_cycle_list::OverlappingWithCycleList(L1, L2);
        if(result == e){
            cout << "Success!"<<endl;
        }else{
            cout << "Keep calm and enjoy coding"<< endl;
        }
        
    }
}
#endif

int main(int argc, const char * argv[]) {
    /*
     Test 1
     1->2->3->4->5->6
           /     \  |
     7->8->       <-
     */
    shared_ptr<ListNode<int>> L6 = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});
    shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{5,L6});
    shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{4,L5});
    shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,L4});
    shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,L3});
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,L2});
    shared_ptr<ListNode<int>> L8 = make_shared<ListNode<int>>(ListNode<int>{8,L3});
    shared_ptr<ListNode<int>> L7 = make_shared<ListNode<int>>(ListNode<int>{7,L8});
    L6->next = L5;
    shared_ptr<ListNode<int>> expected = L3;
    cout << "Test 1: ";
    unitest::Test(L1, L7, expected);
    
    /*
    Test 2
     
        /----------\
    1->2->3->4->5->6
          /
    7->8->
    */
    L6->next = L2;
    expected = L2;
    cout << "Test 2: ";
    unitest::Test(L1, L7, expected);
    return 0;
}
