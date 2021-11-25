#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*top=NULL;
void push(int val){
    struct Node*newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    if(top==NULL){
        newnode->next=NULL;
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
    
}
void display(){
    struct Node*temp;
    temp=top;
    printf("The stack is : ");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    
    
}
void pop(){
    struct Node*temm=top;
    temm=temm->next;
    printf("The popped stack is: ");
    while(temm!=NULL){
        printf("%d",temm->data);
        temm=temm->next;
    }
}
void isempty(){
    if(top==NULL){
        printf("isempty stack");
    }
    else{
        printf("is not empty stack\n");
    }
}
void peak(){
    printf("The peak element is %d\n",top->data);
}

int main()
{
    int i,n,value;
    
    printf("enter no of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&value);
        push(value);
    }
    pop();
    display();
    isempty();
    peak();
    

    return 0;
}
