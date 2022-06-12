class Solution {
public:
    
    //Problem is equavilant to find subset with unique and maximum sum 
    
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0,curr=0;
        unordered_set<int> s;
        int i=0,j=0,n=nums.size();
        while(i<n&&j<n){
            if(s.find(nums[j])==s.end()){
                curr+=nums[j];
                s.insert(nums[j++]);
                sum=max(sum,curr);
            }
            else{
                curr-=nums[i];
                s.erase(nums[i++]);
            }
        }
        return sum;
    }
};