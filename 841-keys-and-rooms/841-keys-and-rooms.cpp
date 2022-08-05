// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         vector<int> keys(rooms.size() , 0);
//         int cnt = 1;
//         keys[0] =1;
        
//         queue<int> q;
//         q.push(0);
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
            
//             for(int i =0;i<rooms[node].size();i++){
//                 if(keys[rooms[node][i]]!=1){
//                     keys[rooms[node][i]] = 1;
//                     q.push(rooms[node][i]);
//                     cnt++;
//                 }
//             }
//         }
        
//         return (cnt == rooms.size());
        
        
//     }
// };


class Solution {
public:
    void dfs(int curr, vector<int>& vis, vector<vector<int>>& rooms) {
        vis[curr] = 1;
        for(auto i : rooms[curr]) {
            if(!vis[i]) dfs(i, vis, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n);
        dfs(0, vis, rooms);
        for(int i=0;i<n;i++) {
            if(!vis[i]) return false;
        }
        return true;
    }
};