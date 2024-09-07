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
    int ans = 0; 
   for(int i{}; i<n ; i++){
    ans^=arr.at(i);
   }
   std::cout<<ans<<std::endl;
    return 0;
}