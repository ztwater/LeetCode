//1004 Max Consecutive Ones III
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int size = A.size();
        int start = 0;
        int end = 0;
        int max = 0;
        int tmp = 0;
        queue<int> q;
        while (end < size) {
        	if (A[end] == 0){
        		if (K == 0) start = end + 1;
        		else if (q.size() >= K) {
        			start = q.front() + 1;
        			q.pop();
        			q.push(end);
        		}
        		else q.push(end);
        	}
        	end++;
        	tmp = end - start;
        	max = max > tmp ? max : tmp;
        }
        return max;
    }
};