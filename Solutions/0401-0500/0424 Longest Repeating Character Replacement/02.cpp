//0424 Longest Repeating Character Replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int size = s.size();
        int ma = 0;
        int tmp = 0;
        int start = 0;
        for (int end = 0; end < size; end++) {
            int index = s[end] - 'A';
            v[index]++;
            tmp = max(tmp, v[index]);
            while (end - start + 1 - k > tmp) {
                v[s[start]]--;
                start++;
            } 
            ma = max(ma, end - start + 1);
        }
        return ma;
    }
};