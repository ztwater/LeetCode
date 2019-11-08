//1162 As Far from Land as Possible
//BFS for each water grid
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
    	int dist = -1;
    	vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
        	for (int j = 0; j < grid[0].size(); j++) {
        		if (grid[i][j] == 1) continue;
        		queue<pair<int, int>> q;
        		q.push(make_pair(i,j));
        		int layer = 1;
        		int lab = 0;
                visit.assign(grid.size(), vector<int>(grid[0].size(), 0));
        		while (!q.empty()) {
        			int cnt = q.size();
        			while (cnt > 0) {
	        			pair<int, int> p = q.front();
	        			q.pop();
                        visit[p.first][p.second] = 1;
	        			cnt--;
	        			if (p.first > 0  && visit[p.first-1][p.second] == 0) {
	        				if (grid[p.first-1][p.second] == 1) {
	        					dist = max(dist, layer);
	        					lab = 1;
	        					break;
	        				}
	        				q.push(make_pair(p.first-1,p.second));
	        			}
	        			if (p.first < grid.size()-1 && visit[p.first+1][p.second] == 0) {
	        				if (grid[p.first+1][p.second] == 1 ) {
	        					dist = max(dist, layer);
	        					lab = 1;
	        					break;
	        				}
	        				q.push(make_pair(p.first+1,p.second));
	        			}
	        			if (p.second > 0 && visit[p.first][p.second-1] == 0) {
	        				if (grid[p.first][p.second-1] == 1 ) {
	        					dist = max(dist, layer);
	        					lab = 1;
	        					break;
	        				}
	        				q.push(make_pair(p.first,p.second-1));
	        			}
	        			if (p.second < grid[0].size()-1 && visit[p.first][p.second+1] == 0) {
	        				if (grid[p.first][p.second+1] == 1 ) {
	        					dist = max(dist, layer);
	        					lab = 1;
	        					break;
	        				}
	        				q.push(make_pair(p.first,p.second+1));
	        			}
	        		}
                    layer++;
	        		if (lab == 1) break;
        		}
        	}
        }
        return dist;
    }
};
/*
int maxDistance(vector<vector<int>>& g, int steps = 0) {
  queue<pair<int, int>> q, q1;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[i].size(); ++j)
      if (g[i][j] == 1)
        q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
  while (!q.empty()) {
    ++steps;
    while (!q.empty()) {
      int i = q.front().first, j = q.front().second;
      q.pop();
      if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
        g[i][j] = steps;
        q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
      }
    }
    swap(q1, q);
  }
  return steps == 1 ? -1 : steps - 1;
}
*/