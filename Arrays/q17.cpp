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

    int currentElement = arr.at(0);
    int counter = 1;

    for(int i{1} ; i<n ; i++){
        if(arr.at(i) == currentElement){
            counter++;
        }else{
            if(counter>0){
                counter--;
            }else{
                counter = 1;
                currentElement = arr.at(i);
            }
        }
    }
    std::cout<<"Majority Element: "<<currentElement;

    return 0;
}