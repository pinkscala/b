#include <iostream>
#include <vector>

#define N 4

bool isValid(int board[N][N], int row, int col){

    for (int i = 0; i < col; i++){
        if (board[row][i] == 1) { std::cout << "1 "; return false;}      
    }

    for(int i = row,j = col; i < N, j < N && i >= 0, j >= 0; i--,j--){
        if (board[i][j] == 1) {  return false;}    
    }

    for(int i = row,j = col; i < N, j < N && i >= 0, j >= 0; i++,j--){
        if (board[i][j] == 1) { std::cout << "3 "; return false;}    
    }

    return true;
    
}

bool solve(int board[N][N], int col){

    if(col >= N) return true;

    for (int i = 0; i < N; i++)
    {
        if (isValid(board,i,col))
        {
            board[i][col] = 1;

            if (solve(board,col+1) == true) return true;

            board[i][col] = 0;
        }
    }

    return false;
}


bool bnb_recursive(int mat[N][N],int rowCheck[N], int diagCheck[2*N-1], int revDiagCheck[2*N-1], int col){
    for (int i = 0; i < N; i++)
    {
        if (col >= N)
        {
            return true;
        }
        
        if (!(rowCheck[i] || diagCheck[i+col] || revDiagCheck[i-col+3])){
        
        std::cout << "gggg" << std::endl; 

        mat[i][col] = 1;
        rowCheck[i] = 1;
        diagCheck[i+col] = 1;
        revDiagCheck[i-col+3] = 1;

        if (bnb_recursive(mat,rowCheck,diagCheck,revDiagCheck,col+1)) return true;

        mat[i][col] = 0;
        rowCheck[i] = 0;
        diagCheck[i+col] = 0;
        revDiagCheck[i-col+3] = 0;
        }
    }
    return false;
}

bool bnb_solver(int mat[N][N]){
    int rowCheck[N] = {0,0,0,0};
    int diagCheck[2*N-1] = {0,0,0,0,0,0,0};
    int revDiagCheck[2*N-1] = {0,0,0,0,0,0,0};

    return bnb_recursive(mat, rowCheck, diagCheck, revDiagCheck, 0);
}

