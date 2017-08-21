## 0. struct
import collections
Object = collections.namedtuple('Object', ('balanced', 'height'));
C = Object(True, -1);
print(C.balanced, C.height);

## 1.	Class (structure):
class ListNode:
    def __init__(self, data=0, next_node=None):
        self.data = data;
        self.next = next_node;

A = ListNode();

class TreeNode:
    def __init__(self, data = 0, left = None, right = None):
        	self.data = data;
        	self.left = left;
        	self.right = right;

A = TreeNode();


## 2 Array

#int
A = []; A = [1,2,3]; A = range(0,10); A = [0]*10;

# class
A = []; B = ListNode();
A.append(B);
A[-1] == B;
A.pop() == B;


## 3. Stack

# stack
stack = [];
stack.append(B);
assert stack[-1] == B;
stack.pop();

# stack with max
class Stack:
    class cache:
        def __init__(self, _max = -float('inf'), count = 0):
            self.max = _max;
            self.count =  count;
            
    def __init__(self):
        self._element = [];
        self._maxCache =[];
        
    def empty(self):
        return not self._element;
        
        
    def max(self):
        return self._maxCache[-1].max;

    def push(self, x):
        #update elemetn
        self._element.append(x);
        
        #update cache
        #if x larger than maxchache[-1], or maxcheche empty, add 
        if(not self._maxCache or x > self._maxCache[-1].max):
            self._maxCache.append(self.cache(x, 1));
        #if x equal to maxcache[-1].max, cout += 1
        elif(x == self._maxCache[-1].max):
            self._maxCache[-1].count += 1;
        #if x larger than maxchache[-1].max, do nothing
            
        
    def pop(self):
        #update element
        result = self._element.pop();
        
        #update cache
        #if result < maxCache[-1].max, no update
        #if result == ---------------, cout -= 1, if cout == 0, pop it
        if(result == self.max()):
            self._maxCache[-1].count -= 1;
            if(self._maxCache[-1].count == 0):
                self._maxCache.pop();
        
        return result;

## 4. Queue

# queue
class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0,item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

# queue using deque
import collections
queue_ = collections.deque();
queue_.append(B);
queue_[0]; #peek
queue_[-1];#peek end
queue_.popleft;

# queue with max
import collections
class QueueWithMax:

    def __init__(self):
        self._entries = collections.deque()
        self._candidates_for_max = collections.deque()

    def enqueue(self, x):
        self._entries.append(x)
        # Eliminate dominated elements in _candidates_for_max.
        while self._candidates_for_max and self._candidates_for_max[-1] < x:
            self._candidates_for_max.pop()
        self._candidates_for_max.append(x)

    def dequeue(self):
        if self._entries:
            result = self._entries.popleft()
            if result == self._candidates_for_max[0]:
                self._candidates_for_max.popleft()
            return result
        raise IndexError('empty queue')

    def max(self):
        if self._candidates_for_max:
            return self._candidates_for_max[0]
        raise IndexError('empty queue')
      

# 5 hashtable

table = {};
table['key1'] = 1;
table['key2'] = B;
if(table.get('key1') == None): print("No key1");
if(not table): print("table empty");
table.pop('key1');



