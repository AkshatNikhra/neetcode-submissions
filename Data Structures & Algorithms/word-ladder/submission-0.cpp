typedef pair<int, int> iPair;
class Solution {
public:
    map<string, int> mp;
    bool canConnect(string a, string b){
        int n = a.length();
        int count = 0;
        for(int i=0;i<n;i++){
            if(a[i] != b[i]) count++;
        }
        return count == 1;
    }
    int djs(int N, string beginWord, string endWord, const vector<vector<int>>& edges){
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<int> dist(N, INT_MAX);
        pq.push({1, mp[beginWord]});
        dist[mp[beginWord]] = 1;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(int v:edges[u]){
                int weight = 1;
                if(dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return (dist[mp[endWord]] == INT_MAX ? 0 : dist[mp[endWord]]);
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ID = 0;
        wordList.push_back(beginWord);
        //wordList.push_back(endWord);
        int n = wordList.size();
        mp.clear();
        map<int, string> idMap;
        for(int i=0;i<n;i++){
            mp[wordList[i]] = ID;
            idMap[ID] = wordList[i];
            ID++;
        }
        if(mp.find(endWord) == mp.end()) return 0;
        vector<vector<int>> edges(ID);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(canConnect(wordList[i], wordList[j])){
                    edges[mp[wordList[i]]].push_back(mp[wordList[j]]);
                    edges[mp[wordList[j]]].push_back(mp[wordList[i]]);
                }
            }
        }
        for(int i=0;i<ID;i++){
            int sz = edges[i].size();
            cout << idMap[i] << " --> ";
            for(int j=0;j<sz;j++){
                cout << idMap[edges[i][j]] << " ";
            }
            cout << '\n';
        }
        return djs(ID, beginWord, endWord, edges);
    }
};
