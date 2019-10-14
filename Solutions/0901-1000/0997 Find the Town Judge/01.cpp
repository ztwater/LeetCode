//0997 Find the Town Judge
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int size = trust.size();
        vector<int> v(N+ 1, 0);
        for (int i = 0; i < size; i++) {
        	v[trust[i][0]]--;
        	v[trust[i][1]]++;
        }
        for (int i = 1; i <= N; i++) {
        	if (v[i] == N - 1) return i;
        }
        return -1;
    }
};