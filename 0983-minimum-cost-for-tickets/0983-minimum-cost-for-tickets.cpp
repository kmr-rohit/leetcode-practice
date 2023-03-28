class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        int j = i;
        while (j < n && days[j] < days[i] + 7) j++;
        int k = i;
        while (k < n && days[k] < days[i] + 30) k++;
        dp[i] = min({dp[i+1] + costs[0], dp[j] + costs[1], dp[k] + costs[2]});
    }
    return dp[0];
}

};