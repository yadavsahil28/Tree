// Approach 1 - O(N) square or O(N*H)
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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right);

        return max(op3, max(op1,op2));
    }
};


// Approach 2 - O(N)

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
    // pair(diameter,height)
    pair<int,int> diameterFast(TreeNode* root){
        if(root == NULL){
            return make_pair(0,0);
        }

        pair<int,int> leftAns = diameterFast(root->left);
        pair<int,int> rightAns = diameterFast(root->right);

        int leftDiameter = leftAns.first;
        int rightDiameter = rightAns.first;
        int leftHeight = leftAns.second;
        int rightHeight = rightAns.second;
        int currDiameter = leftHeight + rightHeight;
        
        int maxDiameter = max(currDiameter, max(leftDiameter,rightDiameter));
        int maxHeight = max(leftHeight,rightHeight) + 1;

        return make_pair(maxDiameter,maxHeight);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return diameterFast(root).first;
    }
};
