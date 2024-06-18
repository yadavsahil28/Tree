// Approach 1

class Solution{
    public:
    
    int findPosition(int in[], int element, int inOrderStartIndex, int inOrderEndIndex){
        for(int i=inOrderStartIndex; i<=inOrderEndIndex; i++){
            if(element == in[i]){
                return i;
            }
        }
        return -1;
    }
    
    Node* constructTree(int in[], int pre[], int& preOrderIndex, int inOrderStartIndex, int inOrderEndIndex, int n){
        if(preOrderIndex >= n || inOrderStartIndex > inOrderEndIndex){
            return NULL;
        }
        
        int element = pre[preOrderIndex++];
        Node* root = new Node(element);
        
        int position = findPosition(in,element,inOrderStartIndex,inOrderEndIndex);
        
        root->left = constructTree(in,pre,preOrderIndex,inOrderStartIndex,position-1,n);
        root->right = constructTree(in,pre,preOrderIndex,position+1,inOrderEndIndex,n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        Node* ans = constructTree(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }
};


// Approach 2

class Solution{
    public:
    
    void createMapping(int in[], unordered_map<int,vector<int>>& inOrderIndexMapping, int n){
        for(int i=0; i<n; i++){
            inOrderIndexMapping[in[i]].push_back(i);
        }
    }
    
    Node* constructTree(int in[], int pre[], int& preOrderIndex, int inOrderStartIndex, int inOrderEndIndex,unordered_map<int, vector<int>>& inOrderIndexMapping, int n){
        if(preOrderIndex >= n || inOrderStartIndex > inOrderEndIndex){
            return NULL;
        }
        
        int element = pre[preOrderIndex++];
        Node* root = new Node(element);
        
        vector<int> position = inOrderIndexMapping[element];
        int i;
        for(i=0; i<position.size(); i++){
            if(position[i]>=inOrderStartIndex && position[i]<=inOrderEndIndex){
                break;
            }
        }
        
        root->left = constructTree(in,pre,preOrderIndex,inOrderStartIndex,position[i]-1,inOrderIndexMapping,n);
        root->right = constructTree(in,pre,preOrderIndex,position[i]+1,inOrderEndIndex,inOrderIndexMapping,n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int,vector<int>> inOrderIndexMapping;
        createMapping(in,inOrderIndexMapping,n);
        int preOrderIndex = 0;
        Node* ans = constructTree(in,pre,preOrderIndex,0,n-1,inOrderIndexMapping,n);
        return ans;
    }
};
