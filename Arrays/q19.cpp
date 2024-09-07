#include <iostream>
#include <vector>
void swap(int &a , int&b){
    int temp = a;
    a = b; 
    b =temp;
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

    int posIndex = 0;
    int negIndex = 1;
    std::vector<int> resultant(n);

    //for NON RELATIVE ORDER
    // for(int i{}  ; i<n ; i++){
    //     if(arr.at(i) > 0 ){
    //         if(i%2 != 0){
    //             swap(arr.at(i) , arr.at(posIndex));
    //             i--;
    //         }
    //         posIndex += 2;
            
    //     }else if(arr.at(i) < 0 && i%2 == 0){
    //         if(i%2 == 0){
    //             swap(arr.at(i) , arr.at(negIndex));
    //             i--;
    //         }
    //         negIndex += 2;
    //     }
    // }
    
    for(int i{} ; i<n ; i++){
        if(arr.at(i)>0){
            resultant.at(posIndex) = arr.at(i);
            posIndex += 2;
        }else{
            resultant.at(negIndex) = arr.at(i);
            negIndex += 2;
        }
    }



    for(int i: resultant){
        std::cout<<i<<" ";
    }
    return 0;
}