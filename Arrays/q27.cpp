#include <iostream>
#include <vector>



int main(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>>result;
    
    for(int i{} ; i<n ; i++){
         std::vector<int> temp;
         temp.push_back(1);
         int ans{1};
        for(int j{1} ; j<i ; j++){
            ans *= (i-j+1);
            ans /= j;
            temp.push_back(ans);
        }
        if(i!=0)
            temp.push_back(1);
        result.push_back((temp));
    }



    for(int i{} ; i<n ; i++){
        for(int j{}; j<=i ; j++){
            std::cout<<result.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}