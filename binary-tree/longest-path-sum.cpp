//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

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
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
private:
    pair<int, int> solve(Node* root) {
        if(!root) {
            return {0, 0};
        }
        
        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);
        
        int leftLen = leftAns.first;
        int rightLen = rightAns.first;
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        int len, sum;
        if (leftLen > rightLen) {
            len = leftLen + 1;
            sum = leftSum + root->data;
        } else if (leftLen < rightLen) {
            len = rightLen + 1;
            sum = rightSum + root->data;
        } else {
            len = leftLen + 1;
            sum = max(leftSum, rightSum) + root->data;
        }
        
        return {len, sum};
    }
    

public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int, int> ans = solve(root);
        return ans.second;
    }
};

//{ Driver Code Starts.

int main()
{
    string treeString;
    getline(cin, treeString);
    Node *root = buildTree(treeString);
    Solution obj;
    int res = obj.sumOfLongRootToLeafPath(root);
    cout << res << "\n";
    return 0;
}
// } Driver Code Ends
/*
input: 4 2 5 7 1 2 3 N N 6 N
*/
