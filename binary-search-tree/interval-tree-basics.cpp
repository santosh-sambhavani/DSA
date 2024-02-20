#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Interval {
    public: 
    int low;
    int high;
    Interval(int low, int high) {
        this->low = low;
        this->high = high;
    }
};

class Node {
    public:
    int max;
    Interval* i;
    Node* left;
    Node* right;
    Node(int low, int high) {
        this->i = new Interval(low, high);
        this->right = NULL;
        this->left = NULL;
        this->max = high;
    }
};

Node* insert(Node* root, pair<int, int> p) {
    if (!root) {
        return new Node(p.first, p.second);
    }
    
    if (p.first < root->i->low) {
        root->left = insert(root->left, p);
    } else {
        root->right = insert(root->right, p);
    }
    
    if (root->max < p.second) {
        root->max = p.second;
    }
    
    return root;
}

void inorder(Node* root) {
    if (!root) {
        return ;
    }
    
    inorder(root->left);
    cout << "{" << root->i->low << ", " << root->i->high << "}";
    inorder(root->right);
}

void levelorder(Node* root) {
    queue<Node*> q;
    
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();
            
            cout << "{ " << front->i->low << ", " << front->i->high << " }" << " max: " << front->max << "\t";    
        
            if (front->left) {
                q.push(front->left);
            }
            
            if (front->right) {
                q.push(front->right);
            }
        }
        cout << "\n";
    }
}

bool isOverlape(Interval* i1, Interval* i2) {
    return i1->low <= i2->high && i2->low <= i1->high;
}

Node* overlapeSearch(Node* root, Interval* searchInterval) {
    if (!root) {
        return NULL;
    }
    
    if (isOverlape(root->i, searchInterval)) {
        return root;
    }
    
    if (root->max < searchInterval->low) {
        return overlapeSearch(root->right, searchInterval);
    } else {
        return overlapeSearch(root->right, searchInterval);
    }
}

int main() {
    vector<pair<int, int>> v = {{15,20}, {10, 16}, {17,19}, {5, 20}, {12, 30}, {30, 40}};
    
    Node* root = NULL;
    for (int i = 0; i < v.size(); i++) {
        root = insert(root, v[i]);
    }
    
    levelorder(root);
    
    Node* node = overlapeSearch(root, new Interval(35, 36));
    
    cout << "\n => Fpund node: " << node->i->low << ", " << node->i->high;
    
}


