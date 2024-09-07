#include <iostream>
#include <vector>
#include <algorithm>

void generateAllPermutations(std::string str,int start,std::vector<std::string> &ans){

    if(start>=str.length()){
        ans.push_back(str);
    }


    for(int i{start} ; i<str.length() ; i++){
        std::swap(str.at(start),str.at(i));
        generateAllPermutations(str,start+1,ans);
        std::swap(str.at(start),str.at(i)); //backtracking
    }
}



int main(){
    
    std::string s = "abcd";
    std::vector<std::string> permutations;
    generateAllPermutations(s,0,permutations);
    std::sort(permutations.begin(),permutations.end());
    for(auto s : permutations){
        std::cout<<s<<std::endl;
    }
    return 0;
}