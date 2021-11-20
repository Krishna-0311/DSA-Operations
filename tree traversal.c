/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*right;
    struct Node*left;
}*root;
struct Node*create(){
    int value;
    struct Node*newnode;
    printf("enter -1 for terminating ");
    scanf("%d",&value);
    if(value==-1){
        return NULL;
    }
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    printf("enter %d values left node",value);
    newnode->left=create();
    printf("enter %d values right node ",value);
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
int main()
{
    root=create();
    printf("\npreorder value is: ");
    preorder(root);
    printf("\npostorder value is: ");
    postorder(root);
    printf("\ninorder value is: ");
    inorder(root);

    return 0;
}
