#include <iostream>

bool isPalindromeHelper(std::string str,int start, int end){
    if(start>=end) return true;
	if(str.at(start) != str.at(end)) return false;
    return isPalindromeHelper(str, start+1, end-1);
}

int  main(){
    std::cout<<isPalindromeHelper("refeer",0,5);
    return 0;
}