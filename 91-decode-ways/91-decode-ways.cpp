class Solution {
public:
    int help(string &s , int ind , int n , vector<int> &dp){
        if(ind >= n){
            return 1;
        }
        if(ind<n && s[ind] == '0'){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int count = 0;
        if(s[ind]!='0'){
           count = help(s , ind+1 , n , dp); 
        }
        
        if(ind+1 < n  && ((s[ind] == '1' && s[ind+1]<='9') || (s[ind] == '2' && s[ind+1] <='6'))){
            count += help(s , ind+2 , n ,dp);
        }
        return dp[ind] = count;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp( n , -1);
        return help(s , 0 , n ,dp);
        
    }
};