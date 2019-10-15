//1161 Maximum Level Sum of a Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        int max = 0;
        int level = 1;
        int l = 0;
        while (!q1.empty() || !q2.empty()) {
        	int s;
        	while (!q1.empty()) {
        		TreeNode* tmp = q1.front();
        		if (tmp != NULL) {
        			s += tmp->val;
	        		q2.push(tmp->left);
	        		q2.push(tmp->right);
        		}
        		q1.pop();
        	}
        	l++;
        	if (s > max) {
        		max = s;
        		level = l;
        	}
        	ma = max(ma, s);
        	s = 0;
        	while (!q2.empty()) {
        		TreeNode* tmp = q2.front();
        		if (tmp != NULL) {
        			s += tmp->val;
	        		q1.push(tmp->left);
	        		q1.push(tmp->right);
        		}
        		q2.pop();
        	}
        	l++;
        	if (s > max) {
        		max = s;
        		level = l;
        	}
        }
        return level;
    }
};