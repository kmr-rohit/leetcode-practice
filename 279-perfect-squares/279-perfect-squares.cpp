class Solution {
public:
    //Memoised Approach
//     int solve(int n , vector<int> &dp){
//         if(n<=3){
//             return n;
//         }
//         if(dp[n] != -1){
//             return dp[n];
//         }
//         int ans=n;
        
//         for(int i = 1 ; i*i <=n; i++){
//             ans = min(ans , 1+solve(n- i*i , dp));
//         }
//         dp[n] = ans;
//         return dp[n];
//     }
    int numSquares(int n) {
        int dp[n+1];
        dp[0] = 0;
        
        for(int i=1;i<=n;++i)
        {
            dp[i] = i;
            for(int j=1;j*j<=i;++j)
            {
                int sq = j*j;
                dp[i] = min(dp[i],1+dp[i-sq]);
            }
        }
        return dp[n];
        
    }
};