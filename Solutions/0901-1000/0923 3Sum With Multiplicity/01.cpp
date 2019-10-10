//0923 3Sum With Multiplicity
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
    	int size = A.size();
    	sort(A.begin(), A.end());
    	int sum = 0;
        for (int i = 0; i < size - 2; i++) {
        	int s = i + 1;
        	int e = size - 1;
        	while (s < e) {
        		if (A[i] + A[s] + A[e] < target) {
        			s++;
        		}
        		else if (A[i] + A[s] + A[e] > target) {
        			e--;
        		}
        		else {
                    if (A[s] != A[e]) {
                    	int b = 1, c = 1;
                        while (A[s] == A[s+1]) {
                            s++;
                            b++;
                        }
                        while (A[e] == A[e-1]) {
                            e--;
                            c++;
                        }
                        s++;
                        e--;
                        sum = (sum + b * c) % 1000000007;
                    }
                    else {
                    	int tmp = 1;
                        tmp =  (e - s + 1) * (e - s) / 2;
                    	sum = (sum + tmp) % 1000000007;
                        break;
                    }
        		}
        	}
        }
        return sum;
    }
};