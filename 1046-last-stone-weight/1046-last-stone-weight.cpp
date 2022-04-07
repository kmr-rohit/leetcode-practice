class Solution {
public:
    void solve(vector<int>& nums){
      
      if(nums[1] !=0){
        if(nums[0] > nums[1]){
          nums[0] = nums[0] - nums[1];
          nums[1] = 0;

        }
        else if(nums[0] == nums[1]){
          nums[0] = nums[1] =0;
        }
        sort(nums.begin() , nums.end(), greater<int>());
       
        solve(nums);
        
      }
      else{
        return;
      }
                                
      
      
      
    }
    int lastStoneWeight(vector<int>& stones) {
      sort(stones.begin() , stones.end() , greater<int>());
      if(stones.size() >1){
          solve(stones);
      }
      return stones[0];
      
        
    }
};