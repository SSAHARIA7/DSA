#include <iostream>
#include <string>
#include<algorithm>

int main(){
    std::string str;
    getline(std::cin,str);

    std::reverse(str.begin(),str.end());
    int start {};
    for(int i{} ; i<str.length() ; i++){
        if(str.at(i) == '.'){
            std::reverse(str.begin() + start ,str.begin() + i);
            start = i+1;
        }
    }
    std::reverse(str.begin() + start, str.end());

    std::cout<<str<<std::endl;
    return 0;   
}