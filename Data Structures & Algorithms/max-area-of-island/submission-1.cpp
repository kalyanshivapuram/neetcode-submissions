class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();
    int max_area = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 1) {
                int current_area = 0;
                sink(grid, r, c, current_area);
                max_area = max(max_area, current_area);
            }
        }
    }
    return max_area;
    }
private:
    void sink(vector<vector<int>>& grid, int r, int c, int& current_area) {
        if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size()) return;
        if (grid[r][c] != 1) return;

        grid[r][c] = 0;
        current_area++;                          // count this cell
        sink(grid, r + 1, c, current_area);
        sink(grid, r - 1, c, current_area);
        sink(grid, r, c + 1, current_area);
        sink(grid, r, c - 1, current_area);
    }
};
