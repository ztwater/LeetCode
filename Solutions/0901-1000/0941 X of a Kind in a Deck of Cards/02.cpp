//0941 X of a Kind in a Deck of Cards
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> m;
        for (int x : deck) {
            m[x]++;
        }
        int tmp = m.begin()->second;
        for (auto a : m) {
            tmp = gcd(tmp, a.second);
        }
        return (tmp >= 2);
    }
};