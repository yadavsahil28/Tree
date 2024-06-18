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
        if(root == NULL){
            return ans;
        }

        map<int,map<int,vector<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();

            int row = temp.second.first;
            int col = temp.second.second;
            TreeNode* frontNode = temp.first;
            int data = frontNode->val;

            nodes[col][row].push_back(data);

            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(row+1,col-1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(row+1,col+1)));
            }
        }

        for(pair<int,map<int,vector<int>>> i: nodes){
            vector<int> output;
            for(pair<int,vector<int>> j: i.second){
                sort(j.second.begin(), j.second.end());
                for(int k: j.second){
                    output.push_back(k);
                }
            }
            ans.push_back(output);
        }

        return ans;
    }
};
