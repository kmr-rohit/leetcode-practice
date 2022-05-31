class Solution {
public:
    int solve(int n , vector<int> &dp){
        if(n<=3){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans=n;
        
        for(int i = 1 ; i*i <=n; i++){
            ans = min(ans , 1+solve(n- i*i , dp));
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1 , -1);
        return solve(n,dp);
    }
};