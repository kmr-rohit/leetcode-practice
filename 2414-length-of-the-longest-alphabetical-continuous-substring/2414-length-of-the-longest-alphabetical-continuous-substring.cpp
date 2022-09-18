class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i = -1;
        int j = 0;
        int ans = INT_MIN;
        int n = s.size();
        while(j<n){
            if(s[j+1] - s[j] == 1){
                j++;
            }
            else{
                ans = max(j-i  , ans);
                i = j;
                j++;
            }
        }
        
        return ans;
    }
};