//0990 Satisfiability of Equality Equation
class Solution {
public:
	int Find(int idx, vector<int>& p) {
		while (idx != p[idx]) {
			int tmp = p[idx];
			p[idx] = p[tmp];
			idx = tmp;
		}
		return idx;
	}

	void Union(int idx1, int idx2, vector<int>& p, vector<int>& rank) {
		int p1 = Find(idx1, p);
		int p2 = Find(idx2, p);
		if (p1 == p2) return;
		if (rank[p1] <= rank[p2]) {
			p[p1] = p2;
			if (rank[p1] == rank[p2]) rank[p2]++;
		}
		else {
			p[p2] = p1;
		}
		return;
	}
	
    bool equationsPossible(vector<string>& equations) {
        int size = equations.size();
        vector<int> p;
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++) {
        	p.push_back(i);
        }
        for (int i = 0; i < size; i++) {
        	if (equations[i][1] == '=') {
        		int c1 = equations[i][0] - 'a';
	        	int c2 = equations[i][3] - 'a';
	        	Union(c1, c2, p, rank);
        	}
        }
        for (int i = 0; i < size; i++) {
        	if (equations[i][1] == '!') {
        		int c1 = equations[i][0] - 'a';
	        	int c2 = equations[i][3] - 'a';
	        	if (Find(c1, p) == Find(c2, p)) return false;
        	}
        }
        return true;
    }
};