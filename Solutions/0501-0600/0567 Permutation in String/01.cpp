//0567 Permutation in String
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        if (size2 < size1) return false;
        vector<int> v(26, 0);
        for (int i = 0; i < size1; i++) {
        	int index = s1[i] - 'a';
        	v[index]++;
        }
        int s = 0, e = 0;
        while (e < size2) {
        	int index = s2[e] - 'a';
        	if (v[index] != 0) {
        		v[index]--;
        		e++;
        	}
        	else {
        		while (s < e && v[index] == 0) {
        			v[s2[s]-'a']++;
	        		s++;
	        	}
	        	if (s == e) s = ++e;
	        	else {
	        		v[index]--;
	        		e++;
	        	}
        	}
        	if (e - s == size1) return true;
        }
        return false;
    }
};