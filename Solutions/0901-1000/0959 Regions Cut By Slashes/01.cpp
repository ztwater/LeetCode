//0959 Regions Cut By Slashes
class Solution {
public:
	int find (int index, vector<int>& p) {
		while (index != p[index]) {
			int tmp = p[index];
			p[index] = p[p[index]];
			index = tmp;
		}
		return index;
	}

	void Union (int idx1, int idx2, vector<int>& p, vector<int>& rank) {
		int p1 = find(idx1, p);
		int p2 = find(idx2, p);

		if (p1 == p2) return;

		if (rank[p1] <= rank[p2]) {
			p[p1] = p2;
			if (rank[p1] == rank[p2]) rank[p2]++;
		} 
		else {
			p[p2] = p1;
		}
	}

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = 4 * n * n;
        vector<int> p;
        vector<int> rank(size, 0);
        for (int i = 0; i < size; i++) {
        	p.push_back(i);
        }

        for (int i = 0; i < n; i++) {
        	string row = grid[i];
        	for (int j = 0; j < n; j++) {
        		int up = ((i - 1) * n + j) * 4;
				int down = ((i + 1) * n + j) * 4;
				int left = (i * n + j - 1) * 4;
				int right = (i * n + j + 1) * 4;
        		if (i != 0) Union(idx, up + 3, p, rank);
    			if (i != n - 1) Union(idx + 3, down, p, rank);
    			if (j != 0) Union(idx + 1, left + 2, p, rank);
    			if (j != n - 1) Union(idx + 2, right + 1, p, rank);
        		if (row[j] == ' ') {
        			int idx = (i * n + j) * 4;
        			Union(idx, idx + 1, p, rank);
        			Union(idx, idx + 2, p, rank);
        			Union(idx, idx + 3, p, rank);
        		}
        		else if (row[j] == '/') Union(idx, idx + 1, p, rank);
        		else Union(idx + 2, idx + 3, p, rank);
        	}
        }
        int s = 0;
        for (int i = 0; i < size; i++) {
        	if (i == p[i]) s++;
        }
        return s;
    }
};