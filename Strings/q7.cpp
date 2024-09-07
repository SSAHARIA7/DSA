#include <iostream>
#include <string>
#include <algorithm>
std::string convertToHex(int n){
    std::string hexa;
    while(n > 0){
        int temp = n%16;
        if(temp<10){
            hexa.push_back(temp + '0');
        }else{
            hexa.push_back(temp + 'a' -10);
        }
        n/=16;
    }
    return hexa;
}




int main(){
    std::string str;
    std::cin>>str;
    char currentLetter = str.at(0);
    int counter = 0;
    std::string ans;
    ans.push_back(currentLetter);
    for(int i{} ; i<str.length() ; i++){
        if(str.at(i) == currentLetter){
            counter++;
        }else{
            ans.append(convertToHex(counter));
            counter = 1;
            currentLetter = str.at(i);
            ans.push_back(currentLetter);  
        }
    }
    ans.append(convertToHex(counter));
    std::reverse(ans.begin(),ans.end());
    std::cout<<ans;
    return 0;   
}