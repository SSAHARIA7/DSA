#include <iostream>
#include <vector>

int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>>matrix;
    for(int i{} ; i<n ; i++){
        std::vector <int> temp;
        for(int j{} ; j<m ; j++){
            int tempNo;
            std::cin>>tempNo;
            temp.push_back(tempNo);
        }
        matrix.push_back(temp);
    }

    //METHOD 1: USE 2 EXTRA ARRAYS TO MARK THE ROWS AND COLUMNS CONTAINING 0's

    //METHOD 2: USE 1ST ROW AND COLUMN OF THE MATRIX ITSELF TO MARK THE ROWS AND COLUMNS AND SAVE SPACE:
    int col0 = 1;
    for(int i{} ; i<n ; i++){
        for(int j{} ; j<m ; j++){
            if(matrix.at(i).at(j) == 0){
                if(j==0){
                    col0 = 0;
                }else{
                    matrix.at(0).at(j) = 0;
                }
                matrix.at(i).at(0) = 0;
            }
        }
    }
    // HANDLING NON MARKING ROWS AND COLUMNS
    for(int i{1} ; i<n ;i++){
        for(int j{1} ; j<m ; j++){
            if(matrix.at(i).at(0) == 0 || matrix.at(0).at(j) == 0){
                matrix.at(i).at(j) = 0;
            }
        }
    }
    // HANDLING 1st Row and 1st Columns 
    // NOTE THAT WE HAVE TO HANDLE THE 1ST ROW FIRST OR ELSE ANSWER MAY COME WRONG

    for(int i{} ; i<m ; i++){
        if(matrix.at(0).at(0) == 0){
            matrix.at(0).at(i) = 0;
        }
    }
    for(int i{} ; i<n ; i++){
        if(col0 == 0){
            matrix.at(i).at(0) = 0;
        }
    }

    for(int i{} ; i<n ; i++){
        for(int j{} ; j<m ; j++){
            std::cout<<matrix.at(i).at(j)<<" "; 
        }
        std::cout<<std::endl;
    }



    return 0;
}