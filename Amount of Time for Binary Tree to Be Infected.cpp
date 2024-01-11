/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> edges;
        traverse(root, edges);

        vector<int> vis(100001, 0);
        int cnt = 0;
        bfs(edges, vis, start, cnt);

        return cnt;
    }

private:
    void traverse(TreeNode* root, unordered_map<int, vector<int>>& edges) {
        if (root == NULL)
            return;

        if (root->left) {
            edges[root->val].push_back(root->left->val);
            edges[root->left->val].push_back(root->val);
            traverse(root->left, edges);
        }

        if (root->right) {
            edges[root->val].push_back(root->right->val);
            edges[root->right->val].push_back(root->val);
            traverse(root->right, edges);
        }
    }

    void bfs(unordered_map<int, vector<int>>& edges, vector<int>& vis, int start, int& cnt) {
        queue<pair<int, int>> q;
        q.push({ start, 0 });
        vis[start] = 1;

        while (!q.empty()) {
            auto [node, time] = q.front();
            q.pop();

            cnt = max(cnt, time);

            for (int neighbor : edges[node]) {
                if (vis[neighbor] == 0) {
                    vis[neighbor] = 1;
                    q.push({ neighbor, time + 1 });
                }
            }
        }
    }
};