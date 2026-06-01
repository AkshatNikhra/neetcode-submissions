class Solution {
public:
    void connectAll(int u, vector<bool>& vis, const vector<vector<int>>& graph){
        vis[u] = true;
        for(int v:graph[u]){
            if(!vis[v]){
                connectAll(v, vis, graph);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                connectAll(i, vis, graph);
            }
        }
        return ans;
    }
};
