//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    // pair(included,excluded)
    pair<int,int> solve(Node* root){
        if(root == NULL){
            return make_pair(0,0);
        }
        
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns = solve(root->right);
        
        int included = root->data + leftAns.second + rightAns.second;
        int excluded = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
        
        return make_pair(included,excluded);
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};
