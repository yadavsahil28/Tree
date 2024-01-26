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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root,0});

        int width = 0;

        while(!q.empty()){
            unsigned long long int leftMostIndex = q.front().second;
            unsigned long long int rightMostIndex = q.back().second;

            int size = q.size();

            for(int i=0; i<size; i++){
                pair<TreeNode*, unsigned long long int> temp = q.front();
                q.pop();
                TreeNode* node = temp.first;
                unsigned long long int index = temp.second;

                if(node->left){
                    q.push({node->left, 2*index+1});
                }
                if(node->right){
                    q.push({node->right, 2*index+2});
                }
            }
            width = max(width, (int)(rightMostIndex - leftMostIndex + 1));
        }
        return width;
    }
};
