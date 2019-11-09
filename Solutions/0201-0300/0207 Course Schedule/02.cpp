//0207 Course Schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        vector<int> visit(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]][prerequisites[i][0]] = 1;
            visit[prerequisites[i][0]]++;
        }
        for (int k = 0; k < numCourses; k++) {
            int i = 0;
            for (; i < numCourses; i++) {
                if (visit[i] == 0)  break;
            }
            if (i == numCourses) return false;
            visit[i]--;
            for (int j = 0; j < numCourses; j++) {
                if (graph[i][j] == 1) visit[j]--;
            }
        }
        return true;
    }   
};