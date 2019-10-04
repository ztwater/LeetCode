//763. Partition Labels
class Solution {
public:
    vector<int> partitionLabels(string S) {
    	unordered_map<char, int> map;
    	int start[505], end[505];
    	int num = 0;
    	vector<int> res;
        int size = S.size();
        for (int i = 0; i < size; i++) {
        	if (map.find(S[i]) == map.end()){
        		map[S[i]] = num;
        		start[num] = i;
        		end[num] = i;
        		num++;
        	}
        	else {
        		end[map[S[i]]] = i;
        	}
        }
        int s, e;
        int lab = 0;
        for (int i = 0; i < num; i++) {
        	if (lab == 0) {
        		lab = 1;
        		s = start[i];
        		e = end[i];
        	}
        	else {
        		if (start[i] < e) {
        			e = e > end[i] ? e : end[i];
        		}
        		else {
        			res.push_back(e - s + 1);
        			s = start[i];
        			e = end[i];
        		}
        	}
        }
        res.push_back(e - s + 1);
        return res;
    }
};