
/*
1 2 3 4 5 N 6 N N 7 8 N 9 10 11 N N N 12 N N N 13
8

simply we need to do use queue for each second and node going to burn in that second
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

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
        if (currVal != "N") {

            // Create the right child for the current Node
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
  private:
    Node* createMapping(Node* root, int target, map<Node*, Node*> &nodeToParent)  {
        queue<Node*> q;
        Node* targetNode;
        
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if (front->data == target) {
                targetNode = front;
            }
            
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        
        return targetNode;
    }
    
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
        map<Node*, bool> visited;
        queue<Node*> q;
        int time = 0;
        
        visited[root] = true;
        q.push(root);
        
        while(!q.empty()) {
            
            int size = q.size();
            bool flag = false;
            for(int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    flag= true;
                }
                
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    flag= true;
                }
                
                if(nodeToParent[curr] && !visited[nodeToParent[curr]]) {
                    visited[nodeToParent[curr]] = true;
                    q.push(nodeToParent[curr]);
                    flag= true;
                }
            }
            
            if(flag) {
                time++;
            }   
        }
        
        return time;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> nodeToParent;
        
        // step 1 create mapping to parent for every node 
        // step 2 locate target node
        Node* targetNode = createMapping(root, target, nodeToParent);

        // step 3 burn tree 
        int time = burnTree(targetNode, nodeToParent);
        
        return time;
    }
};


int main() 
{
    string treeString;
    getline(cin, treeString);
    // cout<<treeString<<"\n";
    int target;
    cin>>target;
    // cout<<target<<"\n";

    Node *root = buildTree(treeString);
    Solution obj;
    cout<<obj.minTime(root, target)<<"\n"; 

    cin.ignore();
    return 0;
}

// } Driver Code Ends
