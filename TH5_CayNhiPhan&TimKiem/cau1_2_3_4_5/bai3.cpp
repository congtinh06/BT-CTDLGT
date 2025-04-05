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
void LRN(TREE root) {
    if (root != NULL) {
        LRN(root->pLeft);
        LRN(root->pRight);
        cout << root->info << " ";
    }
}
int main() {
    TREE root = NULL;
    int arr[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        InsertNode(root, arr[i]);
    }
    cout << "Ket qua duyet hau tu (LRN): ";
    LRN(root);
    cout << endl;
	return 0;
}

