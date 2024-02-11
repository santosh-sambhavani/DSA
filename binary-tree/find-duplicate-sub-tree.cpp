//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

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
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  private:
    string solve(Node* root, unordered_map<string, int> &mp) {
        string s = "";
        if (!root) {
            s += '$';
            return s;
        }
        if (!root->left && !root->right) {
            s += to_string(root->data);
            return s;
        }
        s += to_string(root->data);
        s += "/";
        s += "L" + solve(root->left, mp);
        s += "R" + solve(root->right, mp);
        mp[s]++;
        return s;
    }
  
  public:
    int dupSub(Node *root) {
        unordered_map<string, int> mp;
        solve(root, mp);
        for (auto it: mp) {
            if (it.second >= 2) {
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
  string treeString;
  getline(cin >> ws, treeString);
  struct Node* root = buildTree(treeString);
  Solution ob;
  cout << ob.dupSub(root) << "\n";
	return 0;
}
/*
3 1 1 11 1 1 11

3 1 11 11 N N 1

The Logic is to serialize tree to identify any node is left child node or right child node
or NULL child for non leaf nodes. ans store serialized string for each node in map 
and check at last if any key of map repeated more than twice or for twice. 
*/
