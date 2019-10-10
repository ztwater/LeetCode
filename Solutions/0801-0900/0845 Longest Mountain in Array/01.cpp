//0845 Longest Mountain in Array
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int size = A.size();
        if (size < 3) return 0;
        int s = 0;
        int e = 1;
        int state = 0;
        int res = 0;
        for (e = 1; e < size; e++) {
        	if (state == 0) {
				if (A[e] <= A[e-1]) s = e;
				else state = 1;
        	}
        	else if (state == 1) {
        		if (A[e] == A[e-1]) {
        			state = 0;
        			s = e;
        		}
        		else if (A[e] < A[e-1]) {
        			state = 2;
                    cout << s << " " << e << endl;
        			res = max(res, e - s + 1);
        		}
        	}
        	else {
        		if (A[e] < A[e-1]) {
                    res = max(res, e - s + 1);
                    cout << s << " " << e << endl;
                }
        		else if (A[e] == A[e-1]){
        			state = 0;
        			s = e;
        		}
        		else {
        			state = 1;
        			s = e - 1;
        		}
        	}
        }
        return res;
    }
};