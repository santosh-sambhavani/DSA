/*
logic is to get leftSum & rightSum & return result if it's not leaf-node
inputs
3 1 2
10 20 30 10 10 N N
70 20 30 10 10 N N
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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


// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    pair<bool, int> solve(Node* root) {
        if(!root) {
            return {true, 0};
        }
        
        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        if(!leftAns || !rightAns) {
            return {false, -1};
        }
        
        int leftSum = left.second;
        int rightSum = right.second;
        
        bool ans = (leftSum + rightSum == 0) ? true : (leftSum + rightSum == root->data);
        return { ans, leftSum+rightSum+root->data };
    }
    public:
    bool isSumTree(Node* root)
    {
        pair<bool, int> p = solve(root);
        return p.first;
    }
};

//{ Driver Code Starts.

int main()
{

    string s;
		getline(cin,s);
    Node* root = buildTree(s);
    Solution ob;
    cout <<ob.isSumTree(root) << endl;
    return 1;
}
// } Driver Code Ends
