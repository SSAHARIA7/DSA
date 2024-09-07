#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string str1,str2;
    std::cin>>str1>>str2;
    std::vector<char> key(26);
    bool iso{true};
    for(int i{} ; i<str1.length(); i++){
        if(key.at(str1.at(i) - 'a') == '\0' && key.at(str2.at(i)-'a') == '\0'){
            key.at(str1.at(i)-'a') = str2.at(i);
            key.at(str2.at(i) - 'a') = str1.at(i);
        }else if(key.at(str1.at(i) - 'a') != '\0' && key.at(str2.at(i)-'a') != '\0'){
            if(str2.at(i) != key.at(str1.at(i) - 'a')){
                iso = false;
                break;
            }
        }else{
            iso = false;
            break;
        }
    }
    if(str1.length() != str2.length()){
        iso = false;
    }
    std::cout<<iso;
    return 0;
}