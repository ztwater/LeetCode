//0802 Find Eventual Safe States
class Solution {
public:
	int dfs(int cur, vector<int>& state, vector<vector<int>>& graph) {
		//terminal node
		if (graph[cur].size() == 0) return state[cur] = -1;
		state[cur] = 1;
        for (int i = 0; i < graph[cur].size(); i++) {
        	int tmp = graph[cur][i];
        	int nstate;
        	if (state[tmp] == 0) {
        		nstate = dfs(tmp, state, graph);
        	}
        	else if (state[tmp] == -1) {
        		nstate = -1;
        	}
        	else {
        		nstate = 2;
        	}

        	if (nstate == 2) {
        		return state[cur] = 2;
        	}
        }
        return state[cur] = -1;
	}

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> state(size, 0);
        vector<int> res;
        for (int i = 0; i < size; i++) {
        	if (state[i] == 0) state[i] = dfs(i, state, graph);
        	else continue;
        }
        for (int i = 0; i < size; i++) {
        	if (state[i] == -1) res.push_back(i);
        }
        return res;
    }
};