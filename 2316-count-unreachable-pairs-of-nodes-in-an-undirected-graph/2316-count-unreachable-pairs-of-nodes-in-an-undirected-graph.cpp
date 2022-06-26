#define ll long long


class Solution {
    
    void dfs(ll pnt,vector<vector<ll>>& adj,vector<bool>&vis,ll& ans){
        vis[pnt]=1;
        
        ans++;
        
        for(auto it:adj[pnt]){
            if(!vis[it])dfs(it,adj,vis,ans);
        }
    }
    
    
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        
        vector<vector<ll>>adj(n,vector<ll>());
        
        vector<bool>vis(n,0);
        
        for(auto it:edges){
            adj[it[0]].push_back((ll)it[1]);
            adj[it[1]].push_back((ll)it[0]);
        }
        
        ll ans=0;
        
        ll sum=0;
        
        for(ll i=0;i<n;i++){
            if(!vis[i]){
                ll tmp=0;
                dfs(i,adj,vis,tmp);
                ans+=(tmp*sum);
                sum+=tmp;
            }
        }
        
        return ans;
        
        
    }
};