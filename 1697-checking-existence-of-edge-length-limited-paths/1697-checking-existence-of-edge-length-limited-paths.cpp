class Solution {
public:
    class DisjointSet {
        vector<int> rank, parent;
    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        bool unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
                return true;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
                return true;
            }
            else if(rank[ulp_v] == rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
                return true;
            }
            return false;
        }
};

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        DisjointSet dsu(n);
        
        for(int i=0;i<queries.size();i++)
            queries[i].push_back(i);
    
        sort(queries.begin(), queries.end(), [&](auto const &a, auto const &b){
            return a[2] < b[2];
        });
        sort(edgeList.begin(), edgeList.end(), [&](auto const &a, auto const &b){
            return a[2] < b[2];
        });
        
        int i=0;
        vector<bool> res(queries.size(), false);
        for(auto q: queries){
            while(i<edgeList.size() && edgeList[i][2]<q[2]){
                dsu.unionByRank(edgeList[i][0] , edgeList[i][1]);
                i++;
            }
            
            if(dsu.findUPar(q[0]) == dsu.findUPar(q[1]))
                res[q[3]] = true;
        }
        
        return res;
    }
};