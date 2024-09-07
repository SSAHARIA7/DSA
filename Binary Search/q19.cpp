#include <iostream>
#include <vector>
#include <algorithm>

double minimiseMaxDistance(std::vector<int> &arr, int k){
	// Write your code here.	
    double low = 0;
    double high {INT32_MIN};
    for(int i{} ; i<arr.size()-1 ; i++){
        high = std::max(high,double(arr.at(i+1) - arr.at(i)));
    }


    while(low <= high){
        int mid = (low + high)/2;
        
    }

}
int main(){

    return 0;
}