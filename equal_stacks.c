#include<stdio.h>
int high(int a,int b,int c){
    if(a>b && a>c){
        return 1;
    }
    else if(b>a && b>c){
        
        return 2;
    }
    else {
        return 3;
    }
}
int stacksum(int sum1,int sum2,int sum3,int top1,int top2,int top3,int stk1[],int stk2[],int stk3[]){
    while(!((sum1==sum2)&&(sum2==sum3))){
        int num=high(sum1,sum2,sum3);
        if(num==1){
            sum1=sum1-stk1[top1--];
        }
        else if(num==2){
            sum2=sum2-stk2[top2--];
        }
        else if(num==3){
            sum3=sum3-stk3[top3--];
        }
        else{
            return 0;
        }
    }
    return sum2;
    
}
int main(){
    int n1,n2,n3,i;
    int sum1,sum2,sum3;
    int var;
    int top1=-1,top2=-1,top3=-1;
    printf("Enter the number of elements of stack 1:");
    scanf("%d",&n1);
    int stk1[n1];
    for(i=0;i<n1;i++){
        scanf("%d",&var);
        top1++;
        stk1[top1]=var;
        sum1=sum1+var;
    }
    printf("Enter the number of elements of stack 2:");
    scanf("%d",&n2);
    int stk2[n2];
    for(i=0;i<n2;i++){
        scanf("%d",&var);
        top2++;
        stk2[top2]=var;
        sum2=sum2+var;
    }
    printf("Enter the number of elements of stack 3:");
    scanf("%d",&n3);
    int stk3[n3];
    for(i=0;i<n3;i++){
        
        scanf("%d",&var);
        top3++;
        stk3[top3]=var;
        sum3=sum3+var;
    }
    int ans=stacksum(sum1,sum2,sum3,top1,top2,top3,stk1,stk2,stk3);
    printf("The equal sum is :%d",ans);
    return 0;
}