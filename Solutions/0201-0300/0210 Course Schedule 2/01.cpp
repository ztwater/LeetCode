//0210 Course Schedule 2
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list;
        vector<int> next(numCourses, 0);
        vector<int> res;
        vector<int> null;
        list.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
        	list[prerequisites[i][1]].push_back(prerequisites[i][0]);
        	next[prerequisites[i][0]]++;
        }
        while (res.size() < numCourses) {
        	int i = 0;
        	for (; i < numCourses; i++) {
        		if (next[i] == 0) {
	        		res.push_back(i);
                    next[i]--;
	        		break;
	        	}
        	}
            if (i == numCourses) return null;
        	for (int j = 0; j < list[i].size(); j++) {
        		next[list[i][j]]--;
        	}
        }
        return res;
    }
};