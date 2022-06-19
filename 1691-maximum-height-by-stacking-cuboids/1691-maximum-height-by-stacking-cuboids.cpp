class Solution {
public:
    int dp[101][102] = {};
int dfs(vector<vector<int>>& cubs, int p, int l) {
    if (p < 0)
        return 0;
    if (dp[p][l] > 1)
        return dp[p][l] - 1;
    int res = dfs(cubs, p - 1, l);
    if (l == 101 || (cubs[p][0] <= cubs[l][0] && cubs[p][1] <= cubs[l][1] && cubs[p][2] <= cubs[l][2]))
        res = max(res, cubs[p][2] + dfs(cubs, p - 1, p));
    dp[p][l] = res + 1;
    return res;  
}
int maxHeight(vector<vector<int>>& cubs) {
    for (auto &c : cubs)
      sort(begin(c), end(c));
    sort(begin(cubs), end(cubs));
    return dfs(cubs, cubs.size() - 1, 101);
}
};