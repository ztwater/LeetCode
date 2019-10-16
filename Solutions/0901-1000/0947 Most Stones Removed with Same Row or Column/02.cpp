//0947 Most Stones Removed with Same Row or Column
//0947 Most Stones Removed with Same Row or Column
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

    int removeStones(vector<vector<int>>& stones) {
        int size = stones.size();
        unordered_set<int> s;
        vector<int> p;
        vector<int> rank(20005, 0);
        for (int i = 0; i < 20005; i++) {
        	p.push_back(i);
        }
        int step = 0;
        for (int i = 0; i < size; i++) {
        	Union(stones[i][0], stones[i][1] + 10000, p, rank);
        }
        for (int i = 0; i < size; i++) {
        	if (s.find(p[stones[i][0]]) == s.end()) {
        		s.insert(p[stones[i][0]]);
        	}
        	else {
        		step++;
        	}
        }
        return step;
    }
};