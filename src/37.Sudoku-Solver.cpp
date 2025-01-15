class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, int value){
        for(int i=0; i<9; i++){
            if(board[row][i]==value)    return false;
            if(board[i][col]==value)    return false;
        }
        int startRow=(row/3)*3;
        int startCol=(col/3)*3;
        for(int i=startRow; i<startRow+3; i++){
            for(int j=startCol; j<startCol+3; j++){
                if(board[i][j]==value)    return false;
            }
        }
        return true;
    }
    bool backtracing(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]!='.')    continue;
                for(int k='1'; k<='9'; k++){
                    if(isValid(board,i,j,k)){
                        board[i][j]=k;
                        if(backtracing(board)) return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracing(board);
    }
};
