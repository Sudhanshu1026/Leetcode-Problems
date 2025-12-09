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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        // cols[col][row] = multiset of node values (keeps values sorted for ties)
        map<int, map<int, multiset<int>>> cols;

        // BFS queue storing node, its column (hd) and row (depth)
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, col, row] = q.front(); q.pop();
            cols[col][row].insert(node->val);

            if (node->left)  q.push({node->left,  col - 1, row + 1});
            if (node->right) q.push({node->right, col + 1, row + 1});
        }

        // Build result: iterate columns left -> right, and within each column
        // rows top -> bottom, flattening the multisets (which are ascending).
        for (auto &colPair : cols) {
            vector<int> columnVals;
            for (auto &rowPair : colPair.second) {
                for (int v : rowPair.second) columnVals.push_back(v);
            }
            ans.push_back(move(columnVals));
        }

        return ans;
    }
};