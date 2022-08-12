class Solution {
public:
   bool checkPartition(vector<int>& nums, int i, int n, vector<int> &dp)
{
    //If we reach the end of the array
    if(i == n) return dp[i] = true;
    
    //return memoized answer  if it exists
    if(dp[i]!=-1) return dp[i];
    
    //We have 2 cases 
    //Case 1 is we have two equal consequtive numbers 
    //Case 2 is we have three equal consequtive numbers
    //We need to check if a valid partition is formed if we take case1 and solve for the remaining array or 
    //if we take case2 and solve for the remaining array
    // example1:  [4,4,4,5,6] Case1 = [4,4 | 4,5,6] OR Case2 = [4,4,4 | 5,6] --> Case 1 gives us our valid partition
    // example2:  [4,4,4,1,1] Case1 = [4,4 | 4,1,1] OR Case2 = [4,4,4 | 1,1] --> Case 2 gives us our valid partition
    
    //Here check1 => Case1 ; check2 => Case2
    int check1 =false, check2=false;
    
    
    //This is the 3rd given case
    // in this case we check for consequtive numbers with difference of 1 and if so we solve for the remaining array
    
    if(i+1 < n && i + 2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) 
        return dp[i] = checkPartition(nums,i+3,n,dp);
    
    if(i+1 < n && nums[i] == nums[i+1])
    {
        check1 = checkPartition(nums,i+2,n,dp);
    
        if(i+2 < n && nums[i] == nums[i+2])
            check2 = checkPartition(nums,i+3,n,dp);
    }
        
    return dp[i] = (check1 or check2);
}

bool validPartition(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n+1,-1);
    return checkPartition(nums,0,n,dp);
}
};