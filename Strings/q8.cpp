#include <iostream>
#include <string>
// (()) ))(
int main(){
    std::string str;
    std::cin>>str;
    int closingBrac{};
    int openingBrac{};
    for(int i{} ; i<str.length(); i++){
        if(str.at(i) == ')'){
            closingBrac++;
        }
    }
    for(int i{} ; i<str.length() ; i++){
        if(str.at(i) == ')'){
            closingBrac--;
        }else if(str.at(i) == '('){
            openingBrac++;
        }

        if(openingBrac==closingBrac){
            std::cout<<i+1;
        }
    }

    return 0;   
}