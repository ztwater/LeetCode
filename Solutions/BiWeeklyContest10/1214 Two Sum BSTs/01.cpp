//1214 Two Sum BSTs
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
    vector<int> l;
    vector<int> r;
    void dfs2(TreeNode* t) {
        vector<int> v;
        if (t == NULL) return;
        TreeNode* cur = t;
        dfs2(cur->right);
        r.push_back(cur->val);
        dfs2(cur->left);
        return;
    }
    void dfs1(TreeNode* t) {
        vector<int> v;
        if (t == NULL) return;
        TreeNode* cur = t;
        dfs1(cur->left);
        l.push_back(cur->val);
        dfs1(cur->right);
        return;
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        dfs1(root1);
        dfs2(root2);
        int size1 = l.size();
        int size2 = r.size();
        int s1 = 0;
        int s2 = 0;
        while (s1 < size1 && s2 < size2) {
            int sum = l[s1] + r[s2];
            if (sum < target) s1++;
            else if (sum > target) s2++;
            else return true;
        }
        return false;
    }
};