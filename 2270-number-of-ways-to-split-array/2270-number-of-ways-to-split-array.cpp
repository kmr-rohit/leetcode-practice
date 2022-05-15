class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefixarr;
        long long temp = 0;
        long long sum = 0;
        for(int i =0;i<nums.size();i++){
            sum = sum +  nums[i];
            long long ans = temp+nums[i];
            prefixarr.push_back(ans);
            temp = temp+nums[i];
            
        }
        
        long long count = 0;
        
        for(int i = 0;i<nums.size()-1;i++){
            if(prefixarr[i] >= sum - prefixarr[i]){
                count++;
            }
        }
        return count;
        
    }
};