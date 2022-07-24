class Solution {
public:
    int solve(int i , int size , int sum , vector<vector<int>> &dp  , string &s){
        if(i<0){
            return 0;
        }
        
        if(dp[i][size] != -1){
            return dp[i][size];
        }
        
        int not_pick = solve(i-1 , size , sum , dp  , s);
        int pick = 0;
        
        if(sum - (s[i] - '0')*pow(2 , size) >=0){
            pick = 1 + solve(i-1 , size+1 ,sum - (s[i] - '0')*pow(2 , size) , dp ,s);
        }
        
        return dp[i][size] = max(pick , not_pick);
    }
    int longestSubsequence(string s, int k) {
        vector<vector<int>> dp(s.size() +1 , vector<int>(s.size() , -1));
        return solve(s.size()-1 , 0 , k , dp , s);
    }
};