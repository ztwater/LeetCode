//0424 Longest Repeating Character Replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<queue<int>> qList(26, queue<int>);
        int len[26] = {0};
        int size = s.size();
        int ma = 0;
        for (int i = 0; i < size; i++) {
        	for (int j = 0; j < 26; j++) {
        		if (s[i] == ('A' + j)) {
        			len[j]++;
        		}
        		else {
        			if (qList[j].size() < k) {
        				qList[j].push(i);
        				len[j]++;
        			}
        			else {
        				int f = qList[j].front();
        				qList[j].pop();
        				qList[j].push(i);
        				len[j] = i - f;
        			}
        		}
        		ma = max(ma, len[j]);
        	}
        }
        return ma;
    }
};