class Solution {
public:
  void solve(int ind , int target , vector<vector<int>> &ans , vector<int> &ds , vector<int> &candidates){
    if(ind == candidates.size()){
      if(target == 0){
        ans.push_back(ds);
      }
      return;
    }
    
    // picking ind element
    if(candidates[ind] <= target){
      ds.push_back(candidates[ind]);
      solve(ind , target - candidates[ind] , ans , ds, candidates);
      ds.pop_back(); 
    }
    
    // non picking ind element
    solve(ind+1 , target , ans  ,ds , candidates);
    
    
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> ds;
      vector<vector<int>> ans;
      solve(0 , target , ans , ds ,candidates);
      return ans;
      
      
        
    }
};