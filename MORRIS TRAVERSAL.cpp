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
    // MORRIS TRAVERSAL
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }

                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }

                if(pred->right == curr){
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};


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
    // MORRIS TRAVERSAL
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }

                if(pred->right == NULL){
                    pred->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }

                if(pred->right == curr){
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};



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
    // MORRIS TRAVERSAL
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        TreeNode* curr = root;
        
        while(curr != NULL){
            if(curr->right == NULL){
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else{

                // Finding Predecesser
                TreeNode* pred = curr->right;
                while(pred->left != NULL && pred->left != curr){
                    pred = pred->left;
                }

                if(pred->left == NULL){
                    ans.push_back(curr->val);
                    pred->left = curr;
                    curr = curr->right;
                }
                else if(pred->left == curr){
                    pred->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
