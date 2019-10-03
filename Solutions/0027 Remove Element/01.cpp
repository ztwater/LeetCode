//27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int start = 0;
        int end = nums.size()-1;
        while (start != end) {
        	if (nums[start] == val) {
        		nums[start] = nums[end];
        		end--;
        	}
        	else {
        		start++;
        	}
        }
        if (nums[start] == val) return start;
        return start+1;
    }
};