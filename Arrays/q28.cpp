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

    int counter1{},counter2{};
    int element1{},element2{};

    for(int i{} ; i<n ; i++){
        if(counter1==0 && arr.at(i)!= element2){
            element1 = arr.at(i);
            counter1++;
        }else if(counter2==0 && arr.at(i) != element1){
            element2 = arr.at(i);
            counter2++;
        }else if(element1 == arr.at(i)){
            counter1++;
        }else if(element2 == arr.at(i)){
            counter2++;
        }else{
            counter1--;
            counter2--;
        }
    }
    counter1 = counter2 = 0;
    for(int i{} ; i < n ; i++){
        if(arr.at(i) == element1){
            counter1++;
        }else if(arr.at(i) == element2){
            counter2++;
        }
    }
    std::vector<int> ans;
    if(counter1> (n/3)){
        ans.push_back(element1);
    }
    if(counter2 > (n/3)){
        ans.push_back(element2);
    }

    for(int i: ans){
        std::cout<<i<<" ";
    }
    return 0;
}