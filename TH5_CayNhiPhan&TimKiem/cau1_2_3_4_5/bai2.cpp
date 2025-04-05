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
    if (p == NULL) return NULL;
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
void SwapTree(TREE &p) {
    if (p == NULL) return;
    NODE* temp = p->pLeft;
    p->pLeft = p->pRight;
    p->pRight = temp;
    SwapTree(p->pLeft);
    SwapTree(p->pRight);
}
int main() {
    TREE root = NULL;
    int arr[] = {10, 5, 15, 3, 7, 12, 18, 20,9};
    int n = sizeof(arr) / sizeof(arr[0]); 
    for (int i = 0; i < n; i++) {
        InsertNode(root, arr[i]);
    }
    cout << "Cay ban dau (LNR): ";
    LNR(root);
    cout << endl;
    SwapTree(root);
    cout << "Cay sau khi hoan doi (LNR): ";
    LNR(root);
    cout << endl;
    return 0;
}

