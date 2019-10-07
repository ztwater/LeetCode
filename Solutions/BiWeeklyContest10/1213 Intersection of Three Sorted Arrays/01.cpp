//1213 Intersection of Three Sorted Arrays
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int size1 = arr1.size();
        int size2 = arr2.size();
        int size3 = arr3.size();
        vector<int> res;
        int s1 = 0, s2 = 0, s3 = 0;
        while (s1 < size1 && s2 < size2 && s3 < size3) {
            int a = arr1[s1];
            int b = arr2[s2];
            int c = arr3[s3];
            if (a == b && b == c) {
                res.push_back(a);
                s1++;
                s2++;
                s3++;
            }
            if (a < b || a < c) s1++;
            if (c < a || c < b) s3++;
            if (b < a || b < c) s2++;
        }  
        return res;
    }
};