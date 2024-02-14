//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution {
  private:
    void solve(Node* root, int l, int h, Node* &ans) {
        if (!root || ans) {
            return ;
        }
        
        solve(root->left, l, root->data, ans);
        if (ans) { return ; }
        if (!root->left && !root->right) {
            if (l+1 == root->data && root->data+1 == h) {
                ans = root;
                return ;
            }
        }
        solve(root->right, root->data, h, ans);
    }
    
  public:
    bool isDeadEnd(Node *root)
    {
        Node* ans = NULL;
        solve(root, 0, INT_MAX, ans);
        return ans != NULL;
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
 
}

/*
6
8 7 10 2 N 9 13

Logic here used is check the possible range on left & right side of each leaf node.
if in that range we have space for new element than return true else false
*/
