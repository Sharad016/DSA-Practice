class Solution {
private:
    void dfs(int r , int c , vector<vector<int>> &visit , vector<vector<int>> &grid , int &area){
        visit[r][c] = 1;
        area++;
        int n = grid.size();
        int m = grid[0].size();
        int row[4] = {1,0,-1,0};
        int col[4] = {0,-1,0,1};
        for(int i = 0 ; i<4 ; i++){
            int nrow = r + row[i];
            int ncol = c + col[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visit[nrow][ncol]==0){
                dfs(nrow , ncol , visit , grid , area);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int>(m , 0));
        int area = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ;j++){
                int i_area = 0;
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    dfs(i , j , visited , grid , i_area);
                    area = max(area , i_area);
                }
            }
        }
        return area;
    }
};
