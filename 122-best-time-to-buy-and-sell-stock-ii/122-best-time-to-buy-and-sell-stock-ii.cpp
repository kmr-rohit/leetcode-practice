class Solution {
public:
    int help(int ind  , int buy ,vector<int>& nums,  vector<vector<int>>&dp){
        if(ind == nums.size()){
            return 0;
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        int profit = 0;
        // IF we are liberted to buy a stock
        if(buy == 1){
            profit += max(-nums[ind]+help(ind+1 , 0 , nums , dp) , 0+help(ind+1 ,1 , nums , dp));
        }
        else{
            profit += max(nums[ind] + help(ind+1 , 1 , nums,dp) , help(ind+1 , 0, nums,dp));
        }
        return dp[ind][buy] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() , vector<int>(2 ,-1));
        
        return help(0 , 1 , prices ,dp);
    }
};