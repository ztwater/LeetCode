//344. Reverse String
class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        if (size <= 1) return;
        for (int i = 0; i < size / 2; i++) {
        	char tmp = s[i];
        	s[i] = s[size - i - 1];
        	s[size - i - 1] = tmp;
        }
        return;
    }
};