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
        const int INF = 1e9 + 7;
        // initializeDSU(n + 1);
        // vector<vector<int>> edges;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        //         edges.push_back({dist, i, j});
        //     }
        // }
        // sort(edges.begin(), edges.end());
        // int ans = 0;
        // for(vector<int> p : edges){
        //     if(unionDSU(p[1], p[2])){
        //         ans += p[0];
        //     }
        // }
        // return ans;
        vector<int> dist(n, INF);
        vector<bool> vis(n, false);
        int edges = 0, res = 0, node = 0;
        while(edges < n - 1){
            vis[node] = true;
            int nextNode = -1;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                int curDist = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                dist[i] = min(dist[i], curDist);
                if(nextNode == -1 || dist[i] < dist[nextNode]) nextNode = i;
            }
            res += dist[nextNode];
            node = nextNode;
            edges++;
        }
        return res;
        
    }
};
