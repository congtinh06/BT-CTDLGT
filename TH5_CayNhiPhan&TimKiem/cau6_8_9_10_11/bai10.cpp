#include<iostream>
#include<fstream>
using namespace std;
struct NODE{
    float info;
    NODE*pLeft;
    NODE*pRight;
};
typedef NODE*TREE;
NODE*CreateNode(float x){
    NODE*p=new NODE;
    p->info=x;
    p->pLeft=p->pRight=NULL;
    return p;
}
void InsertNode(TREE &root,float x){
    if(root==NULL){
        root=CreateNode(x);
        return;
    }
    if(x<root->info) InsertNode(root->pLeft,x);
    else if(x>root->info) InsertNode(root->pRight,x);
}
void LRN(TREE t,FILE*fp){
    if(t==NULL) return;
    LRN(t->pLeft,fp);
    LRN(t->pRight,fp);
    fwrite(&t->info,sizeof(float),1,fp);
}
int Xuat(const char*filename,TREE t){
    FILE*fp=fopen(filename,"wb");
    if(fp==NULL) return 0;
    LRN(t,fp);
    fclose(fp);
    return 1;
}
void LRN_Display(TREE t){
    if(t==NULL) return;
    LRN_Display(t->pLeft);
    LRN_Display(t->pRight);
    cout<<t->info<<" ";
}
int main(){
    TREE root=NULL;
    float arr[]={10.5,5.2,15.7,3.1,9.8,12.4,18.6,7.3,20.9};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) InsertNode(root,arr[i]);
    cout<<"Cay BST theo LRN: ";
    LRN_Display(root);
    cout<<endl;
    if(Xuat("data.out",root)) cout<<"Xuat file thanh cong!"<<endl;
    else cout<<"Loi khi mo file!"<<endl;

    return 0;
}

