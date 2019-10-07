//1219 Path with Maximum Gold
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        int ma = 0;
        for(int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 0) continue;
                else ma = max(ma, visit(i, j, w, h, grid));
            }
        }
        return ma;
    }
    int visit(int x, int y, int& w, int& h, vector<vector<int>>& grid) {
        if (grid[x][y] == 0) return 0;
        int tmp = grid[x][y];
        grid[x][y] = 0;
        int s1 = 0;
        if (x != 0) s1 = max(s1, tmp + visit(x-1, y, w, h, grid));
        if (x != h-1) s1 = max(s1, tmp + visit(x+1, y, w, h, grid));
        if (y != 0) s1 = max(s1, tmp + visit(x, y-1, w, h, grid));
        if (y != w-1) s1 = max(s1, tmp + visit(x, y+1, w, h, grid));
        grid[x][y] = tmp;
        return s1;
    }
};  