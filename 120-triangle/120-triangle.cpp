class Solution {
public:
    int solve(vector<vector<int>>& triangle , int i , int j , vector<vector<int>> &dp){
        
        int rows = triangle.size();
        if(i>rows-1 ){
            return 0;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        if(j == rows-1){
            return triangle[i][rows-1];
        }
        
        int down  = triangle[i][j] + solve(triangle , i+1 , j,dp);
        int daigonal  = triangle[i][j] + solve(triangle , i+1 , j+1,dp);
        
        return dp[i][j] = min(down , daigonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> dp(rows,vector<int>(rows , -1));
        return solve(triangle , 0 ,0 ,dp);
    }
};