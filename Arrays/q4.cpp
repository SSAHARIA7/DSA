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
    int counter = 1;
    int lastElement = arr.at(0);
    for(int i{1} ; i<n ; i++){
        if(arr.at(i) != lastElement){
            arr.at(counter) = arr.at(i);
            counter++;
            lastElement = arr.at(i);
        }
    }
    std::cout<<"Unique Elements: " << counter<<std::endl;
    for(int i: arr){
        std::cout<<i<<" ";
    }

    return 0;
}