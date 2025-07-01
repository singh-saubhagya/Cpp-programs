#include<bits/stdc++.h>
using namespace std;
/*
We have two queue a and b , we are aiming to push and pop from the b queue and maintaing a as to have a behaviour of stack
so when ever i have to add element in the queue , i am going to add it into b only when it is empty, so that when we have to 
to pop the latest element i can directly do it from b .
But when we have another push operation , b will not remain empty , so now we will copy all the elements of a into b , and then swap b with a ,
now a will have all the elements in a defined order. and b will be empty for storing the latest elements
*/



class MyStack {


    queue<int> a,b;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(b.empty()==false)
        {
            while(a.empty()==false)
            {
                int z=a.front();
                a.pop();
                b.push(z);

            }
            swap(b,a);
            b.push(x);
        }
        else 
        {
            b.push(x);
        }
    }
    
    int pop() {
        int z;
        if(b.empty()==false)
        {
            z=b.front();
            b.pop();
        }
        else
        {
            swap(b,a);
            z=b.front();
            b.pop();
        }
        return z;
    }
    
    int top() {
        int z;
        if(b.empty()==false)
        {
            z=b.front();
           
        }
        else
        {
            swap(b,a);
            z=b.front();
           
        }
        return z;
        
    }
    
    bool empty() {
        if(a.empty()==false || b.empty()==false )
        {
            return false;
        }
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */