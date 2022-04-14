class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size  = nums.size();
  for (int step = 0; step < (size-1); ++step) {
    int swapped = 0;
    for (int i = 0; i < (size-step-1); ++i) {
      if (nums[i] > nums[i + 1]) {
        int temp = nums[i];
        nums[i] = nums[i + 1];
        nums[i + 1] = temp;
        
        swapped = 1;
      }
    }

    if (swapped == 0)
      break;
  }
        
    }
};