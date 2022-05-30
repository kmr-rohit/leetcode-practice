class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(begin(nums) , end(nums));
        int longest = 0;
        
        for(auto &num : s){
            int curr_longest = 1;
            for(int j = 1;s.count(num-j);j++){
                s.erase(num-j);
                curr_longest++;
                
            }
            for(int j = 1;s.count(num+j);j++){
                s.erase(num+j);
                curr_longest++;
                
            }
            longest = max(longest , curr_longest);
        }
     return longest;   
    }
};