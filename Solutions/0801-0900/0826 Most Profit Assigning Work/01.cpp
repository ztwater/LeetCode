//0826 Most Profit Assigning Work
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int> m;
        for (int i = 0; i < profit.size(); i++) {
        	if (m.find(profit[i]) == m.end()) {
        		m[profit[i]] = difficulty[i];
        	}
        	else {
        		int tmp = m[profit[i]];
        		m[profit[i]] = min(tmp, difficulty[i]);
        	}
        } 
        sort(worker.begin(), worker.end());
        reverse(worker.begin(), worker.end());
        int p = 0;
        int sum = 0;
        auto it = m.end();
        it--;
        while (p < worker.size() && it != m.begin()) {
        	if (it->second <= worker[p]) {
        		sum += it->first;
        		p++;
        	}
        	else it--;
        }
        while (p < worker.size()) {
            if (it->second <= worker[p]) sum += it->first;
            p++;
        }
        return sum;
    }
};