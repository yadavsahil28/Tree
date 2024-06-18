// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    // pair(sum,isSumTree)
    pair<int,bool> solve(Node* root){
        if(root == NULL){
            return make_pair(0,true);
        }
        
        if(root->left == NULL && root->right == NULL){
            return make_pair(root->data,true);
        }
        
        pair<int,bool> leftAns = solve(root->left);
        pair<int,bool> rightAns = solve(root->right);
        
        int leftSum = leftAns.first;
        int rightSum = rightAns.first;
        bool isLeftSumTree = leftAns.second;
        bool isRightSumTree = rightAns.second;
        
        int currSum = leftSum + rightSum;
        
        if(isLeftSumTree && isRightSumTree && currSum == root->data){
            return make_pair(currSum + root->data,true);
        }
        else{
            return make_pair(currSum + root->data,false);
        }
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return solve(root).second;
    }
};
