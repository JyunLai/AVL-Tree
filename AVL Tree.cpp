#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> Roatation;
struct AVLnode{
    int data=0;
    int height=1;
    struct AVLnode *left=NULL;
    struct AVLnode *right=NULL;
};
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int height(AVLnode *node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}
int getBalance(AVLnode *node){
    if(node==NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}
AVLnode *LLRotatation(AVLnode *Anode){
    AVLnode *Bnode=(AVLnode *)malloc(sizeof(AVLnode));
    Bnode->height=1;
    Bnode->data=0;
    Bnode->left=NULL;
    Bnode->right=NULL;
    Bnode=Anode->left;
    if(Bnode->right==NULL){
        Bnode->right=Anode;
        Anode->left=NULL;
    }
    else{
        AVLnode *T2node=(AVLnode *)malloc(sizeof(AVLnode));
        T2node->height=1;
        T2node->data=0;
        T2node->left=NULL;
        T2node->right=NULL;
        T2node=Bnode->right;
        Bnode->right=Anode;
        Anode->left=T2node;
    }
    Anode->height=max(height(Anode->left),height(Anode->right))+1;
    Bnode->height=max(height(Bnode->left),height(Bnode->right))+1;
    return Bnode;
}
AVLnode *RRRoatation(AVLnode *Anode){
    AVLnode *Bnode=(AVLnode *)malloc(sizeof(AVLnode));
    Bnode->height=1;
    Bnode->data=0;
    Bnode->left=NULL;
    Bnode->right=NULL;
    Bnode=Anode->right;
    if(Bnode->left==NULL){
        Bnode->left=Anode;
        Anode->right=NULL;
    }
    else{
        AVLnode *T2node=(AVLnode *)malloc(sizeof(AVLnode));
        T2node->height=1;
        T2node->data=0;
        T2node->left=NULL;
        T2node->right=NULL;
        T2node=Bnode->left;
        Bnode->left=Anode;
        Anode->right=T2node;
    }
    Anode->height=max(height(Anode->left),height(Anode->right))+1;
    Bnode->height=max(height(Bnode->left),height(Bnode->right))+1;
    return Bnode;
}
AVLnode *LRRoatation(AVLnode *Anode){
    AVLnode *Bnode=(AVLnode *)malloc(sizeof(AVLnode));
    Bnode->height=1;
    Bnode->data=0;
    Bnode->left=NULL;
    Bnode->right=NULL;
    AVLnode *Cnode=(AVLnode *)malloc(sizeof(AVLnode));
    Cnode->height=1;
    Cnode->data=0;
    Cnode->left=NULL;
    Cnode->right=NULL;
    Bnode=Anode->left;
    Cnode=Bnode->right;
    if(Cnode->left==NULL&&Cnode->right==NULL){
        Cnode->left=Bnode;
        Cnode->right=Anode;
        Bnode->right=NULL;
        Anode->left=NULL;
    }
    else if(Cnode->left==NULL){
        AVLnode *T3node=(AVLnode *)malloc(sizeof(AVLnode));
        T3node->height=1;
        T3node->data=0;
        T3node->left=NULL;
        T3node->right=NULL;
        T3node=Cnode->right;
        Cnode->left=Bnode;
        Cnode->right=Anode;
        Anode->left=T3node;
        Bnode->right=NULL;
    }
    else if(Cnode->right==NULL){
        AVLnode *T2node=(AVLnode *)malloc(sizeof(AVLnode));
        T2node->height=1;
        T2node->data=0;
        T2node->left=NULL;
        T2node->right=NULL;
        T2node=Cnode->left;
        Cnode->left=Bnode;
        Cnode->right=Anode;
        Bnode->right=T2node;
        Anode->left=NULL;
    }
    else{
        AVLnode *T2node=(AVLnode *)malloc(sizeof(AVLnode));
        T2node->height=1;
        T2node->data=0;
        T2node->left=NULL;
        T2node->right=NULL;
        AVLnode *T3node=(AVLnode *)malloc(sizeof(AVLnode));
        T3node->height=1;
        T3node->data=0;
        T3node->left=NULL;
        T3node->right=NULL;
        T2node=Cnode->left;
        T3node=Cnode->right;
        Cnode->left=Bnode;
        Cnode->right=Anode;
        Bnode->right=T2node;
        Anode->left=T3node;
    }
    Anode->height=max(height(Anode->left),height(Anode->right))+1;
    Bnode->height=max(height(Bnode->left),height(Bnode->right))+1;
    Cnode->height=max(height(Cnode->left),height(Cnode->right))+1;
    return Cnode;
}
AVLnode *RLRoatation(AVLnode *Anode){
    AVLnode *Bnode=(AVLnode *)malloc(sizeof(AVLnode));
    Bnode->height=1;
    Bnode->data=0;
    Bnode->left=NULL;
    Bnode->right=NULL;
    AVLnode *Cnode=(AVLnode *)malloc(sizeof(AVLnode));
    Cnode->height=1;
    Cnode->data=0;
    Cnode->left=NULL;
    Cnode->right=NULL;
    Bnode=Anode->right;
    Cnode=Bnode->left;
    if(Cnode->left==NULL&&Cnode->right==NULL){
        Cnode->left=Anode;
        Cnode->right=Bnode;
        Anode->right=NULL;
        Bnode->left=NULL;
    }
    else if(Cnode->left==NULL){
        AVLnode *T3node=(AVLnode *)malloc(sizeof(AVLnode));
        T3node->height=1;
        T3node->data=0;
        T3node->left=NULL;
        T3node->right=NULL;
        T3node=Cnode->right;
        Cnode->left=Anode;
        Cnode->right=Bnode;
        Anode->right=NULL;
        Bnode->left=T3node;
    }
    else if(Cnode->right==NULL){
        AVLnode *T2node=(AVLnode *)malloc(sizeof(AVLnode));
        T2node->height=1;
        T2node->data=0;
        T2node->left=NULL;
        T2node->right=NULL;
        T2node=Cnode->left;
        Cnode->left=Anode;
        Cnode->right=Bnode;
        Anode->right=T2node;
        Bnode->left=NULL;
    }
    else{
        AVLnode *T2node=(AVLnode *)malloc(sizeof(AVLnode));
        T2node->height=1;
        T2node->data=0;
        T2node->left=NULL;
        T2node->right=NULL;
        AVLnode *T3node=(AVLnode *)malloc(sizeof(AVLnode));
        T3node->height=1;
        T3node->data=0;
        T3node->left=NULL;
        T3node->right=NULL;
        T2node=Cnode->left;
        T3node=Cnode->right;
        Cnode->left=Anode;
        Cnode->right=Bnode;
        Anode->right=T2node;
        Bnode->left=T3node;
    }
    Anode->height=max(height(Anode->left),height(Anode->right))+1;
    Bnode->height=max(height(Bnode->left),height(Bnode->right))+1;
    Cnode->height=max(height(Cnode->left),height(Cnode->right))+1;
    return Cnode;
}
AVLnode *Insert(AVLnode *root,int i){
    if(i==root->data){
        return root;
    }
    else if(i>root->data){
        if(root->right==NULL){
            AVLnode *root1=(AVLnode *)malloc(sizeof(AVLnode));
            root1->data=i;
            root1->height=1;
            root1->left=NULL;
            root1->right=NULL;
            root->right=root1;
        }
        else{
            root->right=Insert(root->right,i);
        }
    }
    else if(i<root->data){
        if(root->left==NULL){
            AVLnode *root1=(AVLnode *)malloc(sizeof(AVLnode));
            root1->data=i;
            root1->height=1;
            root1->left=NULL;
            root1->right=NULL;
            root->left=root1;
        }
        else{
            root->left=Insert(root->left,i);
        }
    }
    root->height=max(height(root->left),height(root->right))+1;
    int balance=getBalance(root);
    if(balance==1||balance==0||balance==-1){
        return root;
    }
    else if(balance>1&&i<root->left->data){
        Roatation.push_back(1);
        return LLRotatation(root);
    }
    else if(balance<-1&&i>root->right->data){
        Roatation.push_back(2);
        return RRRoatation(root);
    }
    else if(balance>1&&i>root->left->data){
        Roatation.push_back(3);
        return LRRoatation(root);
    }
    else if(balance<-1&&i<root->right->data){
        Roatation.push_back(4);
        return RLRoatation(root);
    }
    return root;
}
AVLnode *Delete(AVLnode *root,int i){
    if(root==NULL){
        return root;
    }
    else if(i==root->data){
        if(root->right==NULL){
            return root->left;
        }
        else if(root->left==NULL){
            return root->right;
        }
        else{
            AVLnode *root1=(AVLnode *)malloc(sizeof(AVLnode));
            root1->height=1;
            root1->data=0;
            root1->left=NULL;
            root1->right=NULL;
            root1=root->right;
            while(root1->left!=NULL){
                root1=root1->left;
            }
            root->data=root1->data;
            root->right=Delete(root->right,root1->data);
        }
    }
    else if(i>root->data){
        root->right=Delete(root->right,i);
    }
    else if(i<root->data){
        root->left=Delete(root->left,i);
    }
    switch(getBalance(root)){
        case 2:
            switch(getBalance(root->left)){
                case 0:
                    Roatation.push_back(5);
                    return LLRotatation(root);
                    break;
                case 1:
                    Roatation.push_back(6);
                    return LLRotatation(root);
                    break;
                case -1:
                    Roatation.push_back(7);
                    return LRRoatation(root);
                    break;
                default:
                    break;
            }
            break;
        case -2:
            switch(getBalance(root->right)){
                case 0:
                    Roatation.push_back(5);
                    return RRRoatation(root);
                    break;
                case 1:
                    Roatation.push_back(6);
                    return RLRoatation(root);
                    break;
                case -1:
                    Roatation.push_back(7);
                    return RRRoatation(root);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    root->height=max(height(root->left),height(root->right))+1;
    return root;
}
void Inorder(AVLnode *root){
    if(root->left!=NULL){
        Inorder(root->left);
        printf(" ");
    }
    printf("%d",root->data);
    if(root->right!=NULL){
        printf(" ");
        Inorder(root->right);
    }
    return;
}
int main(){
    AVLnode *root=(AVLnode *)malloc(sizeof(AVLnode));
    vector<char> c;
    char c1;
    int i=0;
    scanf("%c",&c1);
    if((int)c1>=49&&(int)c1<=57){
        while((int)c1>=48&&(int)c1<=57){
            c.push_back(c1);
            scanf("%c",&c1);
        }
        for(int j=(int)c.size()-1;j>=0;j--){
            i+=((int)c[j]-48)*pow(10,(int)c.size()-j-1);
        }
        root->data=i;
        root->height=1;
        root->left=NULL;
        root->right=NULL;
        if(c1==','){
            goto here;
        }
    }
    else if(c1=='I'){
        scanf("%d",&i);
        root->data=i;
        root->height=1;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        root=NULL;
    }
    while(scanf("%c",&c1)!=EOF){
        if(c1==','){
            here:;
            scanf("%d",&i);
            root=Insert(root,i);
        }
        else if(c1=='I'){
            scanf("%d",&i);
            root=Insert(root,i);
        }
        else if(c1=='D'){
            scanf("%d",&i);
            root=Delete(root,i);
        }
    }
    Inorder(root);
    printf("\n%d\n",(int)Roatation.size());
    for(int j=0;j<Roatation.size();j++){
        switch(Roatation[j]){
            case 1:
                printf("LL");
                break;
            case 2:
                printf("RR");
                break;
            case 3:
                printf("LR");
                break;
            case 4:
                printf("RL");
                break;
            case 5:
                printf("R0");
                break;
            case 6:
                printf("R1");
                break;
            case 7:
                printf("R-1");
                break;
            default:
                break;
        }
        if(j!=Roatation.size()-1){
            printf(",");
        }
    }
    free(root);
    return 0;
}
