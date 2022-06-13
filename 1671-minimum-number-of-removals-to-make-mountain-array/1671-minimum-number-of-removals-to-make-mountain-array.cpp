class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size=nums.size();
        vector<int> lis(size,1);
        for(int i=0;i<size;i++){
            int maxYet=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    maxYet=max(maxYet,lis[j]);
                }
            }
            lis[i]=maxYet+1;
        }
        vector<int> ldp(size,1);
        for(int i=size-2;i>=0;i--){
            int maxYet=0;
            for(int j=size-1;j>i;j--){
                if(nums[j]<nums[i]){
                    maxYet=max(maxYet,ldp[j]);
                }
            }
            ldp[i]=maxYet+1;
        }
        int ans=0;
        for(int i=1;i<size-1;i++){
		//bcz there might be a condition where the sum is higher but its not a mountain( \ ) but we have to choose a mountain( ^ ).
            if(lis[i]>1 && ldp[i]>1)
            ans=max(ans,(lis[i]+ldp[i])-1);
        }
        return size-ans;
    }
};