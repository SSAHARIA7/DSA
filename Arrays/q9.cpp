#include <iostream>
#include <vector>
int main(){
    int n;
    std::cout<<"Hello Debugger"<<std::endl;
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

    while(i<n && j<m){
        if(arr1.at(i) > arr2.at(j)){
            j++;
        }else if(arr1.at(i) < arr2.at(j)){
            i++;
        }else{
            arr.push_back(arr1.at(i));
            i++;
            j++;
        }
    }

    for(int k: arr){
        std::cout<<k<<" ";
    }
    return 0;

}