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
    int maxD = 0; //stores maximum depth of given binary tree
    unordered_map<TreeNode*, int> mpp; //unordered map to store node and its corresponding depth

    void depth(TreeNode* root, int d) //function to find the depth of each node of binary tree 
    {
        if(root == NULL) //if root of binary tree is NULL then we simply return means that no other node 
        {               //is present below the current node 
            return;
        }

        maxD = max(maxD, d); //compute the max depth of binary tree 
        mpp[root] = d; //store depth of current node in map 

        depth(root->left, d+1); //recursively call for left subtree of current node
        depth(root->right, d+1); //recursively call for right subtree of current node
    }
    TreeNode* LCA(TreeNode* root) //function to find LCA of max depth node of binary tree
    {
        if(root == NULL) //if current root of binary tree is NULL
        {
            return NULL; //then we return null  
        }
        if(mpp[root] == maxD) //if current node depth is equal to max depth of binary tree then that node
        {
            return root; //is the deepest node and its Least common ancesstor will be our answer  
        }

        TreeNode* l = LCA(root->left); //now going on left subtree of current node recursively 
        TreeNode* r = LCA(root->right); //going to right subtree of current node recursively

        if(l != NULL && r != NULL) //if l and r are not equal to null then that means that the current node is 
        {                         //least common ancesstor so we return root of that node to previous recursive call
            return root;
        }

        return l != NULL ? l : r; //if l is not null and r is null we return l and also vice versa is true
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        depth(root, 0); //calling depth function to find the depth of each node and also calculate max depth of binary tree

        return LCA(root); //finding the least common ancesstor of max depth node of binary tree
    }
};