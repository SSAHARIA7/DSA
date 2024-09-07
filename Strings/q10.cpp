#include <iostream>
#include <string>
#include <vector>
int main(){
    std::string str1,str2;
    std::cin>>str1>>str2;
    int k;
    std::cin>>k;
    bool kAnagram{true};
    std::vector<int> frequency1(26);
    std::vector<int> frequency2(26);
    int counter{};
    if(str1.length()!=str2.length()){
        kAnagram = false;
    }else{

        for(int i{} ; i<str1.length() ; i++){
            frequency1.at(str1.at(i)-'a')++;
        }
        for(int i{} ; i<str2.length() ; i++){
            frequency2.at(str2.at(i) - 'a')++;
        }
        for(int i{} ; i<26 ; i++){
            if(frequency2.at(i) > frequency1.at(i))
                counter += (frequency2.at(i) - frequency1.at(i));
        }
    }
       if(kAnagram && k >= counter){
            kAnagram = true;
       }else{
            kAnagram = false;
       }



    return 0;   
}