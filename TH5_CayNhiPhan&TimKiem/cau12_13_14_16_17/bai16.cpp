#include <iostream>
using namespace std;

struct BST_NODE {
    int Key;
    int So_lan;
    BST_NODE* Left;
    BST_NODE* Right;
};

struct BST_TREE {
    BST_NODE* pRoot;
};

BST_NODE* CreateNode(int x) {
    BST_NODE* p = new BST_NODE;
    p->Key = x;
    p->So_lan = 1;
    p->Left = p->Right = NULL;
    return p;
}

void InsertNode(BST_NODE*& Root, int x) {
    if (Root == NULL) {
        Root = CreateNode(x);
        return;
    }
    if (x < Root->Key)
        InsertNode(Root->Left, x);
    else if (x > Root->Key)
        InsertNode(Root->Right, x);
    else
        Root->So_lan++;
}

int DeleteNode(BST_NODE*& Root, int x) {
    if (Root == NULL) return 0;
    if (x < Root->Key) return DeleteNode(Root->Left, x);
    if (x > Root->Key) return DeleteNode(Root->Right, x);
    if (Root->So_lan > 1) {
        Root->So_lan--;
        return 1;
    }
    if (Root->Left == NULL || Root->Right == NULL) {
        BST_NODE* temp = (Root->Left != NULL) ? Root->Left : Root->Right;
        delete Root;
        Root = temp;
    } else {
        BST_NODE* temp = Root->Right;
        while (temp->Left != NULL) temp = temp->Left;
        Root->Key = temp->Key;
        Root->So_lan = temp->So_lan;
        temp->So_lan = 1;
        DeleteNode(Root->Right, temp->Key);
    }
    return 1;
}

void XoaGiaTri(BST_TREE& t, int x) {
    int kq = DeleteNode(t.pRoot, x);
    if (kq == 0)
        cout << "Khong ton tai " << x << endl;
    else
        cout << "Xoa thanh cong " << x << endl;
}

void NLR(BST_NODE* Root) {
    if (Root == NULL) return;
    if (Root->So_lan > 0)
        cout << Root->Key << " (" << Root->So_lan << ") ";
    NLR(Root->Left);
    NLR(Root->Right);
}

void LietKe(BST_TREE t) {
    NLR(t.pRoot);
    cout << endl;
}

int main() {
    BST_TREE t;
    t.pRoot = NULL;

    int arr[] = {10, 5, 15, 3, 9, 7, 12, 18, 20, 10, 9, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        InsertNode(t.pRoot, arr[i]);
    }

    cout << "Cay BST sau khi them: ";
    LietKe(t);

    XoaGiaTri(t, 10);
    cout << "Cay BST sau khi xoa 10: ";
    LietKe(t);

    XoaGiaTri(t, 15);
    cout << "Cay BST sau khi xoa 15: ";
    LietKe(t);

    XoaGiaTri(t, 100);
    return 0;
}

