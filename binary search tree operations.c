/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int key;
    struct Node*right;
    struct Node*left;
}*root;
struct Node*newnode(int item){
    struct Node*temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}
struct Node*insert(struct Node*root,int key){
    if(root==NULL){
        return newnode(key);
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }
    else if(key>root->key){
        root->right=insert(root->right,key);
    }
    return root;
}
void preorder(struct Node*root){
    if(root!=NULL){
        printf(" %d",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
struct Node*min(struct Node*t){
    if(t->left==NULL){
        return t;
    }
    else{
        return min(t->left);
    }
}
struct Node*max(struct Node*t){
    if(t->right==NULL){
        return t;
    }
    else{
        return max(t->right);
    }
}
struct Node*search(struct Node*root,int key){
    if(root==NULL || root->key==key){
        return root;
    }
    if((root->key)<key){
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}
struct Node*deletenode(struct Node*root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->key){
        root->left=deletenode(root->left,key);
    }
    else if(key>root->key){
        root->right=deletenode(root->right,key);
    }
    else{
        if(root->left==NULL){
            struct Node*temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL){
            struct Node*temp=root->left;
            free(root);
            return temp;
        }
        else{
            
            struct Node*temp=min(root->right);
            root->key=temp->key;
            root->right=deletenode(root->right,temp->key);
        }
    }
    
    return root;
}
int main()
{
    struct Node*temp2,*temp3,*temp4;
    root=insert(root,43);
    insert(root,10);
    insert(root,79);
    insert(root,90);
    insert(root,12);
    insert(root,54);
    insert(root,9);
    insert(root,50);
    printf("\nThe BST is: ");
    preorder(root);
    temp2=min(root);
    printf("The minimum value in the BST is: %d",temp2->key);
    temp3=max(root);
    printf("The maximum value in the BST is: %d",temp3->key);
    temp4=search(root,10);
    if(temp4->key==10){
        printf("\n Hurray");
    }
    else{
        printf("not found!");
    }
    deletenode(root,79);
    printf("\nThe BST after deletion is: ");
    preorder(root);

    return 0;
}

