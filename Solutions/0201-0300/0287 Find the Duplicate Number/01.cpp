//0287 Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (nums[slow] != nums[fast]) {
        	slow = nums[slow];
        	fast = nums[nums[fast]];
        }
        slow = nums[slow];
        fast = 0;
        while (slow != fast) {
        	slow = nums[slow];
        	fast = nums[fast];
        }
        return slow;
    }
};