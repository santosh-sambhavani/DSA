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

Node* insertInToBST(Node* root, int x) {
    if(!root) {
        root = new Node(x);
        return root;
    }
    Node* curr = root;
    while(true) {
        if (curr->data > x) {
            if (!curr->left) {
                curr->left = new Node(x);
                break;
            }
            curr = curr->left;
        } else {
            if (!curr->right) {
                curr->right = new Node(x);
                break;
            }
            curr = curr->right;
        }
    }
    return root;
}

Node* buildBinarySearchTree() {
    Node* root;
    int x;
    while(true) {
        cin>>x;
        if(x == -1) {
            break;
        }
        root = insertInToBST(root, x);
    }
    return root;
}

Node* search(Node* root, int k) {
    Node* ans = NULL;
    Node* curr = root;
    while (curr) {
        if (k < curr->data) {
            curr = curr->left;
        } else if (curr->data == k) {
            ans = curr;
            break;
        } else {
            curr = curr->right;
        }
    }
    return ans;
}

int getMin(Node* root) {
    int min;
    while(root) {
        min = root->data;
        root = root->left;
    }
    return min;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
        return root;
    } 
    if (key > root->data) {
        root->right = deleteNode(root->right, key);
        return root;
    }
    // if node have 0 child
    if(!root->left && !root->right) {
        delete root;
        return NULL;
    } 
    
    // if node have 1 child
    if (root->left && !root->right) {  
        Node* temp = root->left;
        delete root;
        return temp;
    }
    
    if (!root->left && root->right) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    
    // if node has 2 child
    if (root->left && root->right) {
        int min = getMin(root->right);
        root->data = min;
        root->right = deleteNode(root->right, min);
        return root;
    }
}

void inorder(Node* root) {
    if(!root) return ;
    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
}

int main() {
            
    /*
    example BST:
            10
          /    \
        2       11
      /   \
    1       5
          /   \
        3       6
              /
            4
    */
    
    // 10 2 11 1 5 3 6 4 -1
    cout << "\nInsert data for BST: " ;
	Node* root = buildBinarySearchTree();
    levelOrderTraversal(root);
    
    int k = 0;
    
    // 5
    // cout << "\nEnter the node you want to search: ";
    // cin>>k;
    
    // Node* kNode = search(root, k);
    
    // cout << "\n=====> searched node is: " << kNode->data;

    /*
    5 OR 3 OR 6
    */
    cout << "\nEnter the node you want to delete: ";
    cin>>k;
    
    deleteNode(root, k);
    cout << "\n inorder: ";
    inorder(root);
    levelOrderTraversal(root);
}



