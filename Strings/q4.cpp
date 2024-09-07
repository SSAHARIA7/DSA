#include <iostream>
#include <string>


char reqChar(int mode, int value){
    if(mode == 1){
        switch(value){
            case 1: return 'I';
            case 5: return 'V';
        }
    } else if(mode == 10){
        switch(value){
            case 1: return 'X';
            case 5: return 'L';
        }
    } else if(mode == 100){
        switch(value){
            case 1: return 'C';
            case 5: return 'D';
        }
    } else if(mode == 1000){
        switch(value){
            case 1: return 'M';
        }
    }
}



void convertToRoman(std::string &str , int mode , int numb){
    if(numb >= 1 && numb <= 3){
        for(int i{} ; i<numb ; i++){
            str.push_back(reqChar(mode,1));
        }
    }else if(numb == 4){
        str.push_back(reqChar(mode,1));
        str.push_back(reqChar(mode,5));
    }else if(numb>=5 && numb <= 8){
        str.push_back(reqChar(mode,5));
        numb-=5;
        for(int i{} ; i<numb ; i++){
            str.push_back(reqChar(mode,1));
        }
    }else if(numb == 9){
        str.push_back(reqChar(mode,1));
        str.push_back(reqChar(mode*10,1));
    }
}


int main(){
    int n;
    std::cin>>n;

    std::string romanStr;
    int ones = n%10;
    int tens = (n%100)/10;
    int hundreds = (n%1000)/100;
    int thousands = (n%10000)/1000;


    convertToRoman(romanStr,1000,thousands);
    convertToRoman(romanStr,100,hundreds);
    convertToRoman(romanStr,10,tens);
    convertToRoman(romanStr,1,ones);




    std::cout<<romanStr;
    return 0;   
}