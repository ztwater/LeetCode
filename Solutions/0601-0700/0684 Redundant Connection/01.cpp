//0684 Redundant Connection
class Solution {
public:
	int find (int idx, vector<int>& p) {
		while (idx != p[idx]) {
			int tmp = p[idx];
			p[idx] = p[p[idx]];
			idx = tmp;
		}
		return idx;
	}

	int Union (int idx1, int idx2, vector<int>& p, vector<int>& rank) {
		int p1 = find(idx1, p);
		int p2 = find(idx2, p);
		if (p1 == p2) return 1;
		if (rank[p1] <= rank[p2]) {
			p[p1] = p2;
			if (rank[p1] == rank[p2]) {
				rank[p2]++;
			}
		}
		else {
			p[p2] = p1;
		}
		return 0;
	}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(1005,0);
        vector<int> rank(1005,0);
        int res = 0;
        for(int i = 0; i < edges.size(); i++) {
        	int v1 = edges[i][0];
        	int v2 = edges[i][1];
        	if (p[v1] == 0 && p[v2] == 0) {
        		p[v1] = v1;
        		p[v2] = v1;
        	} 
        	else if (p[v1] == 0) p[v1] = v2;
        	else if (p[v2] == 0) p[v2] = v1;
        	else {
        		int lab = Union(v1, v2, p, rank);
        		if (lab == 1) res = i;
        	}
        }
        return edges[res];
    }
};