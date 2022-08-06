class Solution {
public:
    void dfs( int i , vector<int> &vis  , vector<int> edges[]){
        
        vis[i] = 1;
        for(auto &it:edges[i]){
            if(!vis[it]){
                dfs(it , vis , edges);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        
        
        if(n-1<=c.size()){
            int no = 0;
            vector<int> vis(n , 0);
            vector<int> edges[n];
            for(int i = 0;i<c.size();i++){
                int v = c[i][0];
                int u = c[i][1];
                
                edges[u].push_back(v);
                edges[v].push_back(u);
            }
            
            for(int i = 0;i<n;i++){
                if(!vis[i]){
                    
                    dfs(i , vis  , edges);
                    no++;
                    }
                }
            return no-1;
            }
        return -1;
        }
};