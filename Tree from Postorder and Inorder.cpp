// Approach 1

int findPosition(int in[], int element, int inOrderStartIndex, int inOrderEndIndex){
    for(int i=inOrderStartIndex; i<=inOrderEndIndex; i++){
        if(element == in[i]){
            return i;
        }
    }
    return -1;
}

Node* constructTree(int in[], int post[], int& postOrderIndex, int inOrderStartIndex, int inOrderEndIndex, int n){
    if(postOrderIndex < 0 || inOrderStartIndex > inOrderEndIndex){
        return NULL;
    }
    
    int element = post[postOrderIndex--];
    Node* root = new Node(element);
    
    int position = findPosition(in,element,inOrderStartIndex,inOrderEndIndex);
    
    // Right call pehle iss liye ki h kyuki jo position find krke laa rhe h wo right side me h
    root->right = constructTree(in,post,postOrderIndex,position+1,inOrderEndIndex,n);
    root->left = constructTree(in,post,postOrderIndex,inOrderStartIndex,position-1,n);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postOrderIndex = n-1;
    Node* ans = constructTree(in,post,postOrderIndex,0,n-1,n);
    return ans;
}


// Approach 2

void createMapping(int in[], unordered_map<int,vector<int>>& inOrderIndexMapping, int n){
    for(int i=0; i<n; i++){
        inOrderIndexMapping[in[i]].push_back(i);
    }
}

Node* constructTree(int in[], int post[], int& postOrderIndex, int inOrderStartIndex, int inOrderEndIndex, unordered_map<int,vector<int>>& inOrderIndexMapping, int n){
    if(postOrderIndex < 0 || inOrderStartIndex > inOrderEndIndex){
        return NULL;
    }
    
    int element = post[postOrderIndex--];
    Node* root = new Node(element);
    
    vector<int> position = inOrderIndexMapping[element];
    int i;
    for(i=0; i<position.size(); i++){
        if(position[i]>=inOrderStartIndex && position[i]<=inOrderEndIndex){
            break;
        }
    }
    
    // Right call pehle iss liye ki h kyuki jo position find krke laa rhe h wo right side me h
    root->right = constructTree(in,post,postOrderIndex,position[i]+1,inOrderEndIndex,inOrderIndexMapping,n);
    root->left = constructTree(in,post,postOrderIndex,inOrderStartIndex,position[i]-1,inOrderIndexMapping,n);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    unordered_map<int,vector<int>> inOrderIndexMapping;
    createMapping(in,inOrderIndexMapping,n);
    int postOrderIndex = n-1;
    Node* ans = constructTree(in,post,postOrderIndex,0,n-1,inOrderIndexMapping,n);
    return ans;
}
