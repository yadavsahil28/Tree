class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int,int> topNode;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int val = frontNode->data;
            int col = temp.second;
            
            if(!topNode.count(col)){
                topNode[col] = val;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,col-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,col+1));
            }
        }
        
        for(pair<int,int> i:topNode){
            ans.push_back(i.second);
        }
        return ans;
    }

};
