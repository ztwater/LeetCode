//0881 Boats to Save People
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int size = people.size();
        if (size == 0) return 0;
        int l = 0;
        int h = size - 1;
        int num = 0;
        while (l < h) {
        	if (people[l] + people[h] > limit) {
        		num++;
        		h--;
        	}
        	else {
        		num++;
        		l++;
        		h--;
        	}
        }
        return num;
    }
};