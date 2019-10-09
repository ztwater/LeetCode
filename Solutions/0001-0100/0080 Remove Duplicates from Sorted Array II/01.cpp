//0080 Remove Duplicates from Sorted Array II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) return size;
        int slow = 0;
        int fast = 0;
        int last = 0;
        for (fast = 0; fast < size; fast++) {
        	if (fast == 0) {
        		last = 1;
        		continue;
        	}
        	if (nums[fast] != nums[slow]) {
        		last = 1;
        		nums[++slow] = nums[fast];
        	}
        	else {
        		if (last == 1) {
        			nums[++slow] = nums[fast];
        			last++;
        		}
        		else {
        			last++;
        		}
        	}
        }
        return slow + 1;
    }
};