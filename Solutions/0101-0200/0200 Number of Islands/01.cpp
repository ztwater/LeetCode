//0200 Number of Islands
class Solution {
public:
	int Find(int idx, vector<int>&p) {
		while (idx != p[idx]) {
			int tmp = p[idx];
			p[idx] = p[tmp];
			idx = tmp;
		}
		return idx;
	}

	void Union(int idx1, int idx2, vector<int>&p, vector<int>&rank) {
		int p1 = Find(idx1, p);
		int p2 = Find(idx2, p);
		if (p1 == p2) return;
		if (rank[p1] == rank[p2]) {
			p[p1] = p2;
			if (rank[p1] == rank[p2]) rank[p2]++;
		}
		else p[p2] = p1;
		return;
	}

    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        if (w == 0) return 0;
        vector<int> p;
        vector<int> rank;
        for (int i = 0; i < h; i++) {
        	for (int j = 0; j < w; j++) {
        		p.push_back(i * w + j);
        		rank.push_back(0);
        	}
        }
        for (int i = 0; i < h; i++) {
        	for (int j = 0; j < w; j++) {
        		if (grid[i][j] == '1') {
        			if (i > 0 && grid[i-1][j] == '1') Union((i-1)*w+j, i*w+j, p, rank);
        			if (j > 0 && grid[i][j-1] == '1') Union(i*w+j-1, i*w+j, p, rank);
        		}
        	}
        }
        int sum = 0;
        for (int i = 0; i < h; i++) {
        	for (int j = 0; j < w; j++) { 
        		int index = i * w + j;
        		if (grid[i][j] == '1' && p[index] == index) sum++; 
        	}
        }
        return sum;
    }
};