// Recursion
// class Solution {
// public:
//     int m = 1e9 + 7;
//     int solve(int s ,int c , int m , int n  , int maxSteps ){
//         if(s<0 || c<0 || s>m-1 || c > n-1){
//             return 1;
//         }
        
//         if(maxSteps==0){
//             return 0;
//         }
        
        
        
//         int down = solve(s+1 , c, m , n , maxSteps-1 ) ;
//         int right = solve(s , c+1, m , n , maxSteps-1  );
//         int  up= solve(s-1 , c, m , n , maxSteps-1) ;
//         int left = solve(s , c-1, m , n , maxSteps-1) ;
        
//         return (up + right + down  + left);
    
    
//     }
//     int findPaths(int m, int n, int maxSteps, int s, int c) {
        
//         return solve(s , c , m , n , maxSteps );
//     }
// };



// Memoisation
class Solution {
public:
    
    int solve(int s ,int c , int m , int n  , int maxSteps , vector<vector<vector<long long>>>&dp){
        if(s<0 || c<0 || s>=m || c >=n){
            return 1;
        }
        
        if(maxSteps==0){
            return 0;
        }
        
        if(dp[s][c][maxSteps] != -1){
            return dp[s][c][maxSteps];
        }
        
        long long  down = solve(s+1 , c, m , n , maxSteps-1 ,dp)%1000000007 ;
         long long right = solve(s , c+1, m , n , maxSteps-1  , dp)%1000000007;
         long long  up= solve(s-1 , c, m , n , maxSteps-1, dp)%1000000007;
         long long left = solve(s , c-1, m , n , maxSteps-1, dp)%1000000007 ;
        
        return dp[s][c][maxSteps] = (up + right + down  + left)%1000000007;
    
    
    }
    int findPaths(int m, int n, int maxSteps, int s, int c) {
        vector<vector<vector<long long>>> dp(m , vector<vector<long long>> (n , vector<long long>(maxSteps+1 , -1)));
        return solve(s , c , m , n , maxSteps , dp);
    }
};





// Tabulation 

// class Solution {
// public:
    
//     int solve(int s ,int c , int m , int n  , int maxSteps , vector<vector<int>> dp){
//         if(s<0 || c<0 || s>m-1 || c > n-1){
//             return 1;
//         }
        
//         if(maxSteps==0){
//             return 0;
//         }
        
//         if(dp[s][c] != -1){
//             return dp[s][c];
//         }
        
//         int down = solve(s+1 , c, m , n , maxSteps-1 ,dp)%100000007 ;
//         int right = solve(s , c+1, m , n , maxSteps-1  , dp)%100000007;
//         int  up= solve(s-1 , c, m , n , maxSteps-1, dp)%100000007;
//         int left = solve(s , c-1, m , n , maxSteps-1, dp)%100000007 ;
        
//         return dp[s][c] = (up + right + down  + left)%100000007;
    
    
//     }
    
//     int findPaths(int m, int n, int maxSteps, int s, int c) {
//         vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
        
        
//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
                
//             }
//         }
//     }
// };