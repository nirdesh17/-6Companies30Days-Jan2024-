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

int ans;
class ds{
    public:
        bool bst;
        int mx,mi,ms;
        ds(){
            bst=true;
            mx=INT_MIN;
            mi=INT_MAX;
            ms=0;
        }
};
class Solution {
public:
    ds solve(TreeNode* root)
    {
        if(root==NULL)
            return ds();

        ds p;
        ds pl=solve(root->left);
        ds pr=solve(root->right);

        if(pl.bst==true && pr.bst==true && root->val>pl.mx && root->val<pr.mi)
        {
            p.bst=true;
            p.ms=pl.ms+pr.ms+root->val;
            p.mi=min(root->val,pl.mi);
            p.mx=max(root->val,pr.mx);
        }
        else
        {
            p.bst=false;
            p.ms=max(pl.ms,pr.ms);
        }

        ans=max(ans,p.ms);
        return p;
    }
    int maxSumBST(TreeNode* root) {
        ans=0;
        solve(root);
        return ans;
    }
};