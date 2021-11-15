#include <stdio.h>
#include<stdlib.h>
void polynomial(int value,int pp);
void polynomial2(int value2,int pp2);
void polynomial3(int value3,int pp3);
struct Node{
    int data,power;
    struct Node*next;
}*head1=NULL,*head2=NULL,*head3=NULL;
int main()
{
    int n=3,i,coff,po,coff2,po2,coff3,po3;
    struct Node*tempp,*tempp2,*tempp3,*dum1,*dum2;
    for(i=0;i<n;i++){
        scanf("%d",&coff);
        scanf("%d",&po);
        polynomial(coff,po);
    }
    for(i=0;i<n;i++){
        scanf("%d",&coff2);
        scanf("%d",&po2);
        polynomial2(coff2,po2);
    }
    
    tempp=head1;
    tempp2=head2;
    while(tempp!=NULL&&tempp2!=NULL){
        if(tempp->power==tempp2->power){
            coff3=((tempp->data)+(tempp2->data));
            po3=tempp->power;
            polynomial3(coff3,po3);
        }
        tempp=tempp->next;
        tempp2=tempp2->next;
    }
    dum1=head1;
    while(dum1!=NULL){
        printf("%dx^%d+",dum1->data,dum1->power);
        dum1=dum1->next;
    }
    printf("\n");
    dum2=head2;
    while(dum2!=NULL){
        printf("%dx^%d+",dum2->data,dum2->power);
        dum2=dum2->next;
    }
    printf("=\n");
    tempp3=head3;
    while(tempp3!=NULL){
        printf("%dx^%d+",tempp3->data,tempp3->power);
        tempp3=tempp3->next;
    }

    return 0;
}
void polynomial(int value,int pp){
    struct Node*temp=head1;
    struct Node*newNode;
    newNode=(struct Node*)malloc((sizeof(struct Node)));
    newNode->data=value;
    newNode->power=pp;
    if(head1==NULL){
        newNode->next=NULL;
        head1=newNode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void polynomial2(int value2,int pp2){
    struct Node*temp2=head2;
    struct Node*newNode;
    newNode=(struct Node*)malloc((sizeof(struct Node)));
    newNode->data=value2;
    newNode->power=pp2;
    if(head2==NULL){
        newNode->next=NULL;
        head2=newNode;
    }
    else{
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=newNode;
    }
}
void polynomial3(int value3,int pp3){
    struct Node*temp3=head3;
    struct Node*newNode;
    newNode=(struct Node*)malloc((sizeof(struct Node)));
    newNode->data=value3;
    newNode->power=pp3;
    if(head3==NULL){
        newNode->next=NULL;
        head3=newNode;
    }
    else{
        while(temp3->next!=NULL){
            temp3=temp3->next;
        }
        temp3->next=newNode;
    }
}
