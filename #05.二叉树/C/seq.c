#include <stdio.h>
#include <stdlib.h>
#define N 2000

typedef struct
{
    int elem[N];
} tree;

void initTree(tree *t)
{
    for(int i = 0; i < N; i++)
    {
        t->elem[i] = -1;
    }
}

int parent(tree *t, int x)
{
    if(x == 1 || t->elem[x] == -1)return -1;
    return x/2;
}

int lChild(tree *t, int x)
{
    if(t->elem[x] == -1 || t->elem[2*x] == -1)return -1;
    return 2*x;
}

int rChild(tree *t, int x)
{
    if(t->elem[x] == -1 || t->elem[2*x+1] == -1)return -1;
    return 2*x+1;
}

void input(tree *t)
{
    int n; 
    scanf("%d", &n);
    for(int i = 1; i < n+1; i++)
    {
        scanf("%d", &(t->elem[i]));
    }
}

void traverse(tree *t, int cnt) // pre-order
{
    if(t->elem[cnt] == -1)return;
    printf("%d ", t->elem[cnt]);
    traverse(t, 2*cnt);
    traverse(t, 2*cnt+1);
}

int main()
{
    tree *t = (tree*)malloc(sizeof(tree));
    initTree(t);
    input(t);
    traverse(t, 1);
    return 0;
}
/*
input:
7
1 2 3 4 5 6 7

output:
1 2 4 5 3 6 7
*/