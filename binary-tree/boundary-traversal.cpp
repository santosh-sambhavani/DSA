#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution {
private:
    void leftBoundary(Node* root, vector<int> &ans) {
        if(!root->left && !root->right) {
            return ;
        }
        ans.push_back(root->data);
        if(root->left) {
            leftBoundary(root->left, ans);
        } else {
            leftBoundary(root->right, ans);
        }
    }
    
    void rightBoundary(Node* root, vector<int> &ans) {
        if(!root->left && !root->right) {
            return ;
        }
        
        if(root->right) {
            rightBoundary(root->right, ans);
        } else {
            rightBoundary(root->left, ans);
        }
        ans.push_back(root->data);
    }
    
    void addLeafNodes(Node* root, vector<int> &ans) {
        if(!root) {
            return ;
        }
        
        addLeafNodes(root->left, ans);
        
        if(!root->left && !root->right) {
            ans.push_back(root->data);
        }
        
        addLeafNodes(root->right, ans);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        ans.push_back(root->data);
        if(!root->left && !root->right) return ans;
        if(root->left) {
            leftBoundary(root->left, ans);
        }
         
        addLeafNodes(root, ans);
            
        if(root->right) {
            rightBoundary(root->right, ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    string s ,ch;
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    vector <int> res = ob.boundary(root);
    for (int i : res) cout << i << " ";
    cout << endl;
    return 0;
}
/*
input: 6 4 9 N 10 4 5 N 10 1 9 N 8 6 1 N 5 9 3 N 6 8 7 N 4 4

- basic idea is to print left-boundary first than all leaf-nodes & than right boundary in reverse order
- point to be keep in mind is (left-boundary != left-view) and (right-boundary != right-view) and (all-leaf-nodes != bottom-view)
*/
