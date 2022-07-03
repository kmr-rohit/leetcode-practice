class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(high>=low){
            int mid = (high + low)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target> nums[mid]){
                low++;
            }
            else{
                high--;
            }
        }
        return low;
    }
};