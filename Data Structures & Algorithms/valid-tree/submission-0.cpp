class Solution {
public:
    void dfsTraversal(int u, vector<bool>& vis, const vector<vector<int>>& graph){
        vis[u] = true;
        for(int v:graph[u]){
            if(!vis[v]){
                dfsTraversal(v, vis, graph);
            }
        }
    }
    bool isConnected(int n, const vector<vector<int>>& graph){
        vector<bool> vis(n, false);
        dfsTraversal(0, vis, graph);
        for(bool x:vis) {
            if(!x) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int sz = edges.size();
        for(int i=0;i<sz;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        return isConnected(n, graph) && sz == n - 1;
    }
};
