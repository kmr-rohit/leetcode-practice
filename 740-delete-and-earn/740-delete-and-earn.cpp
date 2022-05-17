class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = *max_element(nums.begin(),nums.end());
        
        vector<int> freq(maxi+1,0);
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        
        vector<int> dp(maxi+1,0);
        dp[0] = 0;
        dp[1] = freq[1] * 1;
        for(int i=2;i<=maxi;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+freq[i]*i);
        }
        return dp[maxi];
    }
};