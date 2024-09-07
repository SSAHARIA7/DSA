#include <iostream>
#include <vector>
#include <string>

//BETTER SOLUTION IS USING HASHING SEE STRIVERS VIDEO
void markRow(std::vector<std::string> &chessBoard, int rowIndex){
    for(int i{} ; i<chessBoard.size() ; i++){
        if(chessBoard.at(rowIndex).at(i) != 'Q'){
            chessBoard.at(rowIndex).at(i) = '.';
        }
    }
}



void markColumn(std::vector<std::string> &chessBoard, int columnIndex){
    for(int i{} ; i<chessBoard.size() ; i++){
        if(chessBoard.at(i).at(columnIndex) != 'Q'){
            chessBoard.at(i).at(columnIndex) = '.';
        }
    }
}

void markDiagonals(std::vector<std::string> &chessBoard, int rowIndex, int columnIndex){

    for(int i{rowIndex+1},j{columnIndex-1} ; i<chessBoard.size() && j>=0 ; i++,j--){
        chessBoard.at(i).at(j) = '.';
    }
    for(int i{rowIndex+1},j{columnIndex+1}; i<chessBoard.size() && j<chessBoard.size() ; i++,j++){
        chessBoard.at(i).at(j) = '.';
    }
}



void nQueens (int n, std::vector<std::vector<std::string>> &ans , std::vector<std::string> &storageBoard, int rowIndex = 0){

    if(rowIndex >= n){
        ans.push_back(storageBoard);
        return;
    }

    std::vector<std::string> tempBoard = storageBoard;

    for(int j{} ; j<n ; j++){
        if(storageBoard.at(rowIndex).at(j) != '.'){
            storageBoard.at(rowIndex).at(j) = 'Q';
            markColumn(storageBoard,j);
            markRow(storageBoard,rowIndex);
            markDiagonals(storageBoard,rowIndex,j);
            nQueens(n,ans,storageBoard,rowIndex+1);
            storageBoard = tempBoard;
        }
    }

}


int main(){
    int n = 4;
    std::vector<std::string> chess(n);
    for(int i{} ; i<n ;i++){
        for(int j{} ; j<n ; j++){
            chess.at(i).push_back('-');
        }
    }
    std::vector<std::vector<std::string>> ans;
    nQueens(n,ans,chess);
   for(auto v: ans){
        for(auto s: v){
            std::cout<<s<<std::endl;
        }
        std::cout<<"\n\n\n";
   }


    return 0;
}