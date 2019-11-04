//0765 Couples Holding Hands
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
    	int size = row.size();
    	vector<int> pos(size, -1);
		for (int i = 0; i < size; i++) {
			if (row[i] % 2 == 0) {
				if (pos[row[i]+1] == -1) pos[row[i]] = i;
				else {
					pos[row[i]] = pos[row[i]+1];
					pos[row[i]+1] = i;
				}
			}
			else {
				if (pos[row[i]-1] == -1) pos[row[i]] = i;
				else {
					pos[row[i]] = pos[row[i]-1];
					pos[row[i]-1] = i;
				}
			}
		} 
		int count = 0;
		for (int i = 0; i < size; i += 2) {
			if (pos[row[i]] == i+1) continue;
			else {
				pos[row[pos[row[i+1]]]] = pos[row[i]];
				row[pos[row[i]]] = row[i+1];
				count++;
			}
		}   
		return count;
    }
};