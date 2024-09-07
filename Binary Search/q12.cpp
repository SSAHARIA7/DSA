#include <iostream>
#include <vector>

int roseGarden(std::vector<int> arr, int k, int m)
{
    int maxDays{};
	for(int i: arr){
        maxDays = std::max(maxDays,i);
    }

    int low = 0; 
    int high = maxDays;
    int minDays{INT32_MAX};

    while(low <= high){
        int mid = (low + high)/2;
        int tempRoses{};
        int tempBouquet{};
        for(int days: arr){
            if(days <= mid ){
                tempRoses++;
            }else{
                tempRoses = 0;
            }

            if(tempRoses == k){
                tempBouquet++;
                tempRoses = 0;
            }
        }
        if(tempBouquet >= m){
            minDays  = std::min(minDays,mid);
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    if(minDays == INT32_MAX) return -1;
    return minDays;

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
    int k,m;
    std::cin>>k>>m;

    std::cout<<roseGarden(arr,k,m);
    return 0;
}