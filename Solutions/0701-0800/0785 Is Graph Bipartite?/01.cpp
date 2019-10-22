//0785 Is Graph Bipartite?
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    	int size = graph.size();
        vector<int> state(size, 0);
        queue<int> q;
        for (int i = 0; i < size; i++) {
            if (graph[i].size() > 0 && state[i] == 0) {
                q.push(i);
                int flip = 1;
		        while (!q.empty()) {
		        	int num = q.size();
		        	while (num > 0) {
		        		int tmp = q.front();
		        		if (state[tmp] == 0) {
		        			state[tmp] = flip;
		        			for (int i = 0; i < graph[tmp].size(); i++) {
		        				q.push(graph[tmp][i]);
		        			}
		        		}
		        		else if (state[tmp] == -flip) return false;
		        		q.pop();
		                num--;
		        	}
		        	flip = -flip;
		        }
            }   
        }
        return true;
    }
};