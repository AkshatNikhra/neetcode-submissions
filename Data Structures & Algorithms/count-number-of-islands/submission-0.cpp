#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vis[102][102];
    int x[4] = {0,-1,0,1};
    int y[4] = {-1,0,1,0};
    bool isValid(int r, int c, int n, int m){
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
    void dfs(int r, int c, const vector<vector<char>>& grid){
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int dir=0;dir<4;dir++){
            int row = r + x[dir];
            int col = c + y[dir];
            if(isValid(row, col, n, m) && !vis[row][col] && grid[row][col] == '1'){
                dfs(row, col, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        // vector<vector<bool>> vis(n, vector<int>(m, 0));
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
