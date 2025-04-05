#include <iostream>
#include <stack>
#include <queue>
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

void NLR_Stack(TREE t) {
    if (t == NULL) return;
    stack<TREE> s;
    s.push(t);
    while (!s.empty()) {
        TREE p = s.top();
        s.pop();
        cout << p->info << " ";
        if (p->pRight) s.push(p->pRight);
        if (p->pLeft) s.push(p->pLeft);
    }
}

void LevelOrder_Queue(TREE t) {
    if (t == NULL) return;
    queue<TREE> q;
    q.push(t);
    while (!q.empty()) {
        TREE p = q.front();
        q.pop();
        cout << p->info << " ";
        if (p->pLeft) q.push(p->pLeft);
        if (p->pRight) q.push(p->pRight);
    }
}

int main() {
    TREE t;
    Init(t);
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        InsertNode(t, a[i]);
    }

    cout << "Duyet NLR (dung stack): ";
    NLR_Stack(t);
    cout << endl;

    cout << "Duyet theo muc (dung queue): ";
    LevelOrder_Queue(t);
    cout << endl;

    return 0;
}

