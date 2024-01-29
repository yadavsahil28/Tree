// Approach 1

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
    
    void solve(TreeNode* root, int k, int& count, long long int sum, unordered_map<long long int,int>& mp){
        if(root == NULL){
            return;
        }
        
        sum += root->val;
        if(sum == k){
            count++;
        }
        count += mp[sum-k];
        
        mp[sum]++;
        solve(root->left,k,count,sum,mp);
        solve(root->right,k,count,sum,mp);
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        
        int count = 0;
        unordered_map<long long int,int> mp;
        solve(root,targetSum,count,0,mp);
        return count;
    }
};


// Approach 2 

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
    int count = 0;

    void solve(TreeNode* root, int target, long long int sum ){
        if(root == NULL)
            return;

        if(target == sum)
            count++;
        
        if(root->left != NULL)
            solve(root->left,target,sum + root->left->val);

        if(root->right != NULL)
            solve(root->right,target,sum + root->right->val);

    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        
        solve(root,targetSum,root->val);

        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);

        return count;
    }
};
