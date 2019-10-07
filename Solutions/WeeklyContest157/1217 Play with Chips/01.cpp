//1217 Play with Chips
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {   
        int s = chips.size();
        if (s <= 1) return 0;
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < s; i++) {
            if (chips[i] % 2 == 0) s1++;
            else s2++;
        }
        return min(s1,s2);
    }
};