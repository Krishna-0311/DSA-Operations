#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX];
int rear=-1;
int front=-1;
void display();
void insert();
void delete();
int main()
{
    int n;
    while(1){
    printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Quit \n");
    printf("Enter the operation to be performed:");
    scanf("%d",&n);
    switch(n){
        case 1:
        insert();
        break;
        case 2:
        delete();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(1);
        default:
        printf("Wrong choice \n");}
    }
    return 0;
}
void insert(){
    int ad_item;
    if(rear==MAX-1){
        printf("overflow/queue is full");
        
    }
    else{
        printf("Enter the element of queue:");
        scanf("%d",&ad_item);
        if(front==-1){
            front=0;
        }
        rear=rear+1;
        q[rear]=ad_item;
    }
    
}
void display(){
    if(front==-1){
        printf("The queue is empty");
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}
void delete(){
    if(front==-1||front>rear){
        printf("Empty");
    }
    else{
        front=front+1;
    }
}
