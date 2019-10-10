//0713 Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    	if (k <= 1) return 0;
        int size = nums.size();
        int s = 0;
        int e = 0;
        int prod = 1;
        int cnt = 0;
        while (e < size) {
            prod *= nums[e];
        	while (prod * nums[e] <= k) {
        		prod /= nums[s];
        		s++;
        	}
            e++;
            cnt += e - s;
        }
        return cnt;
    }
};