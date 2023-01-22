class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = -1;
        int size = max(nums1[nums1.size()-1] , nums2[nums2.size() - 1]);
        vector<bool> commonArr(size+1 , false);
        for(int i =0;i<nums1.size();i++){
            commonArr[nums1[i]] = true;
        }
        for(int i = 0;i<nums2.size();i++){
            if(commonArr[nums2[i]] == true){
            ans = nums2[i];
            break;
        }
        }
    return ans;
    }
};