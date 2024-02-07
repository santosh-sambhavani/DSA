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
	struct tNode *current, *suc;

	if (root == NULL)
		return;

	current = root;
	vector<int> ans;

	while (current != NULL) {
		if (current->right == NULL) {
		    ans.push_back(current->data);
			current = current->left;
		}
		else {
			suc = current->right;
			while (suc->left != NULL && suc->left != current)
				suc = suc->left;

			if (suc->left == NULL) {
				suc->left = current;
				ans.push_back(current->data);
				current = current->right;
			}

			else {
				suc->left = NULL;
				current = current->left;
			}
		} 
	}
	reverse(ans.begin(), ans.end());
	cout << "\n post-order: ";
	for(int index = 0; index < ans.size(); index++ ) {
	    cout << " " << ans[index];
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
	root->right->left = newtNode(4);
	root->right->right = newtNode(5);

	MorrisTraversal(root);

	return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)
