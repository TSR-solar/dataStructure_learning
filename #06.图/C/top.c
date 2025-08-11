#include <stdio.h>
#include <stdlib.h>
#define N 200

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

int isFull(queue *q)
{
    return (q->rear+1) % N == q->front;
}

int isEmpty(queue *q)
{
    return q->front == q->rear;
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

int arcs[N][N] = {0};
int in[N] = {0};        // 结点的入度
int s[N] = {0};

int n = 0;

void init()
{
    int cnt = 0;
    scanf("%d%d", &n, &cnt);
    for(int i = 0; i < cnt; i++)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        arcs[p][q] = 1;
    } 
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            in[i] += arcs[j][i];
        }
    }
}

void top()
{
    queue *q = (queue*)malloc(sizeof(queue));
    initQueue(q);
    while(1)
    {
        for(int i = 0; i < n; i++)
        {
            if(in[i] == 0 && s[i] == 0)
            {
                s[i] = 1;
                push(q, i);
            }
        }

        if(isEmpty(q)) break;

        int *x = (int*)malloc(sizeof(int));
        pop(q, x);
        printf("%d ", *x);
        for(int i = 0; i < n; i++)
        {
            in[i] -= arcs[*x][i];
        }
    }
    printf("\n");
}

int main()
{
    init();
    top();
    return 0;
}

/*

input:
8 9
0 2
0 6
1 2
1 4
2 3
3 5
3 7
4 5
6 7

output:
0 1 6 2 4 3 5 7

*/