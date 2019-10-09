//0904 Fruit Into Baskets
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int size = tree.size();
        if (size == 0) return 0;
        int start = 0;
        int end = 0;
        int first = -1;
        int second = -1;
        vector<int> v(size,0);
        int ma = 0;
        while (end < size) {
        	if (tree[end] == first) {
        		v[first]++;
        		end++;
        		ma = max(ma, end - start + 1);
        		continue;
        	}
        	if (tree[end] == second) {
        		v[second]++;
        		end++;
        		ma = max(ma, end - start + 1);
        		continue;
        	}
        	if (tree[end] != second && first == -1) {
        		first = tree[end];
        		v[first]++;
        		end++;
        		ma = max(ma, end - start + 1);
        		continue;
        	}
        	if (tree[end] != first && second == -1) {
        		second = tree[end];
        		v[second]++;
        		end++;
        		ma = max(ma, end - start + 1);
        		continue;
        	}
        	if (tree[end] != first && tree[end] != second) {
        		while (v[first] != 0 && v[second] != 0) {
        			v[tree[start]]--;
        			start++;
        		}
        		if (v[first] == 0) {
        			first = tree[end];
        			v[first]++;
        			end++;
        			ma = max(ma, end - start + 1);
        		}
        		else if (v[second] == 0){
        			second = tree[end];
        			v[second]++;
        			end++;
        			ma = max(ma, end - start + 1);
        		}
        	}
        }
        return ma;
    }
};