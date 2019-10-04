//763. Partition Labels
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int end[26] = {0};
        int num = 0;
        vector<int> res;
        int size = S.size();
        for (int i = 0; i < size; i++) {
            int index = S[i] - 'a';
            end[index] = i;
        }
        int e;
        int s = 0;
        for (int i = 0; i < size; i++) {
            int index = S[i] - 'a';
            if (i == 0) e = end[index];
            if (i == e) {
                res.push_back(e - s + 1);
                if (i == size - 1) break;
                s = i + 1;
                e = end[S[i+1]-'a'];
            }
            else {
                e = e > end[index] ? e : end[index];
            }  
        }
        return res;
    }
};