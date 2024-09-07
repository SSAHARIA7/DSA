#include <iostream>
#include <vector>
#include <algorithm>

#include <list>

int main(){
    std::cout<<"Hello"<<std::endl;
    int n;
    std::cin>>n;
    std::cout<<n;
    std::vector<int> arr{2,3,4,5};
    std::vector<int> arr2{1,2,3};
    std::vector <int> arr3;
    std::cout<<arr.max_size();
    std::transform(arr.begin(),arr.end(),arr2.begin(),std::back_inserter(arr3),[](int x,int y){return x*y;});
    for(int i: arr3){
        std::cout<<i<<" ";
    }
    std::list<int> l;
    l.sort();
    return 0;
}   