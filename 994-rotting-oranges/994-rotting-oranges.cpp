class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int R = grid.size();
        int C = grid[0].size();
        int cnt = 0;
        
        queue<pair<int , int >> q;
        for(int i=0;i<R;i++){
            for(int j = 0;j<C;j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        
        vector<int> xdir = {-1 , 1 , 0 , 0};
        vector<int> ydir = {0 , 0 , -1 , 1};
        
        if(cnt == 0){
            return 0;
        }
        else{
            while(!q.empty()){
                int size = q.size();
                
                while(size--){
                    pair<int , int> p = q.front();
                    q.pop();
                    for(int i =0;i<4;i++){
                        int currx = p.first + xdir[i];
                        int curry = p.second + ydir[i];
                        
                        if(currx >= 0 && curry >= 0 && currx<R && curry <C && grid[currx][curry] == 1 ){
                            grid[currx][curry] = 2;
                            q.push({currx , curry});
                        }
                    }
                }
                
                if(q.size() != 0){
                    time++;
                }
            }
            
            for(int i =0;i<R;i++){
                for(int j = 0;j<C;j++){
                    if(grid[i][j] == 1){
                        return -1;
                    }
                }
            }
            
            return time;
        }
    }
};