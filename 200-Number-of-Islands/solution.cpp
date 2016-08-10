class Solution {
public:
    // int numIslands(vector<vector<char>>& grid) {
    //     int res = 0;
    //     if(grid.size()==0) return res;
    //     for(int i = 0; i < grid.size(); i++){
    //         for(int j = 0; j < grid[0].size(); j++){
    //             if(grid[i][j]=='1'){
    //                 search(grid, i, j);
    //                 res++;
    //             }
    //         }
    //     }
    //     return res;
    // }
    // void searchIsland(vector<vector<char>>& grid, int i, int j){
    //     grid[i][j]='0';
    //     // 搜索该点连通的上下左右
    //     if(i>0 && grid[i-1][j]=='1') searchIsland(grid, i-1, j);
    //     if(j>0 && grid[i][j-1]=='1') searchIsland(grid, i, j-1);
    //     if(i<(grid.size()-1) && grid[i+1][j]=='1') searchIsland(grid, i+1, j);
    //     if(j<(grid[0].size()-1) && grid[i][j+1]=='1') searchIsland(grid, i, j+1);
    // }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int len1 = grid.size();
        int len2 = grid[0].size();
        int count = 0;
        for(int i = 0; i < len1; i++)
            for(int j = 0; j < len2; j++){
                if(grid[i][j] == '1'){
                    search(grid, i, j);
                    count++;
                }
            }
        return count;
    }
    void search(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        if(i > 0 && grid[i-1][j] == '1')
            search(grid, i-1, j);
        if(((j + 1) < grid[0].size() )&&(grid[i][j+1] == '1'))
            search(grid, i, j+1);
        if(((i + 1) < grid.size() )&&(grid[i+1][j] == '1'))
            search(grid, i+1, j);
        if(((j - 1) >=0 )&&(grid[i][j-1] == '1'))
            search(grid, i, j-1);
    }
    // void searchIsland(vector<vector<char>>& grid, int i, int j){
    //     grid[i][j]='0';
    //     // 搜索该点连通的上下左右
    //     if(i>0 && grid[i-1][j]=='1') searchIsland(grid, i-1, j);
    //     if(j>0 && grid[i][j-1]=='1') searchIsland(grid, i, j-1);
    //     if(i<(grid.size()-1) && grid[i+1][j]=='1') searchIsland(grid, i+1, j);
    //     if(j<(grid[0].size()-1) && grid[i][j+1]=='1') searchIsland(grid, i, j+1);
    // }
};