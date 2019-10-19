//1043 Partition Array for Maximum Sum
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
    	int size = A.size();
        vector<int> dp(size, 0);
        int ma = 0;
        for (int i = 0; i < size; i++) {
        	if (i < K) {
        		ma = max(ma, A[i]);
        		dp[i] = ma * (i + 1);
        	}
        	else {
        		int maa = 0;
        		for (int j = 0; j < K; j++) {
        			maa = max(maa, A[i-j])
					dp[i] = max(dp[i], dp[i-j-1] + (j+1) * maa);
				}
        	}
        }
        return dp[size-1];
    }
};