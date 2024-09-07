#include <iostream>
#include <stack>
bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')') return true;
     
     return false;
}

std::string preToInfix(std::string pre_exp) {
        std::stack<std::string> st;
        for(int i{pre_exp.length()-1} ; i>=0 ; i--){
            char c = pre_exp.at(i);
            std::string str = "";
            if(!isOperator(c)){
                str.push_back(c);
                st.push(str);
            }else{
                str = "(" + st.top() + c;
                st.pop();
                str += st.top() + ")";
                st.pop();
                st.push(str);
            }
        }
        return st.top();
    }