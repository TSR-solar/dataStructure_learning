#include <stdio.h>
#include <stdlib.h>
#define N 200

int g1[N][N] = {0}; // directed graph
int g2[N][N] = {0}; // undirected graph

int s[N] = {0};

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

void init1(int g[N][N])
{
    int n; 
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        g[p][q] = 1;
    }
}

void init2(int g[N][N])
{
    int n; 
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        g[p][q] = g[q][p] = 1;
    }
}

void reset()
{
    for(int i = 0; i < N; i++)
    {
        s[i] = 0;
    }
}

void visit(int p)
{
    if(s[p] == 0)
    {
        printf("%d ", p);
        s[p] = 1;
    }
}

void dfs(int g[N][N], int p)
{
    visit(p);
    for(int i = 0; i < N; i++)
    {
        if(g[p][i] == 1 && s[i] == 0) 
        {
            dfs(g, i);
        }
    }
}

void bfs(int g[N][N], int p)
{
    queue *q = (queue*)malloc(sizeof(queue));
    initQueue(q);
    push(q, p);

    while(!isEmpty(q))
    {
        int *x = (int*)malloc(sizeof(int));
        pop(q, x);
        visit(*x);

        for(int i = 0; i < N; i++)
        {
            if(g[*x][i] == 1 && s[i] == 0)
            {
                push(q, i);
            }
        }
    }
}

int main()
{
    init1(g1);
    init2(g2);

    reset();
    printf("dfs for g1: ");
    dfs(g1, 0);
    printf("\n");

    reset();
    printf("dfs for g2: ");
    dfs(g2, 0);
    printf("\n");

    reset();
    printf("bfs for g1: ");
    bfs(g1, 0);
    printf("\n");

    reset();
    printf("bfs for g2: ");
    bfs(g2, 0);
    printf("\n");
    return 0;
}
/*
input:
4
0 1
0 2
2 3
3 1
6
0 1
0 2
0 3
1 2
2 3
2 4

output:
dfs for g1: 0 1 2 3
dfs for g2: 0 1 2 3 4
bfs for g1: 0 1 2 3
bfs for g2: 0 1 2 3 4

*/