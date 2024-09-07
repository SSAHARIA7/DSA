#include <iostream>
#include <stack>
#include <algorithm>

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')') return true;
     
     return false;
}
std::string postToPre(std::string pre_exp) {

    std::stack<std::string> st;
    for(int i{} ; i<pre_exp.length() ; i++){
        char c= pre_exp.at(i);
        std::string str = "";
        if(!isOperator(c)){
            str.push_back(c);
            st.push(str);
        }else{
            
            std::string str1 = st.top();
            st.pop();
            std::string str2 = st.top();
            st.pop();
            str = c+str2+str1;
            st.push(str);
        }
    }

    return st.top();
}

int main(){
    std::cout<<postToPre("ABC/-AK/L-*");
    return 0;
}