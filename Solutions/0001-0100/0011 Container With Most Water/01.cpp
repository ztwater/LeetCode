//0011 Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int s = 0;
        int e = size - 1;
        int left = s;
        int right = e;
        int max = min(height[s], height[e]) * (e - s); 
        while (s < e) {
        	if (height[s] <= height[e]) {
        		s++;
        		while (height[s] <= height[s-1] && s < e) s++;
        	}
    		else{
    			e--;
    			while (height[e] <= height[e+1] && s < e) e--;
    		} 
    		if (s >= e) break;
    		else {
    			int vol = min(height[s], height[e]) * (e - s);
    			max = max(max, vol);
    		}
        }
    }
};