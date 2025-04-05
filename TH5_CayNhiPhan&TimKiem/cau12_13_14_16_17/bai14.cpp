#include <iostream>
using namespace std;

struct NODETREE {
    int info;
    NODETREE* pLeft;
    NODETREE* pRight;
};
typedef NODETREE* TREE;

struct NODELIST {
    int info;
    NODELIST* pNext;
};
typedef struct NODELIST NODELIST;

struct LIST {
    NODELIST* pHead;
    NODELIST* pTail;
};
typedef struct LIST LIST;

void Init(LIST &l) {
    l.pHead = l.pTail = NULL;
}

NODELIST* GetNode(int x) {
    NODELIST* p = new NODELIST;
    if (p == NULL) return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &l, NODELIST* p) {
    if (l.pHead == NULL) 
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void RNL(TREE Root, LIST &l) {
    if (Root == NULL) return;
    RNL(Root->pRight, l);
    NODELIST* p = GetNode(Root->info);
    if (p != NULL) AddTail(l, p);
    RNL(Root->pLeft, l);
}

void BuildList(TREE Root, LIST &l) {
    Init(l);
    RNL(Root, l);
}

NODETREE* CreateNode(int x) {
    NODETREE* p = new NODETREE;
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

void PrintList(LIST l) {
    NODELIST* p = l.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

int main() {
    TREE root = NULL;
    int arr[] = {10, 5, 15, 3, 9, 7, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        InsertNode(root, arr[i]);
    }

    LIST l;
    BuildList(root, l);

    PrintList(l);

    return 0;
}

