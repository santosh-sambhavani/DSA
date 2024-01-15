#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createBinaryTree(Node* root) {
    int data;
    if(root == NULL) {
        cout << "\n Please enter data for root: ";
        cin >> data;
        root = new Node(data);
    }
    
    cout << "\n Please enter the data for left of " << root->data << ": ";
    cin>>data;
    root->left = data != -1 ? new Node(data) : NULL;
    if(root->left) {
        root->left = createBinaryTree(root->left);
    }
    
    cout << "\n Please enter the data for right of " << root->data << ": ";
    cin>>data;
    root->right = data != -1 ? new Node(data) : NULL;
    if(root->right) {
        root->right = createBinaryTree(root->right);
    }
    
    return root;
}

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << " " << v[i];
    }
}

void levelOrderTraversal(Node* root) {
    
    queue<Node* > q;
    
    q.push(root);
    q.push(NULL);
    
    cout << "\n Level order traversal: \n";
    while(!q.empty()) {
        Node* curr = q.front();
        if(curr == NULL) {
            cout << "\n";
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << " " << curr->data;
            if(curr->left) {
                q.push(curr->left);
            } 
            if(curr->right) {
                q.push(curr->right);
            }
            q.pop();
        }
    }
}

void reverseLevelOrderTraversal(Node* root) {
    queue<Node*> q;
    stack<Node*> s;
    
    q.push(root);
    q.push(NULL);
    
    cout << "\n Reverse Level order traversal: \n";
    while(!q.empty()) {
        Node* curr = q.front();
        if(curr == NULL) {
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
                s.push(NULL);
            }
        } else {
            s.push(curr);
            if(curr->right) {
                q.push(curr->right);
            }
            if(curr->left) {
                q.push(curr->left);
            } 
            q.pop();
        }
    }
    
    while(!s.empty()) {
        Node* curr = s.top();
        if(curr == NULL) {
            cout << "\n";
        } else {
            cout << " " << curr->data;
        }
        s.pop();
    }
}

void inorder(Node* root) {
    if(!root) {
        return ;
    } 
    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
}

void inorder_iterative(Node* root) {
    stack<Node*> s;
    vector<int> ans;
    
    Node* curr = root;
    while(true) {
        if(curr) {
            s.push(curr);
            curr = curr->left;
        } else {
            if(s.empty()) {
                break;
            }
            curr = s.top();
            ans.push_back(curr->data);
            curr = curr->right;
            s.pop();
        }
    }
    
    printVector(ans);
}

void preorder(Node* root) {
    if(!root) {
        return ;
    } 
    cout << " " << root->data;
    preorder(root->left);
    preorder(root->right);
}

void preorder_iterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    vector<int> ans;
    
    while(true) {
        if(curr) {
            ans.push_back(curr->data);
            s.push(curr);
            curr = curr->left;
        } else {
            if(s.empty()) {
                break;
            }
            curr = s.top();
            curr = curr->right;
            s.pop();
        }
    }
    printVector(ans);
}

void postorder(Node* root) {
    if(!root) {
        return ;
    } 
    postorder(root->left);
    postorder(root->right);
    cout << " " << root->data;
}

void postorder_iterative(Node* root) {
    stack<Node*> s1;
    stack<Node*> s2;
    Node* curr = root;
    
    s1.push(root);
    while(!s1.empty()) {
        curr = s1.top();
        s1.pop();
        
        s2.push(curr);
        
        if(curr->left) {
            s1.push(curr->left);
        }
        
        if(curr->right) {
            s1.push(curr->right);
        }
    }
    
    while(!s2.empty()) {
        cout << " " << s2.top()->data;
        s2.pop();
    }
}

int main() {

    Node* root = createBinaryTree(NULL);
    
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // cout << "\n===> root: " << root->data;
    // cout << "\n===> root left: " << root->left->data;
    // cout << "\n===> root right: " << root->right->data;
    
    levelOrderTraversal(root);
    // reverseLevelOrderTraversal(root);
    
    // cout << "\n Inorder traversal recursive: ";
    // inorder(root);
    
    // cout << "\n Inorder traversal iterative: ";
    // inorder_iterative(root);
    
    // cout << "\n Preorder traversal recursive: ";
    // preorder(root);
    
    // cout << "\n Preorder traversal iterative: ";
    // preorder_iterative(root);
    
    cout << "\n Postorder traversal recursive: ";
    postorder(root);
    
    cout << "\n Postorder traversal iterative: ";
    postorder_iterative(root);
    
    return 0;
}

/*
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

               
               1
             /   \
           2      3
         / \     /  \
        4   5   6    7


*/
