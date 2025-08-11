#include <stdio.h>
#include <stdlib.h>
#define N 2000

typedef struct 
{
    int elem[N];
    int front; 
    int rear;
} queue;

void initQueue(queue* q)
{
    q->front = q->rear = 0;
}

int isEmpty(queue *q)
{
    return q->front == q->rear;
}

int isFull(queue *q)
{
    return (q->rear+1) % N == q->front;
}

int push(queue *q, int x)
{
    if(isFull(q))return -1;
    
    q->elem[q->rear] = x;
    q->rear = (q->rear+1) % N;
    return 1;
}

int pop(queue *q, int *x)
{
    if(isEmpty(q))return -1;
    *x = q->elem[q->front];
    q->front = (q->front+1) % N;
    return 1;
}

int clearQueue(queue *q)
{
    if(q == NULL)return -1;
    free(q);
    return 1;
}

void input(queue *q)
{
    int n; 
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        push(q, tmp);
    }
}

void output(queue *q)
{
    int *x = (int*)malloc(sizeof(int));
    while(!isEmpty(q))
    {
        pop(q, x);
        printf("%d ", *x);
    }
    printf("\n");
}

int main()
{
    queue *q = (queue*)malloc(sizeof(queue));
    initQueue(q);
    input(q);
    output(q);
    clearQueue(q);
    return 0;
}
/*
input:
5
1 2 3 4 5

output:
1 2 3 4 5
*/