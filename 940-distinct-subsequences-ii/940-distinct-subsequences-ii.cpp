class Solution {
public:
    int distinctSubseqII(string S) {
        int MOD = 1e9 + 7;
        int n = S.size();
        vector<int> dp(n + 1, 1), last(26, -1);

        dp[0] = 1;
        for(int i = 0; i < n; i ++){
            dp[i + 1] = 2 * dp[i] % MOD;
            if(last[S[i] - 'a'] != -1){
                dp[i + 1] -= dp[last[S[i] - 'a']];
                if(dp[i + 1] < 0)
                    dp[i + 1] += MOD;
            }
            last[S[i] - 'a'] = i;
        }
        return dp[n] - 1 < 0 ? MOD - 1 : dp[n] - 1;
    }
};