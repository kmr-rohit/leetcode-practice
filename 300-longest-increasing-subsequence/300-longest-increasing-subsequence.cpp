//Space optimised Code
//          int n = nums.size();
//         vector<int> next(n+1,0) , curr(n+1 , 0);
        
//         // base case 
//         for(int ind = n-1;ind>=0;ind--  ){
//             for(int prev = ind-1;prev>=-1;prev--){
//                 int len = 0+next[prev+1];
//                 if(nums[ind]>nums[prev] || prev == -1){
//                    len = max(1+next[ind+1],len); 
//                 }

//                 curr[prev+1] = len; 
                
//             }
//             next = curr;
//         }
        
//         return next[0];
        
//     }

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1);
        int maxi = 1;
        for(int ind = 0;ind<=n-1;ind++){
            for(int prev = 0;prev<=ind-1;prev++){
                if(nums[ind]>nums[prev]){
                    dp[ind] = max(1 + dp[prev] , dp[ind]);
                }
                maxi = max(maxi , dp[ind]);
            }
        }
        return maxi;
    }
};