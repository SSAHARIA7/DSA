#include <iostream>
#include <vector>
#include <algorithm>

void swap(int &a , int &b){
	int temp = a;
	a = b; 
	b = temp;
}

int main(){
    int n;
    std::cin>>n;
    std::vector <int> a;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        a.push_back(temp);
    }
    int m;
    std::cin>>m;
    std::vector <int> b;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        b.push_back(temp);
    }

	for(int i{a.size() -1} ; i >= 0; i--){
		if(a.size()-i-1 < b.size()-1 && a[i] > b[a.size() - i -1]){
			swap(a[i],b[a.size() - i - 1]);
		}else{
			break;
		}
	}
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());



    for(int i{} ; i<n ; i++){
        std::cout<<a.at(i)<<" ";
    }
    for(int i{} ; i<n ; i++){
        std::cout<<b.at(i)<<" ";
    }
    return 0;
}