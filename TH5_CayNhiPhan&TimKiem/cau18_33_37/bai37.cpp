#include <iostream>
#include <cmath>
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

int ChieuCao(TREE t) {
    if (t == NULL) return 0;
    int a = ChieuCao(t->pLeft);
    int b = ChieuCao(t->pRight);
    return max(a, b) + 1;
}

bool ktCanBang(TREE Root) {
    if (Root == NULL) return true;
    int x = ChieuCao(Root->pLeft);
    int y = ChieuCao(Root->pRight);
    if (abs(x - y) > 1) return false;
    return ktCanBang(Root->pLeft) && ktCanBang(Root->pRight);
}

int main() {
    TREE t;
    Init(t);
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        InsertNode(t, a[i]);
    }

    if (ktCanBang(t))
        cout << "Cay can bang\n";
    else
        cout << "Cay khong can bang\n";

    return 0;
}

