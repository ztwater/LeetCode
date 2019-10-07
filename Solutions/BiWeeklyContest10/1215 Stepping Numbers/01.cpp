//1215 Stepping Numbers
class Solution {
public:
    /*
    bool step(int a) {
        if (a <= 10) return true;
        int last;
        int lab = 0;
        while (a > 0) {
            if (lab == 0) {
                lab = 1;
                last = a % 10;
                a /= 10;
            }
            else {
                int tmp = a % 10;
                if (tmp - last != 1 && last - tmp != 1) return false;
                last = tmp;
                a /= 10;
            }
        }
        return true;
    }*/
    vector<int> v;
    void add(int s, int tmp, int d, int l, int h) {
        int a = -1,b = -1;
        if (tmp == 0) {
            b = 1;
        } 
        else if (tmp == 9) {
            a = 8;
        }
        else {
            a = tmp - 1;
            b = tmp + 1;
        }
        int ten = 1;
        for (int i = 0; i < d; i++) {
            ten *= 10;
        }
        if (ten >= 1000000000 && (a > 2 || ((a == 2) || s >= 247483647) )) return;
        if (a != -1) {
            int s1 = s + ten*a;
            if (s1 > h) return;
            else {
                if (s1 >= l && a != 0) v.push_back(s1);
                if (d >= 9) return;
                add(s1, a, d+1, l, h);
            }
            
        }
        if (ten >= 1000000000 && (b > 2 || ((b == 2) || s >= 247483647) )) return;
        if (b != -1) {
            int s1 = s + ten*b;
            if (s1 > h) return;
            else {
                if (s1 >= l) v.push_back(s1);
                if (d >= 9) return;
                add(s1, b, d+1, l, h);
                
            }
        }
    }
    
    vector<int> countSteppingNumbers(int low, int high) {
        for (int i = 0; i <= 9; i++) {
            if (i >= low && i <= high) v.push_back(i);
            add(i, i, 1, low, high);
        }
        sort(v.begin(),v.end());
        return v;
    }
};