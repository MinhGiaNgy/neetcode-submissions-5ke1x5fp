class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> valid;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        if(n < 3 || m < 3){
            return;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0 || j == n - 1 || i == 0 || i == m -1){
                    if(board[i][j] == 'O'){
                        valid.push({i, j});
                        visited[i][j] = true;
                        board[i][j] = 'n'; 
                    }  
                }
            }
        }

        while(!valid.empty()){
            auto curr = valid.front();
            valid.pop();
            int cr = curr.first;
            int cc = curr.second;
            for(int i = 0; i < 4; i++){
                int nr = cr + dir[i][0];
                int nc = cc + dir[i][1];
                if(nr > m - 1 || nr < 0 || nc > n - 1 || nc < 0) continue;
                if(visited[nr][nc]) continue;
                if(board[nr][nc] == 'O'){
                    board[nr][nc] = 'n';
                    valid.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'n'){
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};