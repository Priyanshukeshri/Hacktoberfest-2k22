// Runtime: 3 ms, faster than 98.43% of C++ online submissions for Rotting Oranges.
// Memory Usage: 13.3 MB, less than 35.21% of C++ online submissions for Rotting Oranges.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j]==2) {
                    q.push({i, j});
                }
            }
        }
        
        vector<vector<bool>>visi(rows, vector<bool>(cols, false));
        
        int ctMins = 0;
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, -1, 0, 1};
        while(!q.empty()) {
            int size = q.size();
            bool couldMark = false;
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                for(int i=0;i<4;i++) {
                    int nrow = it.first+deltaRow[i];
                    int ncol = it.second+deltaCol[i];
                    if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && grid[nrow][ncol]==1 && visi[nrow][ncol]==false) {
                        visi[nrow][ncol] = true;
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        couldMark=true;
                    }
                }
            }
            if(couldMark)ctMins++;
        }
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j]==1)return -1;
            }
        }
        return ctMins;
        
    }
};
