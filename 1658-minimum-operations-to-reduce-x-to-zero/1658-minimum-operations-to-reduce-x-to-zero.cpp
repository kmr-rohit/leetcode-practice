// // Recursive failed approach 
// int steps(vector<int> & nums , int k , int low , int high ){
//         if(low>high){
//             return 1e9-nums.size();
//         }
//         if(k == 0){
//             return 0;
//         }
//         if(k<0){
//             return 1e9-nums.size(); 
//         }
        
//         int x = steps(nums, k-nums[low] , low+1 , high )+1;
//         int y = steps(nums , k -nums[high] ,low , high-1 )+1;
        
//         return min(x ,y);
        
//     }
//     int minOperations(vector<int>& nums, int x) {
        
//         int ans = steps(nums ,x , 0 , nums.size()-1 );
        
//         if(ans>nums.size()){
//             return -1;
//         }
//         else{
//             return ans;
//         }
        
//     }

class Solution {
public:
    // Idea is to find a subarray whose sum is totalsum - x;
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), j = 0, sum = 0, maxlen = -1;
        int total = accumulate(begin(nums), end(nums), 0); // calculation of total sum 
        if(total < x) return -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum > total - x)
                sum -= nums[j++]; // picking first and last elements
            if(sum == total - x) 
                maxlen = max(maxlen, i - j + 1);
        }
        return maxlen == -1 ? -1 : n - maxlen;
    }
};