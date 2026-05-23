#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int x[4] = {0,-1,0,1};
    int y[4] = {-1,0,1,0};
    int vis[55][55];
    int cnt = 0;
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    void dfs(int r, int c, const vector<vector<int>>& grid){
        vis[r][c] = 1;
        cnt++;
        int n = grid.size();
        int m = grid[0].size();
        for(int dir=0;dir<4;dir++){
            int row = r + x[dir];
            int col = c + y[dir];
            if(isValid(row, col, n, m) && !vis[row][col] && grid[row][col] == 1){
                dfs(row, col, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt = 0;
                    dfs(i, j, grid);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
        
    }
};
