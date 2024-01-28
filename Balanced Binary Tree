// Approach 1 - O(N*H) or O(N*N)

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

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        if(leftAns && rightAns && diff){
            return true;
        }
        else{
            return false;
        }
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
    // pair(height, isBalanced)
    pair<int,bool> isTreeBalanced(TreeNode* root){
        if(root == NULL){
            return make_pair(0,true);
        }

        pair<int,bool> leftAns = isTreeBalanced(root->left);
        pair<int,bool> rightAns = isTreeBalanced(root->right);

        int leftHeight = leftAns.first;
        int rightHeight = rightAns.first;
        bool leftBalanced = leftAns.second;
        bool rightBalanced = rightAns.second;

        bool currBalanced = abs(leftHeight - rightHeight) <= 1;
        int currHeight = max(leftHeight, rightHeight) + 1; 

        if(leftBalanced && rightBalanced && currBalanced){
            return make_pair(currHeight, true);
        }
        else{
            return make_pair(currHeight, false);
        }

    }
    bool isBalanced(TreeNode* root) {
        return isTreeBalanced(root).second;
    }
};
