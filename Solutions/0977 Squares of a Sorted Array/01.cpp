//977. Squares of a Sorted Array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size = A.size();
        vector<int> res(size);
        int start = 0;
        int end = size-1;
        int n = size-1;
        for (int i = 0; i < size; i++) {
        	int a = A[start] * A[start];
        	int b = A[end] * A[end];
        	if (a >= b) {
        		res[n--] = a;
        		start++;
        	}
        	else {
        		res[n--] = b;
        		end--;
        	}
        }
        return res;
    }
};