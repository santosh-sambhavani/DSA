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

class info {
    public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

class Solution{
    private:
    info solve(Node* root, int &maxSize) {
        if (!root) {
            info res;
            res.mini = INT_MAX;
            res.maxi = INT_MIN;
            res.isBST = true;
            res.size = 0;
            return res;
        }
        // 1 4 4 6 8
        info leftAns = solve(root->left, maxSize);
        info rightAns = solve(root->right, maxSize);
        cout << "\n ====+> root: " << root->data;
        cout << "\n \t left: " 
             << " min: " << leftAns.mini
             << " max: " << leftAns.maxi
             << " isBST: " << leftAns.isBST
             << " size: " << leftAns.size;
             
        cout << "\n \t right: " 
             << " min: " << rightAns.mini
             << " max: " << rightAns.maxi
             << " isBST: " << rightAns.isBST
             << " size: " << rightAns.size;
        info res;
        if (
                leftAns.isBST && 
                rightAns.isBST &&
                leftAns.maxi < root->data &&
                rightAns.mini > root->data
           ) {
            res.mini = min(leftAns.mini, root->data);
            res.maxi = max(rightAns.maxi, root->data);
            res.isBST = true;
            res.size = leftAns.size + rightAns.size + 1;
            
            if (res.size > maxSize) {
                maxSize = res.size;
            }
            
            return res;
        }
         
        res.isBST = false;
        return res; 
    }
    
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int maxSize = 1;
    	solve(root, maxSize);
    	return maxSize;
    }
};

int main() {
    string s, ch;
    getline(cin, s);
    
    Node* root = buildTree(s);
    Solution ob;
    
    int ans = ob.largestBst(root);
    cout << "\n===> ans: " << ans << endl;
    return 0;
}
/*
1 4 4 6 8
6 6 3 N 2 9 3 N 8 8 2
*/
// } Driver Code Ends
