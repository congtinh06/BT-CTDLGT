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
void NLR(TREE t,FILE*fp){
    if(t==NULL) return;
    fwrite(&t->info,sizeof(float),1,fp);
    NLR(t->pLeft,fp);
    NLR(t->pRight,fp);
}
int Xuat(const char*filename,TREE t){
    FILE*fp=fopen(filename,"wb");
    if(fp==NULL) return 0;
    NLR(t,fp);
    fclose(fp);
    return 1;
}
void NLR_Display(TREE t){
    if(t==NULL) return;
    cout<<t->info<<" ";
    NLR_Display(t->pLeft);
    NLR_Display(t->pRight);
}
int main(){
    TREE root=NULL;
    float arr[]={10.5,5.2,15.7,3.1,9.8,12.4,18.6,7.3,20.9};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) InsertNode(root,arr[i]);
    cout<<"Cay BST theo NLR: ";
    NLR_Display(root);
    cout<<endl;
    if(Xuat("data.out",root)) cout<<"Xuat file thanh cong!"<<endl;
    else cout<<"Loi khi mo file!"<<endl;
    return 0;
}

