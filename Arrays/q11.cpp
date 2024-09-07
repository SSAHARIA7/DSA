#include <iostream>
#include <vector>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int oneCounter = 0;
    int maxOnes = 0;
    for(int i{} ; i<n ; i++){
        if(arr.at(i) == 0){
            if(maxOnes < oneCounter){
                maxOnes=oneCounter;
            }
            oneCounter = 0;
        }else{
            oneCounter++;
        }
    }
    if(maxOnes < oneCounter){
                maxOnes=oneCounter;
            }

    std::cout<<"Maximum Consecutive Ones: "<<maxOnes<<std::endl;

    return 0;
}