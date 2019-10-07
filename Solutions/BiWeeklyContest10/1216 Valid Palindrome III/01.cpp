//1216 Valid Palindrome III
class Solution {
public:
    int getK(int l, int r, vector<vector<int>>& arr, string s){
        if (l >= r) return 0;
        if (arr[l][r] != -1) return arr[l][r];
        if (s[l] == s[r]) {
            arr[l][r] = getK(l+1, r-1, arr, s);
            return arr[l][r];
        }
        else {
            arr[l][r] = min(getK(l, r-1, arr, s), getK(l+1, r, arr, s)) + 1;
            return arr[l][r];
        }
    }
    bool isValidPalindrome(string s, int k) {
        int size = s.size();
        vector<vector<int>> arr(size, vector<int>(size, -1));
        return getK(0, size - 1, arr, s) <= k;
    } 
};