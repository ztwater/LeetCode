//1042 Flower Planting With No Adjacent
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    	vector<vector<int>> adj(N);
    	vector<int> res(N, 1);
    	for (int i = 0; i < paths.size(); i++) {
    		int a = paths[i][0];
    		int b = paths[i][1];
    		adj[a-1].push_back(b-1);
    		adj[b-1].push_back(a-1);
        }
        for (int i = 0; i < N; i++) {
        	bool lab[5] = {false};
        	for (int j = 0; j < adj[i].size(); j++) {
        		lab[res[adj[i][j]]] = true;
        	}
        	for (int j = 1; j <= 4; j++) {
        		if (lab[j] == false) res[i] = j;
        	}
        }
        return res;
    }
};