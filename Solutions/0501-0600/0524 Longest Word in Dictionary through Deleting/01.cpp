//0524 Longest Word in Dictionary through Deleting
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int size_s = s.size();
        int size_d = d.size();
        string res = "";
        int dmin = 1005;
        if (size_s == 0 || size_d == 0) return res;
        for (int i = 0; i < size_d; i++) {
        	int size_w = d[i].size();
        	if (size_w == 0) continue;
        	int tmp = comp(s, d[i]);
        	if (tmp < dmin) {
        		dmin = tmp;
        		res = d[i];
        	}
        	else if (tmp == dmin){
        		if (res.compare(d[i]) > 0) res = d[i];
        	}
        }
        return res;
    }
    int comp(string s, string w) {
    	int size_s = s.size();
    	int size_w = w.size();
    	int d = 0;
    	int s1 = 0, s2 = 0;
    	while (s1 < size_s && s2 < size_w) {
    		if (s[s1] == w[s2]) {
    			s1++;
    			s2++;
    		}
    		else {
    			s1++;
    			d++;
    		}
    	}
    	if (s2 == size_w) return d + size_s - s1;
    	else return 1005;
    }
};