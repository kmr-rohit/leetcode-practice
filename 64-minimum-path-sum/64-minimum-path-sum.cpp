class Solution {
public:
    vector<vector<int>> output;
    int minPathSumHelper(vector<vector<int>>& grid , int i,int j){
       int m=grid.size();
        int n=grid[0].size();
       
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(i>=m || j>=n){
            return INT_MAX;
        }
    if(output[i][j] != -1){
        return output[i][j];
    }
        int x= minPathSumHelper(grid,i+1,j);
       
        int z= minPathSumHelper(grid,i,j+1);
        int ans= min(x,z)+grid[i][j];
        
        output[i][j] = ans;
        return output[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
      int i=0;
        int j=0;
        int m=grid.size();
        int n=grid[0].size();
       if(m==1 and n==1)
            return grid[0][0];
        output.resize(m,vector<int>(n,-1));
        minPathSumHelper(grid,i,j); 
        return output[i][j];
    }
	

};