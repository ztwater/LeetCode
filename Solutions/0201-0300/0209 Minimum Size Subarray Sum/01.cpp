//0209 Minimum Size Subarray Sum 1522
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int mi = size + 1;
        int start = 0;
        int sum = 0;
        int end = 0;
        while (end < size) {
        	if (sum < s) {
                sum += nums[end];
                end++;
            }
            else {
                while (start < end && sum >= s) {
                    sum -= nums[start];
                    start++;
                }
                mi = min(mi, end - start + 1);
            }
        }
        while (sum >= s) {
            sum -= nums[start];
            start++;
        }
        mi = min(mi, end - start + 1);
        if (mi == size + 1) return 0;
        return mi;
    }
};