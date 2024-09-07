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

    // int minNegpreSum{};
    // int currentSum{};
    // int maxSum{};
    // for(int i{} ; i<n ; i++){
    //     currentSum += arr.at(i);
    //         if(maxSum < currentSum - minNegpreSum){
    //             maxSum = currentSum - minNegpreSum;
    //         }
    //     if(currentSum < minNegpreSum){
    //         minNegpreSum = currentSum;
    //     }
    // }

    //KADANE'S ALGORITHM

    long long maxSum = INT32_MIN;
    long long sum{};
    int startIndex = 0;
    int endIndex = -1;
    for(int i{} ; i<n ; i++){
        sum+=arr.at(i);
        if(sum>maxSum){
            maxSum = sum;
            endIndex = i;
        }
        if(sum < 0){
            sum = 0;
            startIndex = i+1;
        }
    }
    if(maxSum < 0){
        maxSum = 0;
        startIndex = -1;
        endIndex = -1;  //Empty Subarray
    }


    std::cout<<"Maximum Subarray Sum : " << maxSum<<std::endl;
    std::cout<<"Subarray: ";
    for(int i = startIndex ; i<=endIndex ; i++){
        std::cout<<arr.at(i)<<" ";
    }

    return 0;
}