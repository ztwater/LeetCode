//844. Backspace String Compare
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int size = S.size();
    	int slow = -1;
    	int fast = 0;
    	while(fast < size) {
    		if (S[fast] == '#') {
    			if (slow >= 0) slow--;
    			fast++;
    		}
    		else {
    			slow++;
    			S[slow] = S[fast];
    			fast++;
    		}
    	}
    	int len1 = slow;
        size = T.size();
        slow = -1;
        fast = 0;
        while(fast < size) {
    		if (T[fast] == '#') {
    			if (slow >= 0) slow--;
    			fast++;
    		}
    		else {
    			slow++;
    			T[slow] = T[fast];
    			fast++;
    		}
    	}
    	int len2 = slow;
    	if (len1 != len2) return false;
    	for (int i = 0; i <= len1; i++) {
    		if (S[i] != T[i]) return false;
    	}
    	return true;
    }

};