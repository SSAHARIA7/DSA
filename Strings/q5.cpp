#include <iostream>
#include <string>
#include <vector>

int main(){
    int n;
    std::cin>>n;
    std::vector<std::string> s(n);
    std::string word1;
    std::string word2;
    for(int i{} ; i<n ;i++){
        std::cin>>s.at(i);
    }
    std::cin>>word1>>word2;
    int indWord1{-1};
    int indWord2{-1};
    int minDist{INT32_MAX};
    for(int i{} ; i<n ; i++){
        if(s.at(i) == word1){
            indWord1 = i;
            if(indWord2 != -1){
                minDist = std::min(minDist,indWord1-indWord2);
            }

        }else if(s.at(i) == word2){
            indWord2 = i;
            if(indWord1 != -1){
                minDist = std::min(minDist,indWord2-indWord1);
            }
        }
    }

    std::cout<<minDist;
    
    return 0;   
}