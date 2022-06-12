class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(i==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        for(int k=0;k<m;k++){
            res = min(res, grid[i][j] + moveCost[grid[i][j]][k] + solve(i+1,k,n,m,grid,moveCost,dp));
        }
        return dp[i][j]=res;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0; i<m;i++){
            ans=min(ans, solve(0,i,n,m,grid,moveCost,dp));
        }
        return ans;
    }
};