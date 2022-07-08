class Solution {
public:
    int dp[101][21][101];
    int solve(int i , int pc, int tn , vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(tn > target){
            return INT_MAX/2;
        }
        if(i == m){
            if(tn == target){
                return 0;
            }
            else{
                return INT_MAX/2;
            }
        }
        if(dp[i][pc][tn] != -1){
            return dp[i][pc][tn];
        }
        else{
            int ans = INT_MAX/2;
            if(houses[i] == 0){
                for(int j = 0;j<n;j++){
                    ans = min ( ans , cost[i][j] + solve(i+1 , j+1 , (pc == j+1?tn:tn+1) ,houses , cost , m , n , target ));

                }
            }
            else{
                ans = min(ans ,solve(i+1 , houses[i] , (houses[i] == pc?tn:tn+1) ,houses , cost , m , n , target ) );
            }
        return dp[i][pc][tn] = ans;
    }
        }
        
        
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp , -1 , sizeof dp);
        int ans =  solve(0 , 0 , 0 , houses , cost , m , n ,target);
        if(ans != INT_MAX/2){
            return ans;
        }
        else{
            return -1;
        }
    }
};