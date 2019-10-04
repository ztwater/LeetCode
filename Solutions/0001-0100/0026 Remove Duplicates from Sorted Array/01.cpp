class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1) return len;
        int i = 1;
        int j = 0;
        for (i = 1; i < len; i++) {
        	if (nums[i] != nums[j]) {
        		j++;
        		nums[j] = nums[i];
        	}
        }
        return j+1;
    }
};