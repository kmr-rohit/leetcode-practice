class Solution {
public:
    
    int numSubmatrixSumTarget(vector<vector<int>>& M, int T) {
        int n = M.size();
        int m = M[0].size();
        int ans = 0;
        unordered_map<int, int> res;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                M[i][j] += M[i][j-1];
                }
        }
        
        for(int j = 0;j<m;j++){
            for(int k = j;k<m;k++){
                res.clear();
                res[0] = 1;
                int currsum = 0;
                for(int i = 0;i<n;i++){
                    currsum += M[i][k] - (j ? M[i][j-1] : 0);
                    ans = ans + (res.find(currsum - T) != res.end() ? res[currsum- T]:0);
                    res[currsum]++;
                     
                }
            }
        }
        return ans;
        
    }
};