#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cout<<"Enter the value of data ";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* newNode = new Node(data);

    cout << "Enter the data for left child of " << data << endl;
    newNode->left = buildTree();

    cout << "Enter the data for right child of " << data << endl;
    newNode->right = buildTree(); 

    return newNode;
}

void buildTreeFromLvlOrderTraversal(Node* &root){
    cout<<"Enter the value of root ";
    int data;
    cin>>data;
    root = new Node(data);
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the value of left child of "<<temp->data<<endl;
        cout<<"Enter the value ";
        int leftData;
        cin>>leftData;
        
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the value of right child of "<<temp->data<<endl;
        cout<<"Enter the value ";
        int rightData;
        cin>>rightData;
        
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }

    }
}

int main(){
    Node* root = NULL;
    // root = buildTree();

    buildTreeFromLvlOrderTraversal(root);
    
}
