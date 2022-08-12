class Solution {
    public:
    
    int longestIdealString(string s, int k) {
        
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(27, 0));
        
        // base case 
        for (int prev = 0; prev < 27; prev++) { // can be neglacted because dp is already initailized as 0.
            dp[0][prev] = 0;
        }
        
        for (int ind = 1; ind <= n; ind++) {
            for (int prev = 0; prev < 27; prev++) {
                int take = 0;
                int ch = s[ind - 1] - 'a' + 1;
                if (prev == 0 or abs(ch - prev) <= k) {
                    take = 1 + dp[ind - 1][ch];
                }

                int notTake = dp[ind - 1][prev];

                dp[ind][prev] = max(take, notTake);
            }
        }
        
        return dp[n][0];
    }
};