/*
https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1

*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* solve(int in[], int post[], int start, int end, int &index) {
    if(start > end) {
        return NULL;
    }
    
    int element = post[index--];
    Node* root = new Node(element);
    int pos = start;
    while(pos <= end) {
        if (element == in[pos])
            break;
        pos++;
    }
    
    root->right = solve(in, post, pos+1, end, index);
    root->left = solve(in, post, start, pos-1, index);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int index = n-1;
    return solve(in, post, 0, n-1, index);
}
