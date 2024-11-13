#include<iostream>
#include<vector>
using namespace std;
bool issafe(int col,int row, vector<string> &board,int n){
        int dupcol=col;
        int duprow=row;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        col=dupcol;
        row=duprow;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=duprow;
        col=dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;

}
void solve(int col,int n,vector<vector<string>>&ans,vector<string>&board){

    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(issafe(col,row,board,n)){
            board[row][col]='Q';
            solve(col+1,n,ans,board);
            board[row][col]='.';
        }
    }
}
vector<vector<string>> SolveQueen(int n){
    vector<vector<string>> ans;
    vector<string>board;
    string s(n,'.');
    for(int i=0;i<n;i++){
        board.push_back(s);
    }
    solve(0,n,ans,board);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the no of queeens "<<endl;
    cin>>n;
    vector<vector<string>>ans=SolveQueen(n);
    for (auto &board : ans) {
        for (auto &row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return  0;
}