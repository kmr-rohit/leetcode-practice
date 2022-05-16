class Solution {
public:
    int solve(int ind , vector<int> &num , int target, vector<vector<int>>& dp){
	if(ind == 0){
		if(target % num[0] == 0){
			return target/num[0];
		}
		else{
			return 1e9;
        }	
	}
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        int not_taken = 0+solve(ind-1 , num , target,dp);
		int taken = 1e9;
		if(num[ind] <= target){
			taken = 1 + solve(ind , num, target - num[ind],dp);
		}
		
		return dp[ind][target] = min(taken , not_taken);
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        int ans = solve(n-1,coins , amount , dp);
        if(ans >= 1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};