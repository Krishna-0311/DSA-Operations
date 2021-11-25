#include <stdio.h>
#include<stdlib.h>
#define max 5
int q[max];
int rear=-1;
int front=-1;
void enqueue();
void dequeue();
void display();

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
        enqueue();
        break;
        case 2:
        dequeue();
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
void enqueue(){
    int ele;
    printf("Enter the element to be inserted:");
    scanf("%d",&ele);
    if((front==rear+1)||(front==0 && rear==max-1)){
        printf("queue is full");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%max;
        q[rear]=ele;
    }
}
void dequeue(){
    if(front==-1){
        printf("The queue is empty");
    }
    else if(front==rear){
        printf("the dequeued element is %d",q[front]);
        front=-1;
        rear=-1;
    }
    else{
        front=((front+1)%max);
    }
}
void display(){
    int i;
    for(i=front;i!=rear;i=((i+1)%max)){
        printf("%d ",q[i]);
    }
    printf("%d",q[i]);
}
