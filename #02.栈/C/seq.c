#include <stdio.h>
#include <stdlib.h>
#define N 2000

typedef struct
{
    int elem[N];
    int top;
} stack;

void initStack(stack* s)
{
    s->top = -1;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

int isFull(stack *s)
{
    return s->top == N-1;
}

int push(stack* s, int x)
{
    if(isFull(s))return -1;
    
    s->top++;
    s->elem[s->top] = x;
    return 1;
}

int pop(stack *s, int *x)
{
    if(isEmpty(s))return -1;

    *x = s->elem[s->top];
    s->top--;
    return 1;
}

int getTop(stack *s, int *x)
{
    if(isEmpty(s))return -1;

    *x = s->elem[s->top];
    return 1;
}

int clearStack(stack *s)
{
    if(s == NULL)return -1;

    free(s);
    return 1;
}

void input(stack *s)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        push(s, tmp);
    }
}

void output(stack *s)
{
    int *x = (int*)malloc(sizeof(int));
    while (!isEmpty(s))
    {
        pop(s, x);
        printf("%d ", *x);
    }
    printf("\n");
}

int main()
{
    stack *s = (stack*)malloc(sizeof(stack));
    initStack(s);
    input(s);
    output(s);
    clearStack(s);
    return 0;
}
/*
input：
5
1 2 3 4 5

output:
5 4 3 2 1

*/