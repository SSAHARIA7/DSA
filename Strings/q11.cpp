#include <iostream>
#include <string>
#include <vector>
int main(){
    std::string str;
    getline(std::cin,str);
    std::vector <int> frequencies(26);
    bool panagram{true};
    for(char c: str){
        if(std::isalpha(c)){
            frequencies.at(std::tolower(c)-'a')++;
        }
    }
    for(int i: frequencies){
        if(i==0){
            panagram = false;
        }
    }
    std::cout<<panagram;

    return 0;   
}