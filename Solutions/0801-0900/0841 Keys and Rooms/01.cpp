//0841 Keys and Rooms
class Solution {
public:
	void dfs(int idx, int& n, vector<int>& visit, vector<vector<int>>& rooms) {
		visit[idx] = 1;
		n--;
		if (n == 0) return;
		for (int i = 0; i < rooms[idx].size(); i++) {
			int key = rooms[idx][i];
			if (visit[key] == 0) dfs(key, n, visit, rooms); 
		}
		return;
	}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visit(n, 0);
        dfs(0, n, visit, rooms);
        if (n == 0) return true;
        else return false;
    }
};