class Solution {
    vector<vector<vector<int>>> dparr;
    int N;
    int dp(int r1, int c1, int c2, vector<vector<int>> &grid)
    {
        int r2 = r1+c1-c2;
        if(r1==N ||r2==N||c1==N||c2==N||grid[r1][c1]==-1||grid[r2][c2]==-1)
            return INT_MIN;
        else if(r1==N-1 && c1==N-1)
            return grid[r1][c1];
        else if(dparr[r1][c1][c2]!=-1)
            return dparr[r1][c1][c2];
        else
        {
            int ans = grid[r1][c1];
            if(r1!=r2 || c1!=c2)
                ans+=grid[r2][c2];
            ans+=max({dp(r1, c1+1, c2+1, grid), dp(r1+1, c1, c2+1, grid), dp(r1, c1+1, c2, grid), dp(r1+1, c1, c2, grid)});
            dparr[r1][c1][c2] = ans;
            return ans;
        }
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        dparr.resize(N, vector<vector<int>>(N, vector<int>(N, -1)));
        return max(0, dp(0, 0, 0, grid));
    }
};