//0713 Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    	if (k == 0) return 0;
        int size = nums.size();
        int s = 0;
        int e = 0;
        int prod = 1;
        int cnt = 0;
        while (e < size) {
        	if (prod * nums[e] < k) {
        		prod *= nums[e];
        		e++;
        		cnt++;
        	}
        	else {
                if (e == s) {
                    s++;
                    e++;
                    continue;
                }
        		prod /= nums[s];
        		s++;
        		cnt += e - s;
        	}
        }
        while (s < e) {
        	s++;
        	cnt += e - s;
        }
        return cnt;
    }
};