class Solution {
public:
    int solve(int m,int n,int i,int j, vector<vector<int>>&dp , vector<vector<int>>& grid){
    
    if(i==m-1&&j==n-1 && grid[i][j] != 1){
        return 1;
    }
    if(i>m-1||j>n-1){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(grid[i][j] == 1){
        return 0;
    }  
    
    int x = solve(m ,n,i+1 , j , dp , grid);
    int y = solve( m , n, i , j+1 , dp , grid);
    return dp[i][j]= x+y;


   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(m , n , 0 , 0, dp ,obstacleGrid);
    }
};