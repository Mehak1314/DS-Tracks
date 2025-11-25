class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {

        // out of boundary or water -> stop
        if (i < 0 || j < 0 || 
            i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == '0')
            return;

        grid[i][j] = '0'; // mark land as visited

        // check all 4 directions
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == '1') {  // found a new island
                    count++;
                    dfs(grid, i, j);      // remove the whole island
                }
            }
        }

        return count;
    }
};
