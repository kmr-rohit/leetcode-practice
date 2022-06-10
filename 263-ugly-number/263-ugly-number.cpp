// class Solution {
// public:
//     bool solve(int n , vector<bool> &dp){
//         if(n<=0){
//             return false;
//         }
//         if(n == 1){
//             return true;
//         }
//         if(dp[n] != false){
//             return dp[n];
//         }
//         if(n%2 == 0 ){
//             return dp[n] = solve(n/2 ,dp);
            
//         }
//         else if(n%3 == 0){
//             return dp[n] = solve(n/3 ,dp);
//         }
//         else if(n%5 == 0){
//             return dp[n] = solve(n/5 ,dp);
//         } 
//         else{
//             return false;
//         }
//     }
    
//     bool isUgly(int n) {
//     vector<bool> dp(n+1 , false);
//     return solve(n ,dp);
//     }
// };
class Solution {
public:
    bool isUgly(int n) {
        if(n < 1) return 0;
        if(n < 7) return 1;
        if((n & 1) == 0) return isUgly(n / 2);
        if((n % 3) == 0) return isUgly(n / 3);
        if((n % 5) == 0) return isUgly(n / 5);
        return 0;
    }
};