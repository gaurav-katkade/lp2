#include <vector>
#include <iostream>
using namespace std;

void printSolution(vector<vector<char>>&board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(vector<vector<char> >&board,int row,int col,int n){
    int i=row;
    int j=col;

    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }

    i=row;
    j=col;

    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;

    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--; 
    }
    return true;
}

void solveBoard(vector<vector<char>> &board,int col,int n){
    if(col>=n){
        printSolution(board,n);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solveBoard(board,col+1,n);
            board[row][col]='-';
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of queens:"<<endl;
    cin>>n;

    vector<vector<char> >board(n,vector<char>(n,'-'));
    int col=0;

    solveBoard(board,col,n);
    return 0;
}
