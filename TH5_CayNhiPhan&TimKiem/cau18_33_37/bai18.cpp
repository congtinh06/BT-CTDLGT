#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pLeft;
    NODE* pRight;
};

typedef NODE* TREE;

void Init(TREE &t) {
    t = NULL;
}

NODE* GetNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

int InsertNode(TREE &t, int x) {
    if (t) {
        if (t->info == x) return 0;
        if (t->info < x) return InsertNode(t->pRight, x);
        return InsertNode(t->pLeft, x);
    }
    t = GetNode(x);
    if (t == NULL) return -1;
    return 1;
}

int TaoCay(TREE &t, int a[], int n) {
    Init(t);
    for (int i = 0; i < n; i++) {
        if (InsertNode(t, a[i]) == -1) return 0;
    }
    return 1;
}

void LNR(TREE t, int a[], int &n) {
    if (t == NULL) return;
    LNR(t->pLeft, a, n);
    a[n++] = t->info;
    LNR(t->pRight, a, n);
}

void SortArrayUsingBST(int a[], int n) {
    TREE t;
    TaoCay(t, a, n);
    int index = 0;
    LNR(t, a, index);
}

int main() {
    int a[] = {64, 37, 78, 10, 57, 69, 82, 6, 67, 93};
    int n = sizeof(a) / sizeof(a[0]);

    SortArrayUsingBST(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

