class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> edges(numCourses + 1);
        vector<int> indegree(numCourses);

        for(int i=0;i<n;i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            edges[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v:edges[u]){
                indegree[v]--;
                
                if(indegree[v] == 0) q.push(v);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i] != 0) return false;
        }
        return true;
        

    }
};
