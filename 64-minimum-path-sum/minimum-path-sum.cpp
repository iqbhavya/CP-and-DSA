class Solution {
public:
    int ans(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>& dp){
        if (i >= m || j >= n) {
            return 1e9; 
        }

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int a = ans(grid, m , n , i+1 , j , dp);
        int b = ans(grid, m , n , i , j+1 , dp);

        return dp[i][j] = grid[i][j] + min(a,b);
        
    }


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));

        return ans(grid,m,n,0,0,dp);

    }
};