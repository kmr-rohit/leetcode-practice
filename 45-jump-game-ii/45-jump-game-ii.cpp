class Solution {
public:
    int solve(vector<int>&nums , int ind , vector<int> &dp){
        if(ind >= nums.size()-1){
            return 0;
        }
        if(dp[ind] != INT_MAX-1){
            return dp[ind]; 
        }
        for(int i = 1 ; i<=nums[ind] ; i++){
            dp[ind] = min(dp[ind] , 1 + solve(nums , ind +i , dp));
            
        }
        return dp[ind];
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() , INT_MAX-1);
        return solve(nums  , 0 , dp);
    }
};