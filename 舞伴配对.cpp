#include <stdlib.h>
#include <stdio.h>
#define MAX  100

typedef struct
{
    int *base;
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue &Q)//初始化队列
{
    Q.base=(int*)malloc(MAX * sizeof(int));
    Q.front=Q.rear=0;
}

void EnQueue(SqQueue &Q,int e)//入队
{
    if((Q.rear+1) % MAX == Q.front)
    {
        exit(0);
    }
    Q.base[Q.rear]=e;
    Q.rear++;
}

void DeQueue(SqQueue &Q,int &e)//出队
{
    if(Q.front==Q.rear)
    {
        exit(0);
    }
    e=Q.base[Q.front];
    Q.front++;
}

void GetHead(SqQueue Q,int &e)//得到当前队列的头元素
{
    if(Q.front == Q.rear)
    {
        exit(0);
    }
    e=Q.base[Q.front];
}

void Party(SqQueue &Q1,SqQueue &Q2)//Q1和Q2队列元素进行配对
{
    int i,m,w,xm,ls,k;
    InitQueue(Q1);
    InitQueue(Q2);
    printf("请输入男舞伴人数\n");
    scanf("%d",&m);
    printf("请输入男舞伴号数\n");
    for(i=0; i<m; i++)
    {
        scanf("%d", &xm);
        EnQueue(Q1,xm);
    }
    printf("请输入女舞伴人数\n");
    scanf("%d",&w);
    printf("请输入女舞伴号数\n");
    for(i=0; i<w; i++)
    {
        scanf("%d", &xm);
        EnQueue(Q2,xm);
    }
    printf("请输入跳舞轮数\n");
    scanf("%d",&ls);
    if(m>w)
        k=w;
    else k=m;
    for(i=1; i<=ls; i++)
    {
        printf("第%d轮出场配对:\n",i);
        for(int j=0; j<k; j++)
        {
            DeQueue(Q1,m);
            DeQueue(Q2,w);
            printf("%d和%d\n",m,w);
            EnQueue(Q1,m);
            EnQueue(Q2,w);
        }
        if(i==ls)
        {
            GetHead(Q1,m);
            GetHead(Q2,w);
            printf("下一轮要配对的第一对舞伴是\n");
            printf("%d和%d\n",m,w);
        }
    }
}

int main()
{
    SqQueue Q1;
    SqQueue Q2;
    Party(Q1,Q2);
    return 0;
}
