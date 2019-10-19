//1202 Smallest String With Swaps
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
		else p[p2] = p1;
		return;
	}

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> p;
        vector<int> rank;
        string res = s;
        for (int i = 0; i < s.size(); i++) {
        	p.push_back(i);
        	rank.push_back(0);
        }
        for (int i = 0; i < pairs.size(); i++) {
        	Union(pairs[i][0], pairs[i][1], p, rank);
        }
        unordered_map<int, vector<char>> m;
        unordered_map<int, int> ptr;
        for (int i = 0; i < p.size(); i++) {
        	p[i] = Find(i, p);
        	if (m.find(p[i]) == m.end()) {
        		vector<char> tmp;
        		tmp.push_back(s[i]);
        		m[p[i]] = tmp;
                ptr[p[i]] = 0;
        	}
        	else {
        		m[p[i]].push_back(s[i]);
        	}
        }
        for (auto it = m.begin(); it != m.end(); it++) {
        	sort(it->second.begin(), it->second.end());
        }
        for (int i = 0; i < p.size(); i++) {
        	int pos = ptr[p[i]]++;
        	res[i] = m[p[i]][pos];
        }
        return res;
    }
};