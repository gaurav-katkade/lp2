#include<bits/stdc++.h>
using namespace std;

bool clash(vector< vector<int> >& b, int n, int r, int c){
    //check horizontal------
    for(int i=c-1; i>=0; i--){
        if(b[r][i]){
            return true;
        }
    }
    
    //check diagonal
    int p=r-1, q=c-1;
    while(p>=0 && q>=0){
        if(b[p][q]){
            return true;
        }
        p--;
        q--;
    }
    
    p=r+1, q=c-1;
    while(p<n && q>=0){
        if(b[p][q]){
            return true;
        }
        p++;
        q--;
    }
    return false;
}

bool fn(vector< vector<int> >& b, int n, int c){
    int i=0;
    if(c==n){
        return true;
    }
    while(i<n){
        if(!clash(b,n,i,c)){
            b[i][c]=1;
            if(fn(b,n,c+1)){
                return true;
            }
            b[i][c]=0;
        }
        i++;
    }
    return false;
}

class nqueen{
private:
    int n;
    vector< vector<int> > board;
public:
    nqueen(){
        this->n=4;
        for(int i=0; i<4; i++){
            board.push_back(vector<int> (n,0));
        }
    }
    nqueen(int n){
        this->n=n;
        for(int i=0; i<n; i++){
            board.push_back(vector<int> (n,0));
        }        
    }
    void printboard(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]){
                    cout<<"Q ";
                }else{
                    cout<<"- ";
                }
            }
            cout<<"\n";
        }
    }
    void placequeen(){
        fn(board,n,0);
    }

};


int main(){
    int n;
    cout<<"Enter size of board:";
    cin>>n;
    nqueen qn(n);
    qn.placequeen();
    qn.printboard();
}
