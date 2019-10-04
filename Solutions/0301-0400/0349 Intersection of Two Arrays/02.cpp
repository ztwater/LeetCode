//349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> res;
        if (size1 == 0 || size2 == 0) return res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int last;
        int lab = 0;
        int i = 0;
        int j = 0;
        while (i < size1 && j < size2) {
            if (nums1[i] > nums2[j]) {
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                if (lab == 0) {
                    lab = 1;
                    last = nums1[i];
                    res.push_back(last);
                    i++;
                    j++;
                }
                else if (last == nums1[i]) {
                    i++;
                    j++;
                }
                else {
                    last = nums1[i];
                    res.push_back(last);
                    i++;
                    j++;
                }
            }
        }
        return res;
    }
};