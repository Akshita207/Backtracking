#include<iostream>
using namespace std;
int n=9;
bool ispos(int mat[][9],int i,int j,int t){
    //for row or col
    for(int p=0; p<n; p++){
        if(mat[p][j]==t || mat[i][p]==t){
            return false;
        }
    }
    //for subgrid
    int s1=(i/3)*3;
    int s2=(j/3)*3;
    for(int x=s1;x<s1+3;x++){
        for(int y=s2;y<s2+3;y++){
            if(mat[x][y]==t){
                return false;
            }
        }
    }
    return true;
}
void printmat(int mat[][9]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
            if((j+1)%3==0){
                cout<<"\t";
            }
        }
        if((i+1)%3==0){
            cout<<endl;
        }
        cout<<endl;
    }
}
bool solve(int mat[][9],int i,int j){
    if(i==9){
        printmat(mat);
        return true;
    }
    //crossed last cell in row
    if(j==9){
        return solve(mat,i+1,0);
    }
    //filled cell
    if(mat[i][j]!=0){
        return solve(mat,i,j+1);
    }
    //empty cell
    for(int t=1;t<=9;t++){
        if(ispos(mat,i,j,t)){
            mat[i][j]=t;
            bool next=solve(mat,i,j+1);
            if(next){
                return true;
            }
            //will try with next no.
        }
    }
    //not possible
    mat[i][j]=0;
    return false;
}
int main(){
    int mat[9][9]={{5,3,0,0,7,0,0,0,0},
                   {6,0,0,1,9,5,0,0,0},
                   {0,9,8,0,0,0,0,6,0},
                   {8,0,0,0,6,0,0,0,3},
                   {4,0,0,8,0,3,0,0,1},
                   {7,0,0,0,2,0,0,0,6},
                   {0,6,0,0,0,0,2,8,0},
                   {0,0,0,4,1,9,0,0,5},
                   {0,0,0,0,8,0,0,7,9}};

    printmat(mat);
    cout<<"sol. : ";
    solve(mat,0,0);
    return 0;
}
