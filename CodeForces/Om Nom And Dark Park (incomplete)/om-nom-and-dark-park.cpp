/*
Problem Name: 
Link to problem: 
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void createTree(Node* current, int depth, int currentdepth, vector<int>& streetlamps, int index) {
    if (currentdepth == depth) return;
    if (index >= streetlamps.size()) return;
    if (currentdepth == 0){
        current->left = new Node(0);
        current->right = new Node(0);
        createTree(current->left, depth, currentdepth + 1, streetlamps, index);
        createTree(current->right, depth, currentdepth + 1, streetlamps, index + 1);
        return;
    }
    current->data = streetlamps[index];
    current->left = new Node(0);
    current->right = new Node(0);
    cout << current->data << " ";
    createTree(current->left, depth, currentdepth + 1, streetlamps, index + 1);
    createTree(current->right, depth, currentdepth + 1, streetlamps, index + 2);
}

int main() {
    int n; cin >> n;
    vector<int> streetlamps(pow(2, n + 1) - 2);
    for (int i = 0; i < pow(2, n + 1) - 2; i++) {
        cin >> streetlamps[i];
    }
    Node* root = new Node(0);
    createTree(root, n, 0, streetlamps, 0);
}