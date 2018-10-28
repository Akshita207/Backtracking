#include<iostream>
using namespace std;
bool issafe(int board[][10],int i,int j,int n){
    // for column
    for(int r=0; r<i; r++){
        if(board[r][j]==1){
            return false;
        }
    }
    //for left diag
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    //for right diag
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solve(int board[][10],int i,int n){
    if(i==n){
    //placed all .... now print
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==1){
                    cout<<"Q";
                }
                else{
                    cout<<"_";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

        for(int j=0; j<n; j++){
            if(issafe(board,i,j,n)){
                board[i][j]=1;

                bool nq=solve(board,i+1,n);
                if(nq){
                    return true;
                }
                //wrong assumption of positions
                //backtrack
                board[i][j]=0;
        }
    }
    //not possible to place
    return false;
    }

int main(){
    int n;
    cin>>n;
    int board[10][10]={0};
    solve(board,0,n);
    return 0;
}
