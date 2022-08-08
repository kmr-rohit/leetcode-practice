class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int , int>> q;
        for(int i =0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(mat[i][j] == 0){
                    q.emplace(i , j);
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        int R = mat.size();
        int C = mat[0].size();
        
        vector<int> xdir = {1 , -1 , 0 , 0};
        vector<int> ydir = {0 , 0 , 1 , -1};
        
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            
            for(int i = 0;i<4;i++){
                int nx = p.first + xdir[i];
                int ny = p.second + ydir[i];
                
                if(nx < 0 || ny < 0 || nx == R || ny == C || mat[nx][ny] != -1){
                    continue;
                }
                    mat[nx][ny] = 1 + mat[p.first][p.second];
                    q.emplace(nx , ny);
                
            }
        }
        
        return mat;
    }
};