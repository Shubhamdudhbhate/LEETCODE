#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


class MinStack {
public:

    stack<pair<int , int >>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }else{

            int minVal = min(val, s.top().second);
            s.push({val,minVal});
        }
        
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
  
};


class MinStacks {
private:
    stack<long long> s;
    long long minVal;  // stores current minimum

public:
    MinStacks() {
        // constructor initializes empty stack
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                // encode value to track previous minVal
                long long encoded = (long long)2 * val - minVal;
                s.push(encoded);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        long long top = s.top();
        s.pop();

        if (top < minVal) {
            // this was an encoded value, recover previous min
            minVal = 2 * minVal - top;
        }
    }

    int top() {
        long long top = s.top();
        if (top < minVal) {
            // encoded value, actual top is minVal
            return (int)minVal;
        } else {
            return (int)top;
        }
    }

    int getMin() {
        return (int)minVal;
    }
};
