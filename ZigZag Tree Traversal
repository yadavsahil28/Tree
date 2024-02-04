class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	bool leftToRight = true;
    	queue<Node*> q;
    	q.push(root);
    	
    	while(!q.empty()){
    	    int n = q.size();
    	    vector<int> lvl(n);
    	    
    	    for(int i=0; i<n; i++){
    	        Node* frontNode = q.front();
    	        q.pop();
    	        
    	        int index = leftToRight ? i : n-i-1;
    	        lvl[index] = frontNode->data;
    	        
    	        if(frontNode->left){
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right){
    	            q.push(frontNode->right);
    	        }
    	    }
    	    leftToRight = !leftToRight;
    	    for(int i=0; i<n; i++){
    	        ans.push_back(lvl[i]);
    	    }
    	}
    	return ans;
    }
};
