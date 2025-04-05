#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pLeft;
    NODE* pRight;
};

typedef NODE* TREE;

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void InsertNode(TREE &root, int x) {
    if (root == NULL) {
        root = CreateNode(x);
        return;
    }
    if (x < root->info)
        InsertNode(root->pLeft, x);
    else if (x > root->info)
        InsertNode(root->pRight, x);
}

void LNR(TREE root) {
    if (root != NULL) {
        LNR(root->pLeft);
        cout << root->info << " ";
        LNR(root->pRight);
    }
}

int main() {
    TREE root = NULL;
    int arr[] = {10, 5, 15, 3, 9, 7, 12, 18, 20};
    for (int i = 0; i < 9; i++) {
        InsertNode(root, arr[i]);
    }

    LNR(root);
    return 0;
}

