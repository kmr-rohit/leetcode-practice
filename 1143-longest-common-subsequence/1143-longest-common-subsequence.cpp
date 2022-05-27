class Solution {
public:
    int solve(int ind1 ,int ind2 , string &text1 , string &text2 ,vector<vector<int>> & dp){
        if(ind1 < 0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        
        if(text1[ind1] == text2[ind2]){
            return dp[ind1][ind2] = 1 + solve(ind1-1 , ind2-1 , text1 ,text2,dp);
        }
        else{
            return dp[ind1][ind2] = max(solve(ind1-1 , ind2 , text1 ,text2,dp) ,solve(ind1 , ind2-1 , text1 ,text2 ,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size()-1;
        int m = text2.size() -1;
        vector<vector<int>> dp(n+1  , vector<int>(m+1 , -1));
        return solve( n , m , text1 , text2 ,dp);
        
    }
};