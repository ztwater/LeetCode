class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> res;
        if (size < 4) return res;
        sort(nums.begin(), nums.end());
        int s1 = 0;
        int e1 = size - 1;
        while (s1 < e1 - 2) {
        	if (nums[s1] + nums[e1-2] + nums[e1-1] + nums[e1] < target) s1++;
        	else if (nums[s1] + nums[s1+1] + nums[s1+2] + nums[e1] > target) e1--;
        	else {
        		int tmp1 = s1;
        		int tmp2 = e1;
        		twoSum(s1, s1+1, e1-1, e1, res, nums, target);
        		tmp2--;
        		while (s1 < tmp2 - 2) {
        			while (nums[tmp2] == nums[tmp2+1]) tmp2--;
        			twoSum(s1, s1+1, tmp2-1, tmp2, res, nums, target);
                    tmp2--;
        		}
        		tmp1++;
        		while (tmp1 < e1 - 2) {
        			while (nums[tmp1] == nums[tmp1-1]) tmp1++;
        			twoSum(tmp1, tmp1+1, e1-1, e1, res, nums, target);
                    tmp1++;
        		}
                e1--;
        		while (s1 < e1 - 2 && nums[e1] == nums[e1+1]) e1--;
        		s1++;
                while (s1 < e1 - 2 && nums[s1] == nums[s1-1]) s1++;
        	}
        }
        sort(res.begin(),res.end());
        return res;
    }

    void twoSum(int s1, int s2, int e2, int e1, vector<vector<int>>& res, vector<int>& nums, int target) {
    	while (s2 < e2) {
			if (nums[s1] + nums[s2] + nums[e2] + nums[e1] < target) s2++;
			else if (nums[s1] + nums[s2] + nums[e2] + nums[e1] > target) e2--;
			else {
				vector<int> tmp{nums[s1], nums[s2], nums[e2], nums[e1]};
				res.push_back(tmp);
				while (s2 < e2 - 1 && nums[s2] == nums[s2+1]) s2++;
				s2++;
			}
		}
        return;
    }
};