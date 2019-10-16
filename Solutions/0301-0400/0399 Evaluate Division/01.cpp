//0399 Evaluate Division
class Solution {
public:
	int Find(int idx, vector<int>& p, vector<double>& val, double& prod) {
		//how many times idx is bigger than root
		prod *= val[idx];
		while (idx != p[idx]) {
			int tmp = p[idx];
			prod *= val[tmp];
			//update the value of the path when do the path splitting
			val[idx] *= val[tmp];
			p[idx] = p[tmp];
			idx = tmp;
		}
		return idx;
	}

	void Union(int idx1, int idx2, vector<int>& p, vector<int>& rank, vector<double>& val, double& d) {
		double prod1 = 1;
		double prod2 = 1;
		int p1 = Find(idx1, p, val, prod1);
		int p2 = Find(idx2, p, val, prod2);
		if (p1 == p2) return;
		if (rank[p1] <= rank[p2]) {
			p[p1] = p2;
			val[p1] = d * prod2 / prod1;
			if (rank[p1] == rank[p2]) rank[p2]++;
		}
		else {
			p[p2] = p1;
			val[p2] = prod1 / prod2 / d;
		}
		return;
	}

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> m;
        vector<int> p;
        vector<int> rank;
        vector<double> val;
        vector<double> res;
        int idx = 0;
        for (int i = 0; i < equations.size(); i++) {
        	int idx1, idx2;
        	if (m.find(equations[i][0]) == m.end()) {
        		m[equations[i][0]] = idx;
        		p.push_back(idx);
        		rank.push_back(0);
        		val.push_back(1.0);
        		idx1 = idx;
        		idx++;
        	}
        	else idx1 = m[equations[i][0]];
        	if (m.find(equations[i][1]) == m.end()) {
        		m[equations[i][1]] = idx;
        		p.push_back(idx);
        		rank.push_back(0);
        		val.push_back(1.0);
        		idx2 = idx;
        		idx++;
        	}
        	else idx2 = m[equations[i][1]];
        	Union(idx1, idx2, p, rank, val, values[i]);
        }
        for (int i = 0; i < queries.size(); i++) {
        	if (m.find(queries[i][0]) == m.end() || m.find(queries[i][1]) == m.end()) {
        		res.push_back(-1.0);
        	}
        	else {
        		int idx1 = m[queries[i][0]];
        		int idx2 = m[queries[i][1]];
        		double prod1 = 1;
				double prod2 = 1;
        		int p1 = Find(idx1, p, val, prod1);
        		int p2 = Find(idx2, p, val, prod2);
        		if (p1 == p2) {
        			res.push_back(prod1 / prod2);
        		}
        		else res.push_back(-1.0);
        	}
        }
        return res;
    }
};