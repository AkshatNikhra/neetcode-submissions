class Solution {
public:
    int x[4] = {0,-1,0,1};
    int y[4] = {-1,0,1,0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        
        queue<pair<int,int>> pacQ, atlQ;
        
        for(int i=0;i<m;i++){
            pacQ.push({0, i});
            atlQ.push({n-1, i});
        }

        for(int i=0;i<n;i++){
            pacQ.push({i, 0});
            atlQ.push({i, m-1});
        }

        bfs(pacQ, pac, heights);
        bfs(atlQ, atl, heights);

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;


    }

    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& ocean, const vector<vector<int>> heights){
        int n = heights.size();
        int m = heights[0].size();
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            ocean[r][c] = true;
            for(int dir=0;dir<4;dir++){
                int row = r + x[dir];
                int col = c + y[dir];
                if(isValid(row, col, n, m) && !ocean[row][col] && heights[row][col] >= heights[r][c]){
                    q.push({row, col});
                }
            }
        }
    }
};
