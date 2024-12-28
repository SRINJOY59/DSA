#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;  
    long long mini;       

public:
    MinStack() {
        mini = LLONG_MAX; 
    }
    
    void push(int val) {
        long long value = val;  
        if(st.empty()){
            mini = value;
            st.push(value);      
        }
        else {
            if(value > mini) {
                st.push(value);  
            }
            else {
                st.push(2 * value - mini); 
                mini = value;              
            }
        }
    }
    
    void pop() {
        if(st.empty()) {
            return;
        }
        long long topValue = st.top();
        st.pop();
        if(topValue < mini) {
            mini = 2 * mini - topValue; 
        }
    }
    
    int top() {
        long long topValue = st.top();
        if(topValue < mini) {
            return mini;  
        } else {
            return topValue; 
        }
    }
    
    int getMin() {
        return mini;  
    }
};