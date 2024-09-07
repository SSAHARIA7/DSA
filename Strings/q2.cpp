#include <iostream>
#include <string>
#include <algorithm>
int main(){
    int n; 
    std::cin>>n;
    std::string arr[n];
    for(int i{} ; i<n ; i++){
        std::cin>>arr[i];
    }
    std::string ans;
    std::sort(arr,arr+n);


    for(int  i{} ; i<n ;i++){
        std::cout<<arr[i]<<" ";
    }

    int minimum = std::min(arr[0].length(),arr[n-1].length());

    for(int i{} ; i<minimum ; i++){
        if(arr[0].at(i) != arr[n-1].at(i)){
            break;
        }else{
            ans.push_back(arr[0].at(i));
        }
    }
    if(ans.length() == 0){
        ans.push_back('-');
        ans.push_back('1');
    }

    std::cout<<ans;
    return 0;   
}