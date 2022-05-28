class Solution {
public:
    string reverse(string &s){
       string r="";
        for (int i = s.length() - 1; i >= 0; i--){
            r = r + s[i];
        }
        return r;
    }
        
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
    int longestPalindromeSubseq(string s) {
        int n = s.size() -1;
        string reverses = reverse(s);
        vector<vector<int>> dp(n+1,vector<int>(n+1 , -1));
        return solve(n , n ,s ,reverses , dp);
    }
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};