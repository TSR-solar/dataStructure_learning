#include <stdio.h>
#include <stdlib.h>
#define N 200

int s[N] = {0};

typedef struct node
{
    int data;
    struct node *next;
} node;

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

void init1(node *g[N])
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < N; i++)
    {
        g[i] = (node*)malloc(sizeof(node));
        g[i]->next = NULL;
    }

    for(int i = 0; i < n; i++)
    {
        int m, n;
        scanf("%d%d", &m, &n);

        node *p = g[m];
        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = (node*)malloc(sizeof(node));
        p = p->next;
        p->data = n;
        p->next = NULL;
    }
}

void init2(node *g[N])
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < N; i++)
    {
        g[i] = (node*)malloc(sizeof(node));
        g[i]->next = NULL;
    }

    for(int i = 0; i < n; i++)
    {
        int m, n;
        scanf("%d%d", &m, &n);

        node *p  = NULL;
        p = g[m];
        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = (node*)malloc(sizeof(node));
        p = p->next;
        p->data = n;
        p->next = NULL;

        p = g[n];
        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = (node*)malloc(sizeof(node));
        p = p->next;
        p->data = m;
        p->next = NULL;
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

void dfs(node *g[N], int x)
{
    visit(x);
    
    node *p = g[x]->next;
    while(p != NULL)
    {
        if(!s[p->data]) dfs(g, p->data);
        p = p->next;
    }
}

void bfs(node *g[N], int x)
{
    queue *q = (queue*)malloc(sizeof(queue));
    initQueue(q);
    push(q, x);
    
    while(!isEmpty(q))
    {
        int *t = (int*)malloc(sizeof(int));
        pop(q, t);
        visit(*t);

        node *p = g[*t]->next;
        while(p != NULL)
        {
            if(!s[p->data]) push(q, p->data);;
            p = p->next;
        }
    }
}

int main()
{
    node *g1[N];
    node *g2[N];
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