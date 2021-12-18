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
    printf("Enter -1 to terminate the node: ");
    scanf("%d",&value);
    if(value==-1){
        return NULL;
    }
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    printf("Enter %ds left child",value);
    newnode->left=create();
    printf("Enter %ds right child",value);
    newnode->right=create();
    return newnode;
}
struct Node*lca(struct Node*root,int node1,int node2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node1 || root->data==node2){
        return root;
    }
    struct Node*lf;
    struct Node*rf;
    lf=lca(root->left,node1,node2);
    rf=lca(root->left,node1,node2);
    if(lf==NULL){
        return rf;
    }
    else if(rf==NULL){
        return lf;
    }
    else{
        return root;
    }
}
void preorder(struct Node*root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    root=create();
    printf("The preorder is: ");
    preorder(root);
    struct Node*temp;
    temp=lca(root,3,4);
    printf("The Least Common ancestor is: %d",temp->data);
    

    return 0;
}

