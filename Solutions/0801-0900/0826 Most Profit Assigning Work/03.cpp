//0826 Most Profit Assigning Work
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v;
        for (int i = 0; i < difficulty.size(); i++) {
            pair<int, int> tmp = make_pair(difficulty[i], profit[i]);
            v.push_back(tmp);
        } 
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        int ma = 0;
        int sum = 0;
        auto it = v.begin();
        for (int i = 0; i < worker.size(); i++) {
            while (it != v.end() && it->first <= worker[i]) {
                ma = max(ma, it->second);
                it++;
            };
            sum += ma;
        }
        return sum;
    }
};