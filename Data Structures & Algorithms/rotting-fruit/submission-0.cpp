class Solution {
public:
    int x[4] = {0,-1,0,1};
    int y[4] = {-1,0,1,0};
    bool isValid(int r, int c, int n, int m){
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int fresh = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) { 
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        while(fresh && !q.empty()){
            ans++;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<int,int> p = q.front();
                q.pop();
                for(int dir=0;dir<4;dir++){
                    int r = p.first + x[dir];
                    int c = p.second + y[dir];
                    if(isValid(r, c, n, m) && !vis[r][c] && grid[r][c] == 1){
                        vis[r][c] = true;
                        q.push({r, c});
                        fresh--;
                    }
                }
            }
        }
        if(fresh > 0) return -1;
        return ans;
    }
};
