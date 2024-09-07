#include <iostream>
#include <vector>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n-1 ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int XOR1 = 0;
    int XOR2 = 0;
    for(int i{} ; i<n-1 ; i++){
        XOR1 ^= i+1;
        XOR2^= arr.at(i);
    }
    XOR1 ^= n;
    int ans = XOR1^XOR2;
    std::cout<<"Missing Number = "<<ans;
    return 0;
}