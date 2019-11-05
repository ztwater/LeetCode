//0743 Network Delay Time
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> A(N+1, vector<int>(N+1, -1));
        vector<int> delay(N+1, INT_MAX);
        for (int i = 1; i <= N; i++) {
        	A[i][i] = 0;
        }
        for (int i = 0; i < times.size(); i++) {
        	A[times[i][0]][times[i][1]] = times[i][2];
        }
        vector<int> visit(N+1, 0);
        delay[K] = 0;
        visit[K] = 1;
        for (int k = 0; k < N; k++) {
        	int m = INT_MAX;
        	int cur = 0;
        	for (int i = 1; i <= N; i++) {
        		if (visit[i] == 1) {
        			if (delay[i] < m) {
	        			cur = i;
	        			m = delay[i];
	        		}
        		}
        	}
        	if (cur == 0) break;
        	visit[cur] = 2;
        	for (int i = 1; i <= N; i++) {
        		if (A[cur][i] == -1) continue;
        		if (delay[i] > delay[cur] + A[cur][i]) {
        			delay[i] = delay[cur] + A[cur][i];
        			visit[i] = 1;
        		}
        	}
        }
        int res = 0;
        for (int i = 1; i <= N; i++) {
        	if (visit[i] != 2) return -1;
        	res = res > delay[i] ? res : delay[i];
        }
        return res;
    }
};