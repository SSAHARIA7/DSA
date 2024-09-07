#include <iostream>
#include <string>
#include <stack>

int precedenceValue(char c){
    if(c == '^') return 3;
    if(c== '*' || c=='/') return 2;
    if(c == '+' || c == '-') return 1;
    if(c== '(' || c == ')') return 0;
}

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')') return true;
     
     return false;
}

std::string infixToPostfix(std::string s) {
        std::stack <char> st;
        std::string ans;
        //a+b*(c^d-e)^(f+g*h)-i
        for(char c: s){
            if(isOperator(c)){
                if(st.empty()){
                    st.push(c);
                }else{
                    if(precedenceValue(c) > precedenceValue(st.top())  || c == '('){
                        st.push(c);
                    }else{

                        if(c != ')'){
                            while(!st.empty() && precedenceValue(st.top()) >= precedenceValue(c)){
                                ans.push_back(st.top());
                                st.pop();
                            }
                            st.push(c);
                        }else{

                            while(st.top() != '('){
                                ans.push_back(st.top());
                                st.pop();
                            }
                            st.pop();
                        }
                    }
                }
            }else{
                ans.push_back(c);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;

    }


    int main(){
        std::string s = "a+(b-c)*d";
        std::cout<<infixToPostfix(s);
        return 0;
    }