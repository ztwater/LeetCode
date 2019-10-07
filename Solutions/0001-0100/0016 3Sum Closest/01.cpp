//0016 3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int closest = 2147483647;
        int res;
        if (size < 3) return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++) {
        	int left = i + 1;
        	int right = size - 1;
        	while (left < right) {
        		int sum = nums[left] + nums[right] + nums[i];
        		if (sum > target) {
        			right--;
                    if (sum - target < closest) {
                        closest = sum - target;
                        res = sum; 
                    }
        		}
        		else {
        			left++;
                    if (target - sum < closest) {
                        closest = target - sum;
                        res = sum; 
                    }
        		}
                cout << closest << " " << res << endl;
        	}
        }
        return res;
    }
};