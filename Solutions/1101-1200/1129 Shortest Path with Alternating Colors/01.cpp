//1129 Shortest Path with Alternating Colors
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> red;
        vector<vector<int>> blue;
        vector<int> res(n, -1);
        vector<vector<int>> visitr(n, vector<int>(n,0));
        vector<vector<int>> visitb(n, vector<int>(n,0));
        red.resize(n);
        blue.resize(n);
        for (int i = 0; i < red_edges.size(); i++) {
        	red[red_edges[i][0]].push_back(red_edges[i][1]);
        }
        for (int i = 0; i < blue_edges.size(); i++) {
        	blue[blue_edges[i][0]].push_back(blue_edges[i][1]);
        }
        queue<int> q;
        q.push(0);
        int lab = 1;
        int cnt = 1;
        while (!q.empty()) {
        	int cnt0 = 0;
        	while (cnt > 0) {
        		int tmp = q.front();
	        	q.pop();
	        	if (lab % 2 == 1) {
	        		for (int i = 0; i < red[tmp].size(); i++) {
	        			int next = red[tmp][i];
	        			if (visitr[tmp][next] == 0) {
	        				q.push(next);
		        			if (res[next] == -1) {
		        				res[next] = lab;
		        			}
		        			else {
		        				res[next] = min(lab, res[next]);
		        			}
		        			cnt0++;
		        			visitr[tmp][next] = 1;
	        			}
	        		}
	        	}
	        	else {
	        		for (int i = 0; i < blue[tmp].size(); i++) {
	        			int next = blue[tmp][i];
	        			if (visitb[tmp][next] == 0) {
	        				q.push(next);
		        			if (res[next] == -1) {
		        				res[next] = lab;
		        			}
		        			else {
		        				res[next] = min(lab, res[next]);
		        			}
		        			cnt0++;
		        			visitb[tmp][next] = 1;
	        			}
	        		}
	        	}
	        	cnt--;
        	}
        	cnt = cnt0;
        	lab++;
        }
        visitr.assign(n, vector<int>(n,0));
        visitb.assign(n, vector<int>(n,0));
        q.push(0);
        lab = 1;
        cnt = 1;
        while (!q.empty()) {
        	int cnt0 = 0;
        	while (cnt > 0) {
        		int tmp = q.front();
	        	q.pop();
	        	if (lab % 2 == 0) {
	        		for (int i = 0; i < red[tmp].size(); i++) {
	        			int next = red[tmp][i];
	        			if (visitr[tmp][next] == 0) {
	        				q.push(next);
		        			if (res[next] == -1) {
		        				res[next] = lab;
		        			}
		        			else {
		        				res[next] = min(lab, res[next]);
		        			}
		        			cnt0++;
		        			visitr[tmp][next] = 1;
	        			}
	        		}
	        	}
	        	else {
	        		for (int i = 0; i < blue[tmp].size(); i++) {
	        			int next = blue[tmp][i];
	        			if (visitb[tmp][next] == 0) {
	        				q.push(next);
		        			if (res[next] == -1) {
		        				res[next] = lab;
		        			}
		        			else {
		        				res[next] = min(lab, res[next]);
		        			}
		        			cnt0++;
		        			visitb[tmp][next] = 1;
	        			}
	        		}
	        	}
	        	cnt--;
        	}
        	cnt = cnt0;
        	lab++;
        }
        res[0] = 0;
        return res;
    }
};