/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}*root;
struct Node*create(){
    struct Node*newnode;
    int value;
    printf("enter -1 for terminating the node: ");
    scanf("%d",&value);
    if(value==-1){
        return NULL;
    }
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    printf("enter %ds left child value: ",value);
    newnode->left=create();
    printf("enter %ds right child value: ",value);
    newnode->right=create();
    return newnode;
}
void preorder(struct Node*root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
void inorder(struct Node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
int height(struct Node*root){
    if(root==NULL){
        return -1;
    }
    int lt=height(root->left);
    int rt=height(root->right);
    if(lt>rt){
        return lt+1;
    }
    else{
        return rt+1;
    }
    
}
void levelorder(struct Node*root,int level){
    if(root==NULL){
        return ;
    }
    if(level==1){
        printf("%d",root->data);
    }
    else if(level>1){
        levelorder(root->left,level-1);
        levelorder(root->right,level-1);
    }
}

int main()
{
    root=create();
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\ninorder: ");
    inorder(root);
    int ht=height(root);
    printf("\nThe height of the tree is %d",ht);
    printf("\nThe level order: ");
    for(int i=1;i<=ht+1;i++){
        levelorder(root,i);
    }
    

    return 0;
}

