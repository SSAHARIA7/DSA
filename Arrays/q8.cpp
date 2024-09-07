#include <iostream>
#include <vector>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr1;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr1.push_back(temp);
    }
    int m;
    std::cin>>m;
    std::vector <int> arr2;
    for(int i{} ; i<m ; i++){
        int temp;
        std::cin>>temp;
        arr2.push_back(temp);
    }
    std::vector <int> arr;
    int i{},j{};
    int latest = INT32_MIN; //or arr.back() can be used
    while(i<n && j < m){
            if(arr1.at(i) >= arr2.at(j)){
                if(latest != arr2.at(j)){
                    arr.push_back(arr2.at(j));
                    latest = arr.at(arr.size()-1);
                }
                j++;
            }else{
                if(latest != arr1.at(i)){
                    arr.push_back(arr1.at(i));
                    latest = arr.at(arr.size()-1);
                }
                i++;
            }
        }


    for(;j<m; j++){
        if(arr.at(arr.size() -1) != arr2.at(j)){
                    arr.push_back(arr2.at(j));
                }
    }
    for(;i<n; i++){
        if(arr.at(arr.size() -1) != arr1.at(i)){
                arr.push_back(arr1.at(i));
            }
    }


    for(int i: arr){
        std::cout<<i<<" ";
    }
    return 0;
}