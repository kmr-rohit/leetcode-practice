
// Memoisation
// int getVal(vector<vector<int>> &mat, vector<vector<int>> &dp , int i=0, int j=0)
//     {
//         int n = mat.size();
//         int m = mat[0].size();    
        
//         if(i == n || j == m)    return 1e9; 
        
//         if(i == n-1 and j == m-1)
//             return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        
//         /// if we know the answer for this cell then no need to recalculate those, simply return those values 
//         if( dp[i][j] != 1e9)
//             return dp[i][j];
        
//         int IfWeGoRight = getVal(mat , dp , i , j+1);
//         int IfWeGoDown = getVal(mat , dp , i+1 , j);
        
//         int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        
//         /// before returning the values, we must store the answers for this cell which we hacve calculated
//         /// in next recurssive call this value will be used to save some computation, aka repetative work which we are doing.
//         dp[i][j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
//         return dp[i][j];
//     }
    
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
//         int n = dungeon.size();
//         int m = dungeon[0].size();
        
//         vector<vector<int>> dp(n , vector<int>(m , 1e9));
        
//         return getVal(dungeon, dp);     
//     }

class Solution{
    public:
    
    int calculateMinimumHP(vector<vector<int> > &dungeon) {

        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 1e9));
        dp[n][m - 1] = 1;
        dp[n - 1][m] = 1;
        
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--) 
            {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];                
                // store this value
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }
};

