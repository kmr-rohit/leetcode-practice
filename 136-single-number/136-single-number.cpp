class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        for(auto x: m){
            if(x.second == 1){
                ans = x.first; 
            }
        }
        return ans;
    }
};