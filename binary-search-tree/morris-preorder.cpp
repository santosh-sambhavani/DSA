#include <bits/stdc++.h>
using namespace std;

/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode {
	int data;
	struct tNode* left;
	struct tNode* right;
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(struct tNode* root)
{
	struct tNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {
		if (current->left == NULL) {
		    cout << current->data << " ";
			current = current->right;
		}
		else {
			pre = current->left;
			while (pre->right != NULL
				&& pre->right != current)
				pre = pre->right;

			if (pre->right == NULL) {
				pre->right = current;
				cout << current->data << " ";
				current = current->left;
			}

			else {
				pre->right = NULL;
				current = current->right;
			}
		} 
	} 
}

struct tNode* newtNode(int data)
{
	struct tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
		 1
		/ \
	   2   3
	  / \
     4	 5
*/
	struct tNode* root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	MorrisTraversal(root);

	return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)
