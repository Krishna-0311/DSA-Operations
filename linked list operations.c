#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void insertion_beginning(int val);
void linear_search(int keyval);
void insertionmiddle(int value,int loc);
void specific(int delval);
void deletion();
void middle_loc();
struct Node
{
    int data;
    struct Node*next;
   
}*head=NULL;
int main()
{
    int n,i,value,key,vall,loc,del,xx;
    struct Node*temp;
   
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&value);
        insertion_beginning(value);
    }
    temp=head;
    while (temp!= NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
   
    printf("\n1:linear search,\n2:insertion at middle ,\n3:deletion of firstnode,\n4:specificdeletion \n5:middle_loc");
    scanf("%d",&xx);
    switch(xx){
        case 1:
        printf("Enter the number to be searched:");
        scanf("%d",&key);
        linear_search(key);
        break;
        case 2:
        printf("Enter the number to be inserted and location:");
        scanf("%d%d",&vall,&loc);
        insertionmiddle(vall,loc);
        break;
        case 3:
        deletion();
        break;
        case 4:
        printf("Enter the value to be deleted from the linked list:");
        scanf("%d",&del);
        specific(del);
        break;
        case 5:
        middle_loc();
        break;
    }

    return 0;
}
void insertion_beginning(int val)
{
   
    struct Node*newNode;
    newNode=(struct Node*)malloc((sizeof(struct Node)));
    newNode->data=val;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
}
void linear_search(int keyval){
    struct Node*tem;
    tem=head;
    int count=0;
    while (tem!= NULL) {
        if(keyval==tem->data){
            printf("The given number is present");
            count=count+1;
        }
        tem = tem->next;
    }
    if(count==0){
        printf("The number is not present");
    }
}
void insertionmiddle(int value,int loc){
    struct Node*newno,*temp1,*temp2;
    int i;
    newno=(struct Node*)malloc((sizeof(struct Node)));
    newno->data=value;
    temp1=head;
    if(head==NULL){
        newno->next=NULL;
        head=newno;
    }
    else
    {
        for(i=1;i<loc-1;i++){
           
            temp1=temp1->next;
        }
   
        newno->next=temp1->next;
        temp1->next=newno;
    }
    temp2=head;
    while (temp2!= NULL) {
        printf(" %d ", temp2->data);
        temp2 = temp2->next;
    }
}
void deletion(){
    struct Node*kim,*temm=head;
    if(head==NULL){
        printf("no deletion can be performed");
    }
    else{
        head=head->next;
        free(temm);
    }
    kim=head;
    while(kim!=NULL){
        printf("%d\n",kim->data);
        kim=kim->next;
    }
}
void specific(int delval){
   
    struct Node*temp3,*x,*temp4=head;
    while(temp4->data!=delval){
        if(temp4->next==NULL){
            printf("Entered value is not there.");
        }
        temp3=temp4;
        temp4=temp4->next;
    }
    temp3->next=temp4->next;
    free(temp4);
    x=head;
    while(x!=NULL){
        printf("%d\n",x->data);
        x=x->next;
    }
}
void middle_loc(){
    struct Node*mid,*las;
    mid=head;
    las=head;
    int count=0,i,midd;
    while(mid!=NULL){
        count=count+1;
        mid=mid->next;
    }
    midd=ceil(count/2);
    for(i=0;i<midd;i++){
        las=las->next;
    }
    printf("%dMiddle postion is:%d",las->data,midd);
}