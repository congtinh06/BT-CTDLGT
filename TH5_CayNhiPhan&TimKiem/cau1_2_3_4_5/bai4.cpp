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

NODE*NhoNhat(TREE Root){
    if(Root==NULL) return NULL;
    NODE*lc=Root;
    while(lc->pLeft) lc=lc->pLeft;
    return lc;
}

NODE*LonNhat(TREE Root){
    if(Root==NULL) return NULL;
    NODE*lc=Root;
    while(lc->pRight) lc=lc->pRight;
    return lc;
}

void LNR(TREE root){
    if(root!=NULL){
        LNR(root->pLeft);
        cout<<root->info<<" ";
        LNR(root->pRight);
    }
}

int main(){
    TREE root=NULL;
    int arr[]={10,5,15,3,9,12,18,7,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<n;i++) InsertNode(root,arr[i]);
    
    cout<<"Cay BST theo LNR: ";
    LNR(root);
    cout<<endl;

    NODE*minNode=NhoNhat(root);
    NODE*maxNode=LonNhat(root);

    if(minNode) cout<<"Phan tu nho nhat: "<<minNode->info<<endl;
    if(maxNode) cout<<"Phan tu lon nhat: "<<maxNode->info<<endl;

    return 0;
}

