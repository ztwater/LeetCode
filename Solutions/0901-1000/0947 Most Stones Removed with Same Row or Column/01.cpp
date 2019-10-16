//0947 Most Stones Removed with Same Row or Column
class Solution {
public:
	/**
	 * dfs
	 */
	void dfs(int x, int y, int d, int& step, vector<vector<int>>& plane) {
		plane[x][y]--;
		for (int i = 0; i < d + 1; i++) {
			if (plane[x][i]) {
				step++;
				dfs(x, i, d, step, plane);
			}
			if (plane[i][y]) {
				step++;
				dfs(i, y, d, step, plane);
			}
		}
		return;
	}

    int removeStones(vector<vector<int>>& stones) {
        int size = stones.size();
        int d = 0;
        int step = 0;
        vector<vector<int>> plane(1005, vector<int>(1005, 0));   
        for (int i = 0; i < size; i++) {
        	d = max(max(stones[i][0], stones[i][1]), d);
        	plane[stones[i][0]][stones[i][1]] = 1;
        }
        for (int i = 0; i < d + 1; i++) {
        	for (int j = 0; j < d + 1; j++) {
        		if (plane[i][j]) {
        			dfs(i, j, d, step, plane);
        		}
        	}
        }
        return step;
    }   
};