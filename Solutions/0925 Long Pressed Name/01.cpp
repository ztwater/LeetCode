//925. Long Pressed Name
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
    	int size1 = name.size();
    	int size2 = typed.size();
    	if (size1 == 0 && size2 == 0) return true;
    	else if (size1 == 0 || size2 == 0) return false;
    	else {
    		int p1 = 0;
    		int p2 = 0;
    		while (p1 < size1 && p2 < size2) {
    			if (typed[p2] == name[p1]){
    				p1++;
    				p2++;
    				if (name[p1] != name[p1-1]) {
	    				while (typed[p2] == typed[p2-1]) {
	    					p2++;
	    					if (p2 >= size2) break;
	    				}
	    			}
    			}
    			else return false;
    		}
    		if (p1 >= size1 && p2 >= size2) return true;
    		else return false;
    	}
    }
};