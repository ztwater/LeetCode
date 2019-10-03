//125. Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
    	int size = s.size();
    	if (size == 0) return true;
    	int start = 0;
    	int end = size - 1;
    	while (start < end) {
    		while (!isValid(s[start]) && start < size-1) {
    			start++;
    		}
    		while (!isValid(s[end]) && end > 0) {
    			end--;
    		}         
            if (start >= end) return true;
    		if (lower(s[start]) != lower(s[end])) {
    			return false;
    		}
            else {
                start++;
                end--;
            }
    	}
    	return true;
    }
    bool isValid (char c) {
    	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || (c <= '9' && c >= '0')) {
    		return true;
    	}
    	else return false;
    }
    
    char lower (char c) {
        if (c <= 'Z' && c >= 'A') {
            return (c - 'A' + 'a');
        }
        return c;
    }
};