class Solution {
public:

    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> matrix(n , vector<int>(n , 1));
        
        for(auto x:mines){
            matrix[x[0]][x[1]] = 0;
        }
        
        
        // we will mantain 4 diffrent matrixs top , left, right , bottom at any cordinate x , y 
        // they will denote the max contious value of ones respectively
        
        vector<vector<int>> up , left , right , bottom ;
        
        bottom = up = left = right = matrix;
        
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int y = n-1-j;
                int x =n-1-i;
                if(j>0 && matrix[i][j]) left[i][j] += left[i][j-1];
                if(i>0 && matrix[i][j]) up[i][j] += up[i-1][j];
                if(y<n-1 && matrix[x][y]) right[x][y] += right[x][y+1];
                if(x<n-1 && matrix[x][y]) bottom[x][y] += bottom[x+1][y];
                
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                ans = max(ans , min({left[i][j] , up[i][j] , bottom[i][j] ,right[i][j]}));
            }
        }
        return ans;
    }
};