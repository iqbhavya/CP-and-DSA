class Solution {
public:

    int ans = 0;

    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();

        // horizontal

        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }

        // Vertical
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // diagonal left
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // diagonal right
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nqueens(vector<string>& board, int row) {

        int n = board.size();
        if(row == n){
            ans++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(board, row, i)) {
                board[row][i] = 'Q';
                nqueens(board, row + 1);
                board[row][i] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        nqueens(board, 0);
        return ans;
    }
};