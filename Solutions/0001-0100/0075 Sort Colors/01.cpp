//0075 Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return;
        int start = 0;
        int end = size - 1;
        int i = start;
        int cnt = 0;
        while (cnt < size) {
        	if (nums[i] == 0) {
        		nums[start] = 0;
        		start++;
        		cnt++;
        		i++;
        	}
        	else if (nums[i] == 2) {
        		while (cnt < size && nums[end] == 2) {
        			end--;
        			cnt++;
        		}
        		if (cnt == size) return;
        		nums[i] = nums[end];
        		nums[end] = 2;
        		end--;
        	}
        	else {
        		cnt++;
        		i++;
        	}
        }
        while (start <= end) {
        	nums[start] = 1;
        	start++;
        }
        return;
    }
};