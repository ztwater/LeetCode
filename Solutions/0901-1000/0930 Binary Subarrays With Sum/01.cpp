//0930 Binary Subarrays With Sum
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int size = A.size();
        if (size == 0) return 0;
        vector<int> v;
        int tmp = 0;
        for (int i = 0; i < size; i++) {
        	if (A[i] == 0) tmp++;
        	else {
        		v.push_back(tmp);
        		tmp = 0;
        	}
        }
        v.push_back(tmp);
        int sum = 0;
        if (S == 0) {
        	for (auto it = v.begin(); it != v.end(); it++) {
                int k = *it;
        		sum += k * (k+1) / 2;
        	}
        }
        else {
        	if (S > v.size() - 1) return 0;
        	else {
        		int s = 0;
        		int e = S;
        		while (e < v.size()) {
        			sum += (v[s] + 1) * (v[e] + 1);
                    s++;
                    e++;
        		}
        	}
        }
        return sum;
    }
};