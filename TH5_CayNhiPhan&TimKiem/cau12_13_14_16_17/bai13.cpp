#include <iostream>
#include <cstdio> // S? d?ng cstdio thay vì fstream d? dùng FILE*
using namespace std;

struct NODE {
    float info;
    NODE* pLeft;
    NODE* pRight;
};

typedef NODE* TREE;

NODE* CreateNode(float x) {
    NODE* p = new NODE;
    if (p) {
        p->info = x;
        p->pLeft = p->pRight = NULL;
    }
    return p;
}

void InsertNode(TREE &root, float x) {
    if (root == NULL) {
        root = CreateNode(x);
        return;
    }
    if (x < root->info)
        InsertNode(root->pLeft, x);
    else if (x > root->info)
        InsertNode(root->pRight, x);
}

void NLR(TREE t, FILE* fp) {
    if (t == NULL) return;
    fwrite(&t->info, sizeof(float), 1, fp);
    NLR(t->pLeft, fp);
    NLR(t->pRight, fp);
}

int Xuat(const char *filename, TREE t) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        cerr << "Khong mo duoc file!" << endl;
        return 0;
    }
    NLR(t, fp);
    fclose(fp);
    return 1;
}

int main() {
    TREE root = NULL;
    float arr[] = {10.5, 5.2, 15.8, 3.1, 9.7, 7.6, 12.4, 18.9, 20.3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        InsertNode(root, arr[i]);
    }

    if (Xuat("data.out", root)) {
        cout << "Da luu cay vao file data.out" << endl;
    }
    return 0;
}
