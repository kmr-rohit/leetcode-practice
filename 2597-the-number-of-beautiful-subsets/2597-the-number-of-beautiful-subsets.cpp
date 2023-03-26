class Solution {
public:
    int solve(int idx , vector<int>&nums , int k , unordered_map<int , int > &mp){
        if(idx == nums.size()){
            return 1;
        }
        
        
        int pick = 0 ;
        int not_pick = 0;
        
        // picking it to consider in our arr 
        // we have to check wheater we can take it or not 
        
        if(mp[nums[idx] - k] == 0){
            mp[nums[idx]]++;
            pick = solve(idx + 1 , nums , k ,mp);
            mp[nums[idx]]--;
        }
        
        not_pick = solve(idx + 1 , nums , k , mp);
        
        return pick + not_pick;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        
        unordered_map<int , int> mp;
        sort(nums.begin() , nums.end());
        
        return solve(0 , nums , k  , mp) - 1 ;
        
    }
};