//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
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
class Solution
{
    private:
    Node* findMiddle(Node* head) {
        Node* fast = head->right; 
        Node* slow = head;
        Node* pre = NULL;
        
        while(fast) {
            pre = slow;
            fast = fast->right;
            if (fast) {
                fast = fast->right;
            }
            slow = slow->right;
        }
        
        if (pre != NULL) {
            pre->right = NULL;
        }
        
        return slow;
    }
    
    Node* sortedListToBST(Node *head) {
        if (!head) {
            return NULL;
        }
        if (!head->right) {
            Node* root = new Node(head->data);
            return root;
        }
        
        Node* midNode = findMiddle(head);
        Node* root = new Node(midNode->data);
        
        root->left = sortedListToBST(head);
        
        root->right = sortedListToBST(midNode->right);
        
        return root;
    }
    
    void convertToDLL(Node *root, Node* &head) {
        if (!root) {
            return ;
        }
    
        convertToDLL(root->right, head);
        root->right = head;
        if (head) {
            head->left = root;
        }
        head = root;
        convertToDLL(root->left, head);
    }

    Node* mergeLLs(Node* head1, Node* head2) { 
    
        Node* head = NULL;
        Node* tail = NULL;
        while(head1 && head2) {
            if(head1->data < head2->data) {
                if (head == NULL) {
                    head = head1;
                    tail = head1;
                } else {
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                }
                head1 = head1->right;
            }
            else {
                if (head == NULL) {
                    head = head2;
                    tail = head2;
                } else {
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                }
                head2 = head2->right;
            }
        }
    
        while(head1) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
    
        while(head2) {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    
        return head;
    }
    
    void inorderSimple(Node* root) {
        if (!root) {
            return ;
        }
        
        inorderSimple(root->left);
        cout << " " << root->data;
        inorderSimple(root->right);
    } 
    
    public:
    vector<int> merge(Node *root1, Node *root2)
    {
        Node* head1 = NULL;
        Node* head2 = NULL;
    
        convertToDLL(root1, head1);
        convertToDLL(root2, head2);
    
        Node* head = mergeLLs(head1, head2);
        
        Node* root = sortedListToBST(head);
        
        cout << "\ninorder: ";
        inorderSimple(root);
        
        cout << "\n === end === \n";
    
        vector<int> ans;
    
        while(head) {
            ans.push_back(head->data);
            head = head -> right;
        }
    
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    string s; 
   getline(cin, s);
   Node* root1 = buildTree(s);

   getline(cin, s);
   Node* root2 = buildTree(s);

   // getline(cin, s);
   Solution obj;
   vector<int> vec = obj.merge(root1, root2);
   for(int i=0;i<vec.size();i++)
        cout << vec[i] << " ";
    cout << endl;
   ///cout<<"~"<<endl;

   return 0;
}
/*
5 3 6 2 4
2 1 3 N N N 7 6

*/
