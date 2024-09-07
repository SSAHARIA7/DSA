#include<iostream>
#include<vector>

void allCombos(int n,int missAllowed , std::vector<std::vector<int>> &combos,std::vector<int> &subset){
    if(n==0 || subset.size() == n-missAllowed){
        if(subset.size() == n-missAllowed){
            combos.push_back(subset);
        }
        return;
    }   
    
    subset.push_back(n);
    allCombos(n-1,missAllowed,combos,subset);
    if(missAllowed!=0){
        missAllowed--;
        subset.pop_back();
        allCombos(n-1,missAllowed,combos,subset);
    }

}


int main(){
    int n =4;
    int k = 3;
    std::vector<int> sub;
    std::vector<std::vector<int>> allCombinations;
    allCombos(n,n-k,allCombinations,sub);

    for(auto v: allCombinations){
        for(int i: v){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }


    return 0;
}