//0130 Surrounded Regions
class Solution {
public:
	void dfs(int x, int y, vector<vector<char>>& board) {
        int h = board.size();
        int w = board[0].size();
        board[x][y] = ' ';
		if (x > 0 && board[x-1][y] == 'O') dfs(x-1, y, board);
		if (x < h - 1 && board[x+1][y] == 'O') dfs(x+1, y, board);
		if (y > 0 && board[x][y-1] == 'O') dfs(x, y-1, board);
		if (y < w - 1 && board[x][y+1] == 'O') dfs(x, y+1, board);
		return;
	}

    void solve(vector<vector<char>>& board) {
        int h = board.size();
        if (h <= 2) return;
        int w = board[0].size();
        if (w <= 2) return;
        for (int i = 1; i < w - 1; i++) {
        	if (board[0][i] == 'O') dfs(0, i, board);
        	if (board[h-1][i] == 'O')dfs(h-1, i, board);
        }
        for (int i = 1; i < h - 1; i++) {
        	if (board[i][0] == 'O') dfs(i, 0, board);
        	if (board[i][w-1] == 'O')dfs(i, w-1, board);
        }
        for (int i = 0; i < h; i++) {
        	for (int j = 0; j < w; j++) {
        		if (board[i][j] == 'O' && i > 0 && i < h - 1 && j > 0 && j < w - 1) board[i][j] = 'X';
        		else if (board[i][j] == ' ') board[i][j] = 'O';
        	}
        }
        return;
    }
};