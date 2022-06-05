class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        else{
            vector<int> newnums(n/2 , -1);
            for(int i = 0;i<n/2;i++){
                if(i%2 == 0){
                    newnums[i] = min(nums[2*i] , nums[2*i +1]);
                }
                else{
                   newnums[i] = max(nums[2*i] , nums[2*i +1]); 
                }
            }
            return minMaxGame(newnums);
        }
        
    }
};