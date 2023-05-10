#include <iostream>
#include <vector>
using namespace std;
struct BinomialTreeNode {
    int val;
    int degree;
    BinomialTreeNode* parent;
    BinomialTreeNode* child;
    BinomialTreeNode* sibling;
};
BinomialTreeNode* merge(BinomialTreeNode* t1, BinomialTreeNode* t2) {
    if (t1->val > t2->val) {
        swap(t1, t2);
    }
    t1->sibling = t2->child;
    t2->child = t1;
    t1->parent = t2;
    t2->degree++;
    return t2;
}
BinomialTreeNode* createNode(int val) {
    BinomialTreeNode* node = new BinomialTreeNode;
    node->val = val;
    node->degree = 0;
    node->parent = nullptr;
    node->child = nullptr;
    node->sibling = nullptr;
    return node;
}
vector<BinomialTreeNode*> mergeHeaps(vector<BinomialTreeNode*> h1, vector<BinomialTreeNode*> h2) {
    vector<BinomialTreeNode*> res;
    int i = 0, j = 0;
    while (i < h1.size() && j < h2.size()) {
        if (h1[i]->degree <= h2[j]->degree) {
            res.push_back(h1[i++]);
        } else {
            res.push_back(h2[j++]);
        }
    }
    while (i < h1.size()) {
        res.push_back(h1[i++]);
    }
    while (j < h2.size()) {
        res.push_back(h2[j++]);
    }
    for (int k = 0; k < res.size() - 1; k++) {
        res[k]->sibling = res[k+1];
    }
    return res;
}
vector<BinomialTreeNode*> insert(vector<BinomialTreeNode*> heap, int val) {
    BinomialTreeNode* node = createNode(val);
    vector<BinomialTreeNode*> temp = {node};
    return mergeHeaps(heap, temp);
}
vector<BinomialTreeNode*> createBinomialHeap() {
    vector<BinomialTreeNode*> heap;
    int n;
    cout <<"Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cout <<"Enter the value of element "<< i+1 <<": ";
        cin >> val;
        heap = insert(heap, val);
    }
    return heap;
}
int main() {
    vector<BinomialTreeNode*> heap = createBinomialHeap();
    // Print the binomial heap
    for (BinomialTreeNode* node : heap) {
        while (node != nullptr) {
            cout << node->val <<"";
            node = node->child;
        }
    }
    cout << endl;
    return 0;
}
