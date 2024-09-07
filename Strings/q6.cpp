#include <iostream>
#include <string>
#include <math.h>
int main(){
    std::string str;
    std::cin>>str;
    //ASCII value of 0 is 48
    long long ans{};
    int factor{1};
    int mode{1};
    for(int i{str.length()-1} ; i>=0 ; i--){
        int temp = str.at(i) - '0';
        if(mode){
            ans  += (temp*factor);
        }else{
            ans -= (temp*factor);
        }
        if(factor == 100){
            factor = 1;
            mode = !mode;
        }else{
            factor *= 10;
        }
    }
    std::cout<<ans;
    return 0;   
}