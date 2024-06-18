/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void solve(Node* root, map<int,vector<int>>& nodes, int diagonalLevel){
    if(root == NULL){
        return;
    }
    
    nodes[diagonalLevel].push_back(root->data);
    
    solve(root->left,nodes,diagonalLevel+1);
    solve(root->right,nodes,diagonalLevel);
}

vector<int> diagonal(Node *root)
{
   // your code here
    vector<int> ans;
    map<int,vector<int>> nodes;
    
    solve(root,nodes,0);
   
    for(pair<int,vector<int>> i: nodes){
       for(int j: i.second){
           ans.push_back(j);
       }
    }
    return ans;
}
