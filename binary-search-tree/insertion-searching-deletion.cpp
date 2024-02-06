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

void deleteNode(root) {
    
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
    
    // 5
    cout << "\nEnter the node you want to search: ";
    int k = 0;
    cin>>k;
    
    Node* kNode = search(root, k);
    
    cout << "\n=====> searched node is: " << kNode->data;
    
    cout << "\nEnter the node you want to delete: ";
    cin>>k;
    
    Node* deletedNode = deleteNode(root, k);
    cout << "\n=====> deleted node is: " << deletedNode->data;
}



