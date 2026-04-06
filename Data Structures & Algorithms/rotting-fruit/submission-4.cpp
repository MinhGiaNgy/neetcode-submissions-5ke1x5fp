class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int ,int>> bfs; 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    bfs.push({i, j});
                    visited[i][j] = true;
                    
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;
        if(bfs.empty()) return -1;
        
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int time = -1;
        while(!bfs.empty()){
            int rag = bfs.size();
            for(int j = 0; j < rag; j++){
            int cr = bfs.front().first;
            int cc = bfs.front().second;
            bfs.pop();
            for(int i = 0; i < 4;i ++){
                int nr = cr + dir[i][0];
                int nc = cc + dir[i][1];
                
                if(nr > m -1 || nr < 0 || nc < 0 || nc > n-1) continue;
                if(visited[nr][nc] || grid[nr][nc] == 2) continue;
                if(grid[nr][nc] == 1)
                {
                    fresh--;
                    grid[nr][nc] = 2;
                    visited[nr][nc] = true;
                    bfs.push({nr, nc});
                }
            }
            }
            time++;

        }
        if(fresh > 0){
            return -1;
        }
        return time;
    }
};
