#include <iostream>
#include <string>

int main(){
    std::string str;
    std::cin>>str;

    int ans{};
    
    for(int i{} ; i<str.length(); i++){
        switch(str.at(i)){
            case 'I':{
                if(i!=str.length()-1 && str.at(i+1) != 'I'){
                    ans -= 1;
                }else{
                    ans += 1;
                }
                break;
            }
            case 'V':{
                if(i!=str.length()-1 && str.at(i+1) != 'I' && str.at(i+1) != 'V'){
                    ans -= 5;
                }else{
                    ans += 5;
                }
                break;
            }
            case 'X':{
                if(i!=str.length()-1 && str.at(i+1) != 'I' && str.at(i+1) != 'V'&&str.at(i+1) != 'X'){
                    ans -= 10;
                }else{
                    ans += 10;
                }
                break;
            }
            case 'L':{
                if(i!=str.length()-1 && str.at(i+1) != 'I' && str.at(i+1) != 'V'&&str.at(i+1) != 'X' && str.at(i+1) != 'L'){
                    ans -= 50;
                }else{
                    ans += 50;
                }
                break;
            }
            case 'C':{
                if(i!=str.length()-1 && str.at(i+1) != 'I' && str.at(i+1) != 'V'&&str.at(i+1) != 'X' && str.at(i+1) != 'L'&&str.at(i+1) != 'C'){
                    ans -= 100;
                }else{
                    ans += 100;
                }
                break;
            }
            case 'D':{
                if(i!=str.length()-1 && str.at(i+1) != 'I' && str.at(i+1) != 'V'&&str.at(i+1) != 'X' && str.at(i+1) != 'L'&&str.at(i+1) != 'C'&& str.at(i+1) != 'D'){
                    ans -= 500;
                }else{
                    ans += 500;
                }
                break;
            }
            case 'M':{
                if(i!=str.length()-1 && str.at(i+1) != 'I' && str.at(i+1) != 'V'&&str.at(i+1) != 'X' && str.at(i+1) != 'L'&&str.at(i+1) != 'C'&& str.at(i+1) != 'D' && str.at(i+1) != 'M'){
                    ans -= 1000;
                }else{
                    ans += 1000;
                }
                break;
            }
        }
    }

    std::cout<<ans<<std::endl;
    return 0;   
}