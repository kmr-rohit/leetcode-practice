class Solution {
public:
// Memoised Approach
//     int help (int ind , int buy  , int cap , vector<int>prices , vector<vector<vector<int>>> &dp){
//         if(ind == prices.size()){
//             return 0; // at the end of market we will not get any extra profit 
//         }
//         if(cap == 0){
//             return 0; // we can preform any more transactions
//         }
//         if(dp[ind][buy][cap] != -1){
//             return dp[ind][buy][cap];
//         }
        
        
//         if(buy){
//             return  dp[ind][buy][cap] =  max(-prices[ind] + help(ind+1 , 0 , cap , prices ,dp) , 0 + help(ind+1 ,1 , cap, prices,dp));
//         }
//         else{
//             return dp[ind][buy][cap] = max(prices[ind] + help(ind+1 , 1,cap-1, prices,dp)  , 0+help(ind+1 ,0,cap, prices,dp));
//         }
//     }
    int maxProfit(vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2, vector<int>(3 ,0)));
        int n = prices.size();
        // Base Case 
        // If(cap == 0) return 0
        // for(int ind = 0;ind<=n-1;ind++){
        //     for(int buy = 0;buy<=1;+buy++){
        //         dp[ind][buy][0] = 0;
        //     }
        // }
        // // if(ind == n) retrun 0;
        // for(int buy  = 0;buy<=1;buy++){
        //     for(int cap = 0;cap<=2;cap++){
        //         dp[n][buy][cap] = 0;
        //     }
        // }
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){
                    if(buy == 1){
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap] , dp[ind+1][1][cap]);  
                        }
                    else{
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1] , dp[ind+1][0][cap]);
                    }
                    }
                }
            }
        return dp[0][1][2];
        }
        
        // return help(0,1,2 , prices , dp);
        // We have to optimise it by using a dp[n][2][3];
        
    
};