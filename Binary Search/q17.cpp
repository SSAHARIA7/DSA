#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


int findPages(std::vector<int>& arr, int n, int m) {

    if(n<m) return -1;


    int low = *std::max_element(arr.begin(),arr.end());
    int high = std::accumulate(arr.begin(),arr.end(),0);

    int leastMaxPages{INT32_MAX};

    while(low <= high){
        int mid = (low + high)/2;
        int tempStuds = m;
        int currentPages{};
        int maxPages{INT32_MIN};
        for(int i{} ; i<n ; i++){
            if(currentPages + arr.at(i) <= mid){
                currentPages += arr.at(i);
            }else{
                maxPages = std::max(maxPages,currentPages);
                tempStuds--;
                currentPages = 0;
                currentPages+=arr.at(i);
            }
        }
        tempStuds--;
        maxPages = std::max(maxPages,currentPages);
        if(tempStuds == 0){
            leastMaxPages = std::min(maxPages,leastMaxPages);
            high = mid - 1;
        }else if(tempStuds < 0){
            low = mid+1;
        }else{
            high = mid - 1;
        }
        
    }
    return leastMaxPages;
}


int main(){
    std::vector <int> arr;
    int n;
    std::cin>>n;
    int m;
    std::cin>>m;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    } 
    std::cout<<findPages(arr,n,m);
    return 0;
}