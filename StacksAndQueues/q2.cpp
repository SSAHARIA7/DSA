#include <iostream>
#include <stack>



class MinStack {
public:
    std::stack <long long> st;
    long long minVal;
    
    MinStack() {
        
    }
    
    void push(int val) {
        long long pushVal = static_cast <long long> (val); 
        if(st.empty()){
            st.push(pushVal);
            minVal = val;
        }else{

            if(val>=minVal){
                st.push(pushVal);
            }else{
                st.push(static_cast<long long>(2)*pushVal - minVal);
                minVal = pushVal;
            }
        }
    }
    
    void pop() {
        if(st.top() >= minVal){
            st.pop();
        }else{
            minVal = static_cast<long long>(2)*minVal - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top() >= minVal){
            return st.top();
        }else{
            return minVal;
        }
    }
    
    int getMin() {
        return static_cast<int> (minVal);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



int main(){

    return 0;
}