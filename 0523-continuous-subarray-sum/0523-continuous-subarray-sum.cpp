class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        
        unordered_map<int , int> m;
        bool ans = false;
        for(int i = 0; i<n;i++){
        int prefSum = prefix[i]%k;
        if(prefSum == 0 && i) ans = true;
        if(m.find(prefSum) != m.end())  // Found the required prefix sum 
        {
          if(i - m[prefSum] > 1) ans = true; // check if atleast 2 elements are there or not
        }
        else m[prefSum] = i;
      }
        
        return ans;
    }
};