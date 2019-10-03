//283. Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int size = nums.size();
    	if (size <= 1) return;
        int p1 = 0;
        int p2 = 0;
        while (p2 < size) {
        	if (nums[p2] != 0) {
        		nums[p1] = nums[p2];
        		p1++;
        	}
        	p2++;
        }
        while (p1 < size) {
        	nums[p1] = 0;
         	p1++;
        }
        return;
    }
};