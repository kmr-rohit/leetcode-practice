// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n , vector<int>(amount+1 , 0));

//         for(int i = 0;i<=amount;i++){
//           if(i % coins[0] == 0){
//             dp[0][i] = i/coins[0];
//           }
//           else{
//             dp[0][i] = 1e9;
//           }
//         }

//         for(int ind = 1;ind < n;ind++){
//           for(int target = 0;target<=amount;target++){

//             int not_taken =0+ dp[ind-1][target];
//             int taken = 1e9;
//             if(coins[ind]<= target){
//               taken = 1 + dp[ind][target - coins[ind]];
//             }

//             dp[ind][target] = min(taken , not_taken);
//           }
//         }

//         int ans = dp[n-1][amount];
//         if(ans >= 1e9){
//           return -1;
//         }
//         else{
//              return ans;
//         } 
//     }
// };
class Solution {
public:
int solve(int index,int amount,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(index==0) {
            if((amount%coins[0])==0) return (amount/coins[0]);
            else return 1e9-1;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int not_take=solve(index-1,amount,coins,dp);
        int take=1e9-1;
        if(coins[index] <= amount) take=1 + solve(index,amount-coins[index],coins,dp);
        return dp[index][amount]=min(take,not_take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==1) {
            if((amount!=coins[0]) && (amount%coins[0])!=0 ) return -1;
        }
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        if(ans == 1e9-1){
            return -1;
        }
        else{
            return ans;
        }
    }
};