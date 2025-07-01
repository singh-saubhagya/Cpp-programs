#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> a, b;
public:
    MyQueue() {}
  
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        int z = b.top();
        b.pop();
        return z;
    }
    
    int peek() {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};
