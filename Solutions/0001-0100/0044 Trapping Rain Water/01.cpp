//0044 Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size <= 2) return 0;
        int slow = 0;
        int fast = 0;
        int sum = 0;
        while(1) {
	        while (slow < size - 1) {
	        	if (height[slow+1] >= height[slow]) slow++;
	        	else break;
	        }
	        if (slow >= size - 2) return sum;
	        fast = -1;
	        int tmp = slow + 2;
	    	while (tmp < size) {
	    		if (height[tmp] >= height[slow]) {
	    			fast = tmp;
	    			break;
	    		}
	    		if (height[tmp] > height[tmp-1]) {
	    			if (fast == -1 || height[tmp] > height[fast]) fast = tmp;
	    			tmp++;
	    		}
	    		else {
	    			tmp++;
	    		}
	    	}
	    	if (fast == -1) return sum;
	    	else {
	    		int m = min(height[fast], height[slow]);
	    		for (int i = slow + 1; i < fast; i++) {
                    if (height[i] < m) sum += m - height[i];
	    		}
	    	}
	    	slow = fast;
        }
    } 
};
//[5,4,1,2]