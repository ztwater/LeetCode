//532. K-diff Pairs in an Array
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size <= 1) return 0;
        int pre = 0;
        int cur = 1;
        int d = 0;
        int last;
        while (pre < size && cur < size) {
        	if (nums[cur] - nums[pre] > k) {
        		if (cur - pre == 1) {
        			cur++;
        		}
        		pre++;
        	}
        	else if (nums[cur] - nums[pre] < k) cur++;
        	else {
        		if (d == 0 || last != nums[pre]) {
        			last = nums[pre];
        			d++;
        		}
        		pre++;
        		cur++;
        	}
        }
       	return d;
    }
};