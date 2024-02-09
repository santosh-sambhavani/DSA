BinaryTreeNode<int>* solve(vector<int> &pre, int &index, int min, int max) {
    if (index == pre.size()) {
        return NULL;
    }
    int data = pre[index];
    if (data < min || data > max) {
        return NULL;
    }

    BinaryTreeNode<int>* node = new BinaryTreeNode<int>(data);
    index++;
    node->left = solve(pre, index, min, node->data);
    node->right = solve(pre, index, node->data, max);
    return node;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int index = 0;
    return solve(preorder, index, INT_MIN, INT_MAX);
}
