//1218 Longest Arithmetic Subsequence of Given Difference
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int size = arr.size();
        unordered_map<int, int> m;
        int p1 = 0;
        int p2 = 0;
        for (int i = 0; i < size; i++) {
            int a = arr[i] - difference;
            if (m.find(a) == m.end()){
                if(m.find(arr[i]) == m.end()) m[arr[i]] = 1;
            }
            else {
                int tmp = m[a];
                m.erase(a);
                m[arr[i]] = tmp + 1;
            }
            //cout << m[arr[i]] << endl;
        }
        int ma = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            //cout << it->first << " " << it->second <<endl;
            ma = max(ma, it->second);
        }
        return ma;
    }
};