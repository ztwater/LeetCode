//0826 Most Profit Assigning Work
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> bucket(100005, 0);
        for (int i = 0; i < difficulty.size(); i++) {
            int tmp = bucket[difficulty[i]];
            bucket[difficulty[i]] = max(tmp, profit[i]);
        } 
        for (int i = 1; i < 100005; i++) {
            bucket[i] = max(bucket[i], bucket[i-1]);
        } 
        int sum = 0;
        for (int i = 0; i < worker.size(); i++) {
            sum += bucket[worker[i]];
        }
        return sum;
    }
};