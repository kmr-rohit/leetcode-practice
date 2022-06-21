class Solution {
public:
    vector<vector<int>>ans;
    
    void dfs(vector<int>&nums, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            dfs(nums, index+1);
            swap(nums[index],nums[i]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};