class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = needle.size();
        if (size == 0) return 0;
        int* next = new int[size];
        makeNext(next, size, needle);
        int p = 0, q = 0;
        while (p < size && q < haystack.size()) {
        	if (needle[p] == haystack[q]) {
        		p++;
        		q++;
        	}
        	else {
        		if (next[p] == -1) {
        			p = 0;
        			q++;
        		}
        		else {
        			p = next[p];
        		}
        	}
        }
        if (p == size) return q - size;
        return -1;
    }
    void makeNext(int* next, int size, string needle) {
    	next[0] = -1;
    	int i = 0;
    	int j = next[i];
    	while (i < size-1) {
    		if (j == -1 || needle[i] == needle[j]) {
    			next[++i] = ++j;
    			if (needle[i] == needle[j]) {
    				next[i] = next[j];
    			}
    		}
    		else {
    			j = next[j];
    		}
    	}
    }
};