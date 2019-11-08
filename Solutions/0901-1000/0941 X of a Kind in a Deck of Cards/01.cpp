//0941 X of a Kind in a Deck of Cards
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> cnt(10005,0);
        int tmp = 0;
        for (int i = 0; i < deck.size(); i++) {
        	cnt[deck[i]]++;
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0) continue;
            if (tmp == 0) tmp = cnt[i];
            else tmp = gcd(tmp, cnt[i]);
            if (tmp == 1) return false;
        }
        return true;
    }
    
    int gcd(int a, int b) {
        if (a < b) {
            int tmp = b;
            b = a;
            a = tmp;
        }
        while (a % b != 0) {
            a = a % b;
            int tmp = b;
            b = a;
            a = tmp;
        }
        return b;
    }
};