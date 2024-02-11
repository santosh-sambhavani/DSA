//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    private:
    Node* findLCA(Node* root, int a, int b) {
        if(!root) {
            return NULL;
        }
        
        if (root->data == a || root->data == b) {
            return root;
        }
        
        Node* leftAns = findLCA(root->left, a, b);
        Node* rightAns = findLCA(root->right, a, b);
         
        if (leftAns && rightAns) {
            return root;
        } else if (!leftAns && rightAns) {
            return rightAns;
        } else if (leftAns && !rightAns) {
            return leftAns;
        }
        return NULL;
    }
    
    int findDistUtil(Node* root, int a) {
        if (!root) {
            return -1;
        }
        
        if (root->data == a) {
            return 0;
        }

        int left = findDistUtil(root->left, a);
        int right = findDistUtil(root->right, a);
        
        if (left == -1 && right == -1) {
            return -1;
        } else if (left == -1 && right != -1) {
            return right + 1;
        } else if (left != -1 && right == -1) {
            return left + 1;
        }
    }
    
    public:
    int findDist(Node* root, int a, int b) {
        Node* lcaNode = findLCA(root, a, b);
        
        return findDistUtil(lcaNode, a) + findDistUtil(lcaNode, b);
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {
    string s, ch;
    getline(cin, s);
    
    Node* root = buildTree(s);
    int n1, n2;
    scanf("%d %d ", &n1, &n2);
    Solution ob;
    cout << ob.findDist(root, n1, n2) << endl;
    
    return 0;
}

/*
11 22 44 55 60 70 80
11 80

11 22 44 55 60 70 80
22 80

11 22 44 55 60 70 80
55 80

logic is to find LCA first than find both a & b differently from LCS & sum up the distances

*/
