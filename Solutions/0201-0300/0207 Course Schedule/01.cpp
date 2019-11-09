//0207 Course Schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        for (int i = 0; i < prerequisites.size(); i++) {
        	graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }
        for (int k = 0; k < numCourses; k++) {
        	for (int i = 0; i < numCourses; i++) {
        		for (int j = 0; j < numCourses; j++) {
                    if (i == j) continue;
        			graph[i][j] |= graph[i][k] * graph[k][j];
        			if (graph[i][j] & graph[j][i] == 1) return false;
        		}
        	}
        }
        return true;
    }	
};

