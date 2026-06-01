class Solution {
public:
    int N = 101;
    void dfs(int u, vector<bool>& vis, const vector<set<int>>& graph){
        vis[u] = true;
        for(auto v:graph[u]){
            if(!vis[v]){
                dfs(v, vis, graph);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int sz = edges.size();
        vector<set<int>> graph(N);
        vector<bool> vis(sz, false);
        for(int i=0;i<sz;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        for(int i=sz-1;i>=0;i--){
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].erase(b);
            graph[b].erase(a);
            vis.clear();
            vis.assign(N, false);
            dfs(a, vis, graph);
            if(vis[b]) return edges[i];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        return {};
    }
};
