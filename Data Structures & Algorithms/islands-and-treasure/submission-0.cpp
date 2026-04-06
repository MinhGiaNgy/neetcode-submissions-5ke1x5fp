class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> khobau;
        int dir[4][2] =  {{0,1}, {0,-1}, {1, 0}, {-1,0}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    khobau.push({i, j});
                }
            }
        }
        while(!khobau.empty()){
            int cr = khobau.front().first;
            int cc = khobau.front().second;
            khobau.pop();
            for(int i = 0; i < 4; i++){
                int nr = cr + dir[i][0];
                int nc = cc + dir[i][1];
                if(nr < 0 || nc < 0 || nr > m - 1 || nc > n-1){
                    continue;
                }
                if(grid[nr][nc] == 2147483647){
                    grid[nr][nc] = grid[cr][cc] + 1;
                    khobau.push({nr, nc});
                }
            }
        }
        return;
    }
};
