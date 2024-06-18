class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int,int> bottomNode;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int val = frontNode->data;
            int col = temp.second;
            
            bottomNode[col] = val;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,col-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,col+1));
            }
        }
        
        for(pair<int,int> i:bottomNode){
            ans.push_back(i.second);    
        }
        return ans;
    }
};
