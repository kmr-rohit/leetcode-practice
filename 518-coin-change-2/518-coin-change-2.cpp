class Solution {
public:
    int solve(int ind  , vector<int> &a , int t,vector<vector<int>> &dp){
        if(ind == 0){
            if(t%a[0] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][t] != -1){
            return dp[ind][t];
        }

        int not_take  = solve(ind-1 , a , t,dp);
        int take = 0;
        if(a[ind] <= t){
            take  = solve(ind , a , t-a[ind],dp);
    }
    
    return dp[ind][t] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        return solve( n-1 ,coins , amount,dp);
        
    }
};