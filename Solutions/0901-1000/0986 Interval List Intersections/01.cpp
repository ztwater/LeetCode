//986. Interval List Intersections
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    	vector<vector<int>> res;
        int sizeA = A.size();
        int sizeB = B.size();
        int i = 0;
        int j = 0;
        int s1, e1, s2, e2;
        while (i < sizeA && j < sizeB) {
        	s1 = A[i][0];
        	e1 = A[i][1];
        	s2 = B[j][0];
        	e2 = B[j][1];
        	if (e1 < s2) i++;
        	else if (e2 < s1) j++;
        	else if (e1 < e2) {
        		vector<int> tmp(2);
        		tmp[1] = e1;
        		if (s1 < s2) tmp[0] = s2;
        		else tmp[0] = s1;
        		res.push_back(tmp);
        		i++;
        	}
        	else {
        		vector<int> tmp(2);
        		tmp[1] = e2;
        		if (s1 < s2) tmp[0] = s2;
        		else tmp[0] = s1;
        		res.push_back(tmp);
        		j++;
        	}
        }
        return res;
    }
};