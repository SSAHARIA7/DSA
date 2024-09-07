#include <iostream>
#include <string>
#include <stack>
bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')') return true;
     
     return false;
}
 std::string postToInfix(std::string exp) {
        std::stack<std::string> st;

        for(char c: exp){
            if(!isOperator(c)){
                std::string pushStr;
                pushStr.push_back(c);
                st.push(pushStr);
            }else{

                std::string str1 = st.top();
                st.pop();
                std::string str2 = st.top();
                st.pop();
                str1 = '(' + str2 + c + str1 + ')';
                st.push(str1);
            }
        }

        return st.top();
    }



    int main(){
        std::string test = "ab*c+";
        std::cout<<postToInfix(test);
        return 0;
    }