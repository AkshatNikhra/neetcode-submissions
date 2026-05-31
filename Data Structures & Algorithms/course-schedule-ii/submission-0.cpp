class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            edges[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int v:edges[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i] != 0) return {};
        }
        return ans;
    }
};
