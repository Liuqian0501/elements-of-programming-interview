//
//  main.cpp
//  C++
//
//  Created by 刘谦 on 8/16/17.
//  Copyright © 2017 qianliu. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::list;
using std::pair;
using std::unordered_map;

template <size_t capacity>
class LRUCache{
public:
    bool Lookup(int isbn, int* price){
        auto it = isbn_price_table.find(isbn);
        if(it == isbn_price_table.end()){
            return false;
        }
        *price = it->second.second;
        push_top(isbn, it);
        return true;
    }
    
    void Insert(int isbn, int price){
        auto it = isbn_price_table.find(isbn);
        if(it!=isbn_price_table.end()){
            push_top(isbn, it);
        }else{
            if(isbn_price_table.size() == capacity){
            //Erase last newest record
                int endIsbn = priceCache.back();
                isbn_price_table.erase(endIsbn);
                priceCache.pop_back();
            }
            priceCache.push_front(isbn);
            isbn_price_table[isbn] = {priceCache.begin(), price};
        }
    }
    bool Erase(int isbn){
        auto it = isbn_price_table.find(isbn);
        if(it == isbn_price_table.end()){
            return false;
        }else{
            priceCache.erase(it->second.first);
            isbn_price_table.erase(it);
            return true;
        }
    }
private:
    typedef unordered_map<int, pair<list<int>::iterator, int>> Table;
    Table isbn_price_table;
    
    void push_top(int isbn, Table::iterator& it){
        priceCache.erase(it->second.first);
        priceCache.push_front(isbn);
        it->second.first = priceCache.begin();
    }
    list<int> priceCache;
};

int main(int argc, char* argv[]) {
    const int kCapacity = 2;
    {
        LRUCache<kCapacity> c;
        cout << "c.Insert(1, 1)" << endl;
        c.Insert(1, 1);
        cout << "c.Insert(1, 10)" << endl;
        c.Insert(1, 10);
        int val;
        cout << "c.Lookup(2, val)" << endl;
        assert(!c.Lookup(2, &val));
        cout << "c.Lookup(1, val)" << endl;
        assert(c.Lookup(1, &val));
        assert(val == 1);
        c.Erase(1);
        assert(!c.Lookup(1, &val));
    }
    
    // test capacity constraints honored, also FIFO ordering
    {
        LRUCache<kCapacity> c;
        c.Insert(1, 1);
        c.Insert(2, 1);
        c.Insert(3, 1);
        c.Insert(4, 1);
        int val;
        assert(!c.Lookup(1, &val));
        assert(!c.Lookup(2, &val));
        assert(c.Lookup(3, &val));
        assert(val == 1);
        assert(c.Lookup(4, &val));
        assert(val == 1);
    }
    
    // test retrieval moves to front
    {
        LRUCache<kCapacity> c;
        c.Insert(1, 1);
        c.Insert(2, 1);
        c.Insert(3, 1);
        int val;
        c.Lookup(2, &val);
        c.Insert(4, 1);
        assert(!c.Lookup(1, &val));
        assert(c.Lookup(2, &val));
        assert(val == 1);
        assert(!c.Lookup(3, &val));
        assert(c.Lookup(4, &val));
        assert(val == 1);
    }
    
    // test update moves to front
    {
        LRUCache<kCapacity> c;
        c.Insert(1, 1);
        c.Insert(2, 1);
        c.Insert(3, 1);
        c.Insert(2, 2);
        c.Insert(4, 1);
        int val;
        assert(!c.Lookup(1, &val));
        assert(c.Lookup(2, &val));
        assert(val == 1);
        assert(!c.Lookup(3, &val));
        assert(c.Lookup(4, &val));
        assert(val == 1);
    }
    
    // test remove
    {
        LRUCache<kCapacity> c;
        c.Insert(1, 1);
        c.Insert(2, 1);
        c.Erase(2);
        c.Insert(3, 3);
        int val;
        assert(c.Lookup(1, &val));
        assert(val == 1);
        assert(!c.Lookup(2, &val));
        assert(c.Lookup(3, &val));
        assert(val == 3);
    }
    return 0;
}
