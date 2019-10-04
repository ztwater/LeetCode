//349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        unordered_set<int> s2;
        vector<int> res;
        s.insert(nums1.begin(), nums1.end());
        int size = nums2.size();
        if (size == 0) return res;
        for (int i = 0; i < size; i++) {
        	if (s.find(nums2[i]) != s.end()) {
        		int j = nums2[i];
        		s2.insert(j);
        	}
        }
        unordered_set<int> :: iterator it;
        for (it = s2.begin(); it != s2.end(); it++) {
            res.push_back(*it);
        } 
        return res;
    }
};