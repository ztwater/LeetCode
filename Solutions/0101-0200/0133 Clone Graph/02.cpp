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
        unordered_map<Node*, Node*> m;
        vector<Node*> null;
        Node* cur = new Node(node->val, null);
        m[node] = cur;
        q.push(node);
        while (!q.empty()) {
            Node* pre = q.front();
            cur = m[pre];
            vector<Node*> nb;
            for (int i = 0; i < pre->neighbors.size(); i++) {
                if (m.find(pre->neighbors[i]) == m.end()) {
                    q.push(pre->neighbors[i]);
                    Node * n = new Node(pre->neighbors[i]->val, null);
                    m[pre->neighbors[i]] = n;
                    nb.push_back(n);
                }
                else nb.push_back(m[pre->neighbors[i]]);
            }
            cur->neighbors = nb;
            q.pop();
        }
        return m[node];
    }
};