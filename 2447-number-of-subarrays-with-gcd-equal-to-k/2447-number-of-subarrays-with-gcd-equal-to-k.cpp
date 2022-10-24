class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0;i  < nums.size();++i){
            int gcdt = 0;
            for(int j = i;j < nums.size() && (nums[j]%k == 0);++j){
                gcdt = gcd(nums[j],gcdt);
                if(gcdt == k) res++;
            }
        }
        return res;
    }
};