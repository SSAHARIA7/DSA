#include <iostream>
#include <vector>
void swap(int &a , int &b){
    int temp  = a;
    a = b;
    b = temp;
}
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }


    int start = 0, end = n-1;

    int middle = 0;

    while(middle>=start && middle <= end){
        if(arr.at(middle) == 1){
            middle++;
        }else if(arr.at(middle) == 2){
            swap(arr.at(middle), arr.at(end));
            end--;
        }else{
            swap(arr.at(middle),arr.at(start));
            start++;
        }
    }

    for(int i: arr){
        std::cout<<i<<" ";
    }
    return 0;
}