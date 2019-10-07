//0838 Push Dominoes
class Solution {
public:
    string pushDominoes(string dominoes) {
        int size = dominoes.size();
        if (size <= 1) return dominoes;
        string dom(size, '.');
        int res = 0;
        int state = 0;
        for (int i = 0; i < size; i++) {
            dom[i] = dominoes[i];
        	if (dominoes[i] == 'L') {
        		if (state == 0) {
        			for (int j = res; j <= i; j++) {
        				dom[j] = 'L';
        			}
        			res = i + 1;
        		}
        		else if (state == 1) {
        			for (int j = 0; j <= (i - res - 1) / 2; j++) {
                        
        				dom[res + j] = 'R';
        				dom[i - j] = 'L';
        			}
        			res = i + 1;
        			state = 0;
        		}
        	}
        	else if (dominoes[i] == 'R') {
        		if (state == 0) {
        			state = 1;
        			res = i;
        		}
        		else if (state == 1) {
        			for (int j = res; j <= i; j++) {
        				dom[j] = 'R';
        			}
        			res = i;
        		}
        	}
        }
        if (state == 1) {
        	for (int j = res; j < size; j++) {
				dom[j] = 'R';
			}
			res = size;
        }
        return dom;
    }
};