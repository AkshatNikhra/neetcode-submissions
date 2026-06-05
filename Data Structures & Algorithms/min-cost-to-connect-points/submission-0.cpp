class Solution {
public:
    vector<int> parent, sz;
    void initializeDSU(int n){
        parent.clear();
        sz.clear();
        parent.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] != node){
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }
    bool unionDSU(int u, int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        if(parent_u == parent_v) return false;
        if(sz[parent_u] < sz[parent_v]) swap(parent_u, parent_v);

        sz[parent_u] += sz[parent_v];
        parent[parent_v] = parent_u;
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        initializeDSU(n + 1);
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(vector<int> p : edges){
            if(unionDSU(p[1], p[2])){
                ans += p[0];
            }
        }
        return ans;
        
    }
};
