//0721 Accounts Merge
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
		if (rank[p1] <= rank[p2]) {
			p[p1] = p2;
			if (rank[p1] == rank[p2]) rank[p2]++;
		}
		else {
			p[p2] = p1;
		}
		return;
	}

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        vector<int> p;
        vector<int> rank;
        vector<string> owner;
        vector<string> name;
        int idx = 0;
        for (int i = 0; i < accounts.size(); i++) {
    		int lab; //which one to merge
        	for (int j = 1; j < accounts[i].size(); j++) {
        		auto tmp = m.find(accounts[i][j]);
        		if (tmp == m.end()) {
        			m[accounts[i][j]] = idx;
        			p.push_back(idx);
        			rank.push_back(0);
        			owner.push_back(accounts[i][0]);
        			name.push_back(accounts[i][j]);
        			if (j == 1) lab = idx;
        			else Union(lab, idx, p, rank); //merge to first one or existed one
        			idx++;
                    
        		}
        		else {
                    int k = m[accounts[i][j]];
        			if (j != 1) Union(k, lab, p, rank); //merge the first to the existed one
        			lab = k;
        		} 
        	}
        }
        int pos = 0;
        unordered_map<int, int> m2;
        for (int i = 0; i < idx; i++) {
        	int root = Find(i, p);
        	auto tmp = m2.find(root);
        	if (tmp == m2.end()) {
        		vector<string> s;
        		s.push_back(owner[i]);
        		s.push_back(name[i]);
        		res.push_back(s);
        		m2[root] = pos;
        		pos++;
        	}
        	else {
                int k = m2[root];
        		res[k].push_back(name[i]);
        	}
        }
        for (int i = 0; i < res.size(); i++) {
        	sort(res[i].begin()+1, res[i].end());
        }
        return res;
    }
};