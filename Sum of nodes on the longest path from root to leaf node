// Approach 1 

//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void solve(Node* root, int sum, int& maxSum, int len, int& maxLength){
        if(root == NULL){
            if(len > maxLength){
                maxLength = len;
                maxSum = sum;
            }
            else if(len == maxLength){
                maxSum = max(maxSum,sum);
            }
            return;
        }
        
        sum += root->data;    
            
        solve(root->left, sum, maxSum, len+1, maxLength);
        
        solve(root->right, sum, maxSum, len+1, maxLength);
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root == NULL)
            return 0;
            
        int sum = 0;
        int maxSum = INT_MIN;
        
        int len = 0;
        int maxLength = 0;
        
        
        solve(root, sum, maxSum, len, maxLength);
        return maxSum;
    }
};


// Approach 2

//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    // pair(height,sum)
    pair<int,int> sumOfLongestPath(Node* root){
        if(root == NULL){
            return make_pair(0,0);
        }
        
        pair<int,int> leftAns = sumOfLongestPath(root->left);
        pair<int,int> rightAns = sumOfLongestPath(root->right);
        
        int leftHeight = leftAns.first;
        int rightHeight = rightAns.first;
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        int currHeight = 1 + max(leftHeight,rightHeight);
        int currSum;
        if(leftHeight > rightHeight){
            currSum = root->data + leftSum;
        }
        else if(rightHeight > leftHeight){
            currSum = root->data + rightSum;
        }
        else if(leftHeight == rightHeight){
            currSum = root->data + max(leftSum,rightSum);
        }
        return make_pair(currHeight, currSum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(root == NULL){
            return 0;
        }
        return sumOfLongestPath(root).second;
    }
};
