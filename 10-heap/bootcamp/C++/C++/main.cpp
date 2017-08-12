//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/11/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

class mycomparison
{
private:
    bool reverse;
public:
    //constructor
    mycomparison(const bool& revparam=false)
    {reverse=revparam;}
    
    //operator
    
    /*
     bool operator()(Person const & p1, Person const & p2) {
         // return "true" if "p1" is ordered before "p2", for example:
         return p1.age < p2.age;
     }
     */
    bool operator() (const int& lhs, const int&rhs) const
    {
        if (reverse) return (lhs>rhs);
        else return (lhs<rhs);
    }
};


/*
 struct CompareAge {
     bool operator()(Person const & p1, Person const & p2) {
         // return "true" if "p1" is ordered before "p2", for example:
         return p1.age < p2.age;
     }
 };
 
 priority_queue<Person, vector<Person>, CompareAge>
 */

int main ()
{
    int myints[]= {10,60,50,20};
    
    std::priority_queue<int> first;
    std::priority_queue<int> second (myints,myints+4);
    std::priority_queue<int, std::vector<int>, std::greater<int> >
    third (myints,myints+4);
    // using mycomparison:
    typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;
    
    mypq_type fourth;                       // less-than comparison
    mypq_type fifth (mycomparison(true));   // greater-than comparison 10 at top
    
    return 0;
}
