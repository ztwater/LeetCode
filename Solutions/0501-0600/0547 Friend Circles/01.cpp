//0547 Friend Circles
class Solution {
public:
	int Find(int idx, vector<int>&p) {
		while (idx != p[idx]) {
			int tmp = p[idx];
			p[idx] = p[p[idx]];
			idx = p[idx];
		}
		return idx;
	}

	void Union(int idx1, int idx2, vector<int>&p, vector<int>&rank) {
		int p1 = Find(idx1, p);
		int p2 = Find(idx2, p);
		if (p1 == p2) return;
		if (rank[p1] <= rank[p2]) {
			p[p1] = p2;
			if (rank[p1] == rank[p2]) {
				rank[p2]++;
			}
		}
		else p[p2] = p1;
		return;
	}

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> p;
        vector<int> rank(n,0);
        int g = 0;
        for (int i = 0; i < n; i++) {
        	p.push_back(i);
        }
        for (int i = 0; i < n; i++) {
        	for (int j = i + 1; j < n; j++) {
        		if (M[i][j] == 1) Union(i, j, p, rank);
        	}
        }
        for (int i = 0; i < n; i++) {
        	if (i == p[i]) g++;
        }
        return g;
    }
};