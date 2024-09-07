#include <iostream>
#include <vector>


bool isPalindrome(std::string str, int start, int end){
    while(start<end){
        if(str.at(start) != str.at(end)){
            return false;
        }
        start++;
        end--;
    }
    return true;
}


void palindromePartitioning(std::string str, std::vector<std::vector<std::string>> &ans,std::vector<std::string> &currentAns, int position , int lastPartition){

    if(position >= str.length()){
        if(lastPartition == str.length()-1){
            ans.push_back(currentAns);
        }
        return;
    }
    //partition at pos
    if(isPalindrome(str,lastPartition+1,position)){
        std::string temp;
        for(int i{lastPartition+1} ; i<=position ; i++){
            temp.push_back(str.at(i));
        }
        currentAns.push_back(temp);
        palindromePartitioning(str,ans,currentAns,position+1,position);
        currentAns.pop_back();
    }
    //no partioning at pos
    palindromePartitioning(str,ans,currentAns,position+1,lastPartition);

}

int main(){
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> currentAns;
    palindromePartitioning("a",ans,currentAns,0,-1);
    for(auto v: ans){
        for(auto s: v){
            std::cout<<s<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}