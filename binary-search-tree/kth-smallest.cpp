//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        int i = 0;
        Node* curr = root;
        while(curr) {
            if (!curr->left) {
                i++;
                if (i == k) {
                    return curr->data;
                }
                curr = curr->right;
            }
            
            else {
                Node* pre = curr->left;
                while(pre->right && pre->right != curr) {
                    pre = pre->right;
                }

                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    i++;
                    if (i == k) {
                        return curr->data;
                    }
                    curr = curr->right;
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    string s;
    getline(cin, s);
    Node* root = buildTree(s);

    getline(cin, s);
    int k = stoi(s);
    //  getline(cin, s);
    Solution obj;
    cout << obj.KthSmallestElement(root, k) << endl;
    // cout<<"~"<<endl;
    return 0;
}

/*
40 25 50 12 30 N N 10 15
4

2 1 3 
2

Logic here used is to maintain index with inorder traversal and when it matched with k return the data of that node.
and in question the requirement was to complete in O(1) SC so here we used morris traversal for inorder

*/
// } Driver Code Ends
