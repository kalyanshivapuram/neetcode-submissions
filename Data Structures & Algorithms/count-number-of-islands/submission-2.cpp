class Solution {
    void sink(vector<vector<char>>& grid ,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()){
            return;
        }
        if(grid[r][c]!='1') return;
        grid[r][c]='0';
        sink(grid,r+1,c);
        sink(grid,r-1,c);
        sink(grid,r,c+1);
        sink(grid,r,c-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0) return 0;
        int cols = grid[0].size();
        int islands=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]=='1'){
                    islands++;
                    sink(grid,r,c);
                }

            }
        }
        return islands;

    }
};
