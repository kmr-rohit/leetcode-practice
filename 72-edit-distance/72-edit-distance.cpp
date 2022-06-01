class Solution {
public:
// MEMOISED APPROACH
//     int solve(int i  , int j , string &s , string & t , vector<vector<int>> &dp){
        
//         if(i<0){
//             return j+1;
//         }
//         if(j<0){
//             return i+1;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         if(s[i] == t[j]){
//             //  Matching chars therefor we will shift both indexs
//             return 0 + solve(i-1 , j-1 , s ,t , dp);
//         }
//         else{
//             // We can perform deletion (i-1 , j)
//             int a = 1 + solve(i-1 , j , s, t,dp);
//             // We can perform insertion ( we will be quiet intelligent we will add simply the s[j] to find                  minimum operations   || hypothrtically i will not shift bcz we inserted ahead if it tit                    becoms current i )
//             int b = 1 + solve(i , j-1 , s ,t ,dp);
//             //  We can replace the s[i] with s[j] : i->i-1 && j->j-1
//             int c = 1 + solve(i-1 ,j-1 , s, t ,dp);
            
//             return min(a ,min(b ,c));
            
//         }
        
//     }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // Base case
        for(int i = 0 ; i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i == 0){
                    dp[0][j] = j;
                }
                else if(j == 0){
                    dp[i][0] = i;
                }
                else{
                    if(s[i-1] == t[j-1]){
                        dp[i][j] = 0 + dp[i-1][j-1];
                    }
                    else{
                        int a = 1 + dp[i][j-1] ;// insertion
                        int b = 1 + dp[i-1][j] ;//deletion;
                        int c = 1 + dp[i-1][j-1];// replace
                        dp[i][j] = min(a , min(b,c));
                    }
                }
            }
        }
        return dp[n][m];
        
    }
};