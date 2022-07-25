class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -1;
        // 2 observation 
        // one the left and right half is sorted or not 
        // if it is .... the is our target laying in that range
        
        
        while(low<= high){
            int mid = (low+high)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            else if(nums[low] <= nums[mid]){ // left half is sorted
                if(target>= nums[low] && target <= nums[mid]){ // laying in between the left sorted half
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{ // right half is sorted 
                
                if(target>= nums[mid] && target<= nums[high]){ // target laying in right half
                    
                    low = mid + 1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        
        return -1;
    }
};