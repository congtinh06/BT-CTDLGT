#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE *TREE;
void KhoiTaoCay(TREE &Root)
{
    Root = NULL;
}
void ThemNode(TREE &Root, int x)
{
    if (Root == NULL)
    {
        NODE *p = new NODE;
        p->info = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        Root = p;
    }
    else
    {
        if (x < Root->info)
            ThemNode(Root->pLeft, x);
        else
            ThemNode(Root->pRight, x);
    }
}
int DemNode(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = DemNode(Root->pLeft);
    int b = DemNode(Root->pRight);
    return (a + b + 1);
}
int TongNode(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = TongNode(Root->pLeft);
    int b = TongNode(Root->pRight);
    return (a + b + Root->info);
}
float TrungBinhCong(TREE Root)
{
    int s = TongNode(Root);
    int dem = DemNode(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}
int DemDuong(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = DemDuong(Root->pLeft);
    int b = DemDuong(Root->pRight);
    if (Root->info > 0)
        return (a + b + 1);
    return (a + b);
}
int TongDuong(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = TongDuong(Root->pLeft);
    int b = TongDuong(Root->pRight);
    if (Root->info > 0)
        return (a + b + Root->info);
    return (a + b);
}
float TrungBinhDuong(TREE Root)
{
    int s = TongDuong(Root);
    int dem = DemDuong(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}
int DemAm(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = DemAm(Root->pLeft);
    int b = DemAm(Root->pRight);
    if (Root->info < 0)
        return (a + b + 1);
    return (a + b);
}
int TongAm(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = TongAm(Root->pLeft);
    int b = TongAm(Root->pRight);
    if (Root->info < 0)
        return (a + b + Root->info);
    return (a + b);
}
float TrungBinhCongAm(TREE Root)
{
    int s = TongAm(Root);
    int dem = DemAm(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}
float TinhTySo(TREE Root)
{
    int a = TongDuong(Root);
    int b = TongAm(Root);
    if (b == 0)
        return 0;
    return (float)a / b;
}
void LNR(TREE Root)
{
    if (Root != NULL)
    {
        LNR(Root->pLeft);
        cout << Root->info << " ";
        LNR(Root->pRight);
    }
}
int main()
{
    TREE Root;
    KhoiTaoCay(Root);
    int arr[] = {10, -5, 15, -10, 7, 20, -3, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        ThemNode(Root, arr[i]);
    }
    cout << "Cay duyet theo LNR: ";
    LNR(Root);
    cout << endl;
    cout << "Tong cac nut trong cay: " << TongNode(Root) << endl;
    cout << "So luong nut trong cay: " << DemNode(Root) << endl;
    cout << "Trung binh cong cac nut trong cay: " << TrungBinhCong(Root) << endl;
    cout << "Tong cac nut duong: " << TongDuong(Root) << endl;
    cout << "So luong nut duong: " << DemDuong(Root) << endl;
    cout << "Trung binh cong cac nut duong: " << TrungBinhDuong(Root) << endl;
    cout << "Tong cac nut am: " << TongAm(Root) << endl;
    cout << "So luong nut am: " << DemAm(Root) << endl;
    cout << "Trung binh cong cac nut am: " << TrungBinhCongAm(Root) << endl;
    cout << "Ty so tong duong / tong am: " << TinhTySo(Root) << endl;
    return 0;
}

