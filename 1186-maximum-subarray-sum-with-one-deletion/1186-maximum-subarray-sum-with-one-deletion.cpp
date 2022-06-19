class Solution {
public:
    int maximumSum(vector<int>& arr) {
        optional<int> dp0;
        int dp1 = arr[0], ans = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            dp0 = dp0 ? max(dp1, *dp0 + arr[i]) : dp1;
            dp1 = max(arr[i], dp1 + arr[i]);
            ans = max(ans, max(*dp0, dp1));
        }
        return ans;
    }
};