//0207 Course Schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int size = prerequisites.size();
        if (size == 0) return true;
        vector<vector<int>> graph;
        graph.resize(numCourses);
        vector<int> visit(numCourses, 0);
        for (int i = 0; i < size; i++) {
            int p = prerequisites[i][1];
            int c = prerequisites[i][0];
            graph[p].push_back(c);
            visit[c]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (visit[i] == 0) q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            --visit[i];
            cnt++;
            for (int j = 0; j < graph[i].size(); j++) {
                if (--visit[graph[i][j]] == 0) q.push(graph[i][j]);
            }
        }
        return (cnt == numCourses);
    }   
};