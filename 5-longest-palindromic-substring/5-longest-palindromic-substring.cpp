class Solution {
public:
    string printlcs(string &s , int start,int end , string& ans){
        for(int i = start ;i<= end;i++){
            ans[i-start] = s[i];
        }
        return ans;
    }
    
    string longestPalindrome(string str) {
        int n = str.size();
        vector<vector<bool>> dp( n , vector<bool>(n , false));
        
        for(int i = 0;i<n;i++){
            dp[i][i] = true;
        }
        
        int maxLength = 1;
        
       int start = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        for (int k = 3; k <= n; ++k) {
        // k is for varying the length of string under consideration
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (dp[i + 1][j - 1] && str[i] == str[j]) {
                dp[i][j] = true;
 
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
        string ans = "";
        for(int i = 0;i<maxLength;i++){
            ans = ans + "$";
        }
       return printlcs(str , start , start + maxLength - 1 ,ans);
 
    
    }
};