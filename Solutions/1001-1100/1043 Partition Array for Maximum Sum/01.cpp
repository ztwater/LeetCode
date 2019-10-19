//1043 Partition Array for Maximum Sum
class Solution {
public:
	int Find(int s, int e, vector<vector<int>>& dp, int K) {
		if (s > e) return 0;
		if (dp[s][e] >= 0) return dp[s][e];
		//if (s == e) return dp[s][e];
		if (e - s + 1 <= K) {
			int ma = 0;
			for (int i = s; i <= e; i++) {
				ma = max(ma, dp[i][i]);
			}
			dp[s][e] = (e - s + 1) * ma;
			return dp[s][e];
		}
		else {
			int ma = 0;
			for (int i = 0; i < K; i++) {
				int sum = Find(s, s + i, dp, K) + Find(s + i + 1, e, dp, K);
				ma = max(ma, sum);
			}
			dp[s][e] = ma;
			return dp[s][e];
		}
	}

    int maxSumAfterPartitioning(vector<int>& A, int K) {
    	int size = A.size();
        vector<vector<int>> dp(size, vector<int>(size, -1));
        for (int i = 0; i < size; i++) {
        	dp[i][i] = A[i];
        }
        return Find(0, size - 1, dp, K);
    }
};