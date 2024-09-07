 #include <iostream>
#include <vector>


int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>>arr;
    for(int i{} ; i<n ; i++){
        std::vector <int> temp;
        for(int j{} ; j<m ; j++){
            int tempNo;
            std::cin>>tempNo;
            temp.push_back(tempNo);
        }
        arr.push_back(temp);
    }

    int mode{};  //0- right 1-down 2-left 3-up
    int rightLimit{m-1},downLimit{n-1},leftLimit{},upLimit{1};
    int i{},j{};
    int counter{};
    while(counter<n*m){
        switch(mode){
            case 0:
                {
                    if(j==rightLimit){
                        std::cout<<arr.at(i).at(j)<<" ";
                        i++;
                        mode = 1;
                        rightLimit--;
                    }else{
                        std::cout<<arr.at(i).at(j)<<" ";
                        j++;
                    }
                    break;

                }
            case 1:
                {
                    if(i==downLimit){
                        std::cout<<arr.at(i).at(j)<<" ";
                        mode = 2;
                        j--;
                        downLimit--;
                    }else{
                        std::cout<<arr.at(i).at(j)<<" ";
                        i++;
                    }
                    break;

                }
            case 2:
                {
                    if(j==leftLimit){
                        std::cout<<arr.at(i).at(j)<<" ";
                        mode = 3;
                        i--;
                        leftLimit++;
                    }else{
                        std::cout<<arr.at(i).at(j)<<" ";
                        j--;
                    }
                    break;

                }
            case 3:
                {
                    if(i==upLimit){
                        std::cout<<arr.at(i).at(j)<<" ";
                        mode = 0;
                        j++;
                        upLimit++;
                    }else{
                        std::cout<<arr.at(i).at(j)<<" ";
                        i--;
                    }
                    break;
                }
        }
        counter++;
    }



    return 0;
}