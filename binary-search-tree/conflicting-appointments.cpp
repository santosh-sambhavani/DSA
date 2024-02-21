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

void findConflicting(vector<pair<int, int>> &v) {
    Node* root = NULL;
    
    for (auto &ele: v) {
        Node* overlapped = overlapeSearch(root, new Interval(ele.first, ele.second));
        
        if (overlapped) {
            cout << "\n => {" << ele.first << ", " << ele.second<< "}"
                 << " conflicts with " << " {" 
                 << overlapped->i->low << ", " << overlapped->i->high << "}";
        }
        
        root = insert(root, ele);
    }
}

int main() {
    vector<pair<int, int>> v = {{15,16}, {10, 16}, {17,19}, {5, 20}, {18, 30}, {30, 40}};
    
    // Node* root = NULL;
    // for (int i = 0; i < v.size(); i++) {
    //     root = insert(root, v[i]);
    // }
    
    // levelorder(root);
    
    // Node* node = overlapeSearch(root, new Interval(35, 36));
    
    // cout << "\n => Fpund node: " << node->i->low << ", " << node->i->high;
    
    
    findConflicting(v);
}
