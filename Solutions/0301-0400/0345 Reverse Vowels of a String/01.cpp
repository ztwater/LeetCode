//345. Reverse Vowels of a String
class Solution {
public:
    string reverseVowels(string s) {
    	int size = s.size();
    	if (size <= 1) return s;
    	int start = 0;
    	int end = size - 1;
    	while (1) {
    		while (!isVowel(s[start]) && start < end) {
    			start++;
    		}
    		while (!isVowel(s[end]) && start < end) {
    			end--;
    		}
    		if (start >= end) return s;
    		else {
    			char tmp = s[start];
    			s[start] = s[end];
    			s[end] = tmp;
    			start++;
    			end--;
    		}
    	}
    }

    bool isVowel(char c) {
    	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
    		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    		return true;
    	}
    	else {
    		return false;
    	}
    }
};
