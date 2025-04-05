#include<iostream>
using namespace std;

struct NODE{
    int info;
    NODE*pLeft;
    NODE*pRight;
};

typedef NODE*TREE;

NODE*CreateNode(int x){
    NODE*p=new NODE;
    p->info=x;
    p->pLeft=p->pRight=NULL;
    return p;
}

void InsertNode(TREE &root,int x){
    if(root==NULL){
        root=CreateNode(x);
        return;
    }
    if(x<root->info) InsertNode(root->pLeft,x);
    else if(x>root->info) InsertNode(root->pRight,x);
}

int DemNode(TREE t){
    if(t==NULL) return 0;
    return 1+DemNode(t->pLeft)+DemNode(t->pRight);
}

int TongNode(TREE t){
    if(t==NULL) return 0;
    return t->info+TongNode(t->pLeft)+TongNode(t->pRight);
}

void NLR(TREE root){
    if(root!=NULL){
        cout<<root->info<<" ";
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}

int main(){
    TREE root=NULL;
    int arr[]={10,5,15,3,9,12,18,7,20};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++) InsertNode(root,arr[i]);

    cout<<"Cay BST theo NLR: ";
    NLR(root);
    cout<<endl;

    cout<<"So nut trong cay: "<<DemNode(root)<<endl;
    cout<<"Tong gia tri cac nut: "<<TongNode(root)<<endl;

    return 0;
}

