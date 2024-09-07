#include <iostream>
#include <vector>

int missingK(std::vector < int > vec, int n, int k) {
    int low = 0;
    int high = n -1;
    int allMissing = vec.at(n-1) - n;
    if(k<vec.at(0)){
        return k;
    }

    if(k > allMissing){
        return vec.at(n-1) + k - allMissing;
    }


    while (low <= high){

        int mid = (low + high)/2;

        int totalMissing{vec.at(mid) - 1 - mid};

        if(totalMissing >= k){
            high = mid -1;
        }else{
            low = mid+1;
        }
 
    }
        return vec[high] + k - (vec.at(high) -1 - high ); 
}


int main(){
    std::vector <int> arr;
    int n;
    std::cin>>n;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int k;
    std::cin>>k;

    std::cout<<missingK(arr,arr.size(),k);
    return 0;
}