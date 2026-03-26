#include<bits/stdc++.h>
using namespace std;
void printBoard(vector<vector<char>>board){
    int n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
    }
    cout<<"----------------\n";
}
bool isSafe(vector<vector<char>>board, int row, int col){
    int n = board.size();
    //horizontal
    for(int i=0;i<n;i++){
        if(board[row][i] =='Q'){
            return false;
        }
    }
    //vertical
    for(int i=0;i<row;i++){
        if(board[i][col] =='Q'){
            return false;
        }
    }
    //diagonal left
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    //diagonal right
    for(int i=row,j=col;i>=0 && j>=0;i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
int nQueens(vector<vector<char>>board, int  row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return 1;
    }
    int count = 0;
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j)){
           board[row][j] = 'Q';
           count += nQueens(board,row+1);
           board[row][j] = '.';
        }
    }
    return count;//no of possible solutions at each level
}
//*****GRID WAY*****// T.C= O(2^(n+m))
int gridWays(int r, int c, int n, int m,string ans){
    if(r==n-1 && c==m-1){
        cout<<ans<<"\n";
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    //right
    int val1 = gridWays(r,c+1,n,m, ans+"R");
    //down
    int val2 = gridWays(r+1,c,n,m,ans+"D");
    return val1+ val2;
}
// ********** SUDOKU ***********
void printSudoku(int sudoku[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    } 
}
bool isSafee(int sudoku[9][9], int row,int col,int dig){
    for(int i=0;i<=8;i++){//vertical
        if(sudoku[i][col] == dig){
            return false;
        }
    }
    for(int j=0;j<=8;j++){//horizontal
        if(sudoku[row][j]==dig){
            return false;
        }
    }
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i=startRow;i<=startRow+2;i++){
        for(int j=startCol;j<=startCol+2;j++){
            if(sudoku[i][j] ==dig){
                return false;
            }
        }
    }
    return true;
}
bool SudokuSolve(int sudoku[9][9],int row,int col){
    if(row ==9){
        printSudoku(sudoku);
        return true;
    }
    int nextRow = row;
    int nextCol = col+1;
    if(col +1 ==9){
        nextRow = row+1;
        nextCol=0;
    }
    if(sudoku[row][col] !=0){
        return SudokuSolve(sudoku,nextRow,nextCol);
    }
    for(int dig = 1;dig<=9;dig++){
        if(isSafee(sudoku,row,col,dig)){
            sudoku[row][col] = dig;
            if (SudokuSolve(sudoku,nextRow,nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}
int main(){
    vector<vector<char>>board;
    int n;
    cin>>n;
    int m;
    cin>>m;
    cout<<"\n";
    string ans = "";
    for(int i=0;i<n;i++){
        vector<char>newRow;
        for(int j=0;j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int count = nQueens(board,0);
    cout<<"count : "<<count<<endl;
    cout<<gridWays(0,0,n,m,ans)<<endl;
    int sudoku[9][9]={{0, 0, 8, 0, 0, 0, 0, 0, 0},
                      {4, 9, 0, 1, 5, 7, 0, 0, 2},
                      {0, 0, 3, 0, 0, 4, 1, 9, 0},
                      {1, 8, 5, 0, 6, 0, 0, 2, 0},
                      {0, 0, 0, 0, 2, 0, 0, 6, 0},
                      {9, 6, 0, 4, 0, 5, 3, 0, 0},
                      {0, 3, 0, 0, 7, 2, 0, 0, 4},
                      {0, 4, 9, 0, 3, 0, 0, 5, 7},
                      {8, 2, 7, 0, 0, 9, 0, 1, 3}}; 
    SudokuSolve(sudoku,0,0);
    return 0;
}