//0133 Clone Graph
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        queue<Node*> q;
        unordered_map<Node*, int> nd2idx; //old graph
        unordered_map<int, Node*> idx2nd; //new graph
        vector<int> visit(105, 0);
        int idx = 0;
        vector<Node*> null;
        nd2idx[node] = idx++;
        q.push(node);
        while (!q.empty()) {
        	Node* pre = q.front();
        	int id = nd2idx[pre];
            visit[id] = 1;
            vector<Node*> nb;
            Node* cur;
        	if (idx2nd.find(id) == idx2nd.end()) {
        		cur = new Node(pre->val, null);
        		idx2nd[id] = cur;
        	}
        	else {
        		cur = idx2nd[id];
        	}
        	for (int i = 0; i < pre->neighbors.size(); i++) {
        		int nbid;
	        	if (nd2idx.find(pre->neighbors[i]) == nd2idx.end()) {
                    nbid = idx;
	        		nd2idx[pre->neighbors[i]] = idx++;
	        		Node * n = new Node(pre->neighbors[i]->val, null);
	        		idx2nd[nbid] = n;
	        		nb.push_back(n);
	        	}
	        	else {
                    nbid = nd2idx[pre->neighbors[i]];
	        		nb.push_back(idx2nd[nbid]);
	        	}
                if (visit[nbid] == 0) {
                    q.push(pre->neighbors[i]);
                }
	        }
	        cur->neighbors = nb;
	        q.pop();
        }
        return idx2nd[0];
    }
};
