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

void SearchStandFor(TREE &p, TREE &q) {
    if (q->pLeft) {
        SearchStandFor(p, q->pLeft);
    } else {
        p->info = q->info;
        p = q;
        q = q->pRight;
    }
}

void DeleteNode(TREE &root, int x) {
    if (root == NULL) return;
    
    if (x < root->info) {
        DeleteNode(root->pLeft, x);
    } else if (x > root->info) {
        DeleteNode(root->pRight, x);
    } else {
        NODE* p = root;
        if (root->pLeft == NULL) {
            root = root->pRight;
        } else if (root->pRight == NULL) {
            root = root->pLeft;
        } else {
            SearchStandFor(p, root->pRight);
        }
        delete p;
    }
}

void NLR(TREE root) {
    if (root == NULL) return;
    cout << root->info << " ";
    NLR(root->pLeft);
    NLR(root->pRight);
}

int main() {
    TREE root = NULL;
    int arr[] = {65, 35, 80, 21, 44, 77, 92, 10, 70, 5, 17, 28, 55, 48, 53, 60, 59, 97, 94, 93, 95, 98, 90, 68, 66, 69, 72, 74};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        InsertNode(root, arr[i]);
    }

    cout << "Cay truoc khi xoa: ";
    NLR(root);
    cout << endl;

    int x = 92;
    DeleteNode(root, x);

    cout << "Cay sau khi xoa " << x << ": ";
    NLR(root);
    cout << endl;

    return 0;
}

