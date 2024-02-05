class Solution {
  public:
    // Create Mapping
    // find target Node
    Node* childToParentMapping(Node* root, int target, unordered_map<Node*,Node*>& nodeToParent){
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        Node* targetNode = NULL;
        
        while(!q.empty()){
            Node* frontNode = q.front();
            q.pop();
            
            if(target == frontNode->data){
                targetNode = frontNode;
            }
            
            if(frontNode->left){
                q.push(frontNode->left);
                nodeToParent[frontNode->left] = frontNode;
            }
            
            if(frontNode->right){
                q.push(frontNode->right);
                nodeToParent[frontNode->right] = frontNode;
            }
        }
        return targetNode;
    }
    
    void burnTree(Node* targetNode, unordered_map<Node*,Node*>& nodeToParent, int& ans){
        unordered_map<Node*,bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        while(!q.empty()){
            bool flag = false;
            int n = q.size();
            
            for(int i=0; i<n; i++){
                Node* frontNode = q.front();
                q.pop();
                
                if(frontNode->left && !visited.count(frontNode->left)){
                    q.push(frontNode->left);
                    visited[frontNode->left] = true;
                    flag = true;
                }
                
                if(frontNode->right && !visited.count(frontNode->right)){
                    q.push(frontNode->right);
                    visited[frontNode->right] = true;
                    flag = true;
                }
                
                if(nodeToParent[frontNode] && !visited.count(nodeToParent[frontNode])){
                    q.push(nodeToParent[frontNode]);
                    visited[nodeToParent[frontNode]] = true;
                    flag = true;
                }
            }
            
            if(flag){
                ans++;
            }
        }
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> nodeToParent;
        Node* targetNode = childToParentMapping(root, target, nodeToParent);
        
        int ans = 0;
        burnTree(targetNode,nodeToParent,ans);
        return ans;
    }
};
