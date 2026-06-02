typedef pair<int,int> iPair;
class Solution {
public:
    int djs(int N, int src, const vector<vector<iPair>>& edges){
        vector<int> dist(N, INT_MAX);
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(iPair p : edges[u]){
                int v = p.first;
                int w = p.second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ma = INT_MIN;
        for(int i=1;i<N;i++){
            ma = max(ma, dist[i]);
        }
        return (ma == INT_MAX ? -1 : ma);
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<iPair>> edges(n + 1);
        int sz = times.size();
        for(int i=0;i<sz;i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            edges[u].push_back({v, w});
        }
        return djs(n + 1, k, edges);
    }
};
