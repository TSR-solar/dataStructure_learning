// in-order thread
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2000

int cnt = 0;

typedef struct node
{
    char data;
    int Ltag, Rtag;
    struct node *lChild;
    struct node *rChild;
} node;

void init(node** n, char *str)
{
    char tmp = str[cnt];
    cnt++;
    if(tmp == '.')
    {
        *n = NULL;
        return;
    }
    *n = (node*)malloc(sizeof(node));
    (*n)->data = tmp;
    init(&((*n)->lChild), str);
    init(&((*n)->rChild), str);
}

node* pre = NULL;
void tag(node* n)
{
    if(n->lChild == NULL)
    {
        n->Ltag = 1;
        n->lChild = pre;
    }
    else
    {
        n->Ltag = 0;
    }

    if(pre != NULL && pre->rChild == NULL)
    {
        pre->Rtag = 1;
        pre->rChild = n;
    }
    else if(pre != NULL)
    {
        pre->Rtag = 0;
    }

    pre = n;
}

void thread(node *n)
{
    if(n != NULL)
    {
        thread(n->lChild);
        tag(n);
        thread(n->rChild);
    }
}

node* first(node* tree)
{
    node* p = tree;
    if(p == NULL)return NULL;

    while(p->Ltag == 0) p = p->lChild;
    return p;
}

void visit(node* n)
{
    printf("%c ", n->data);
}

node* next(node *n)
{
    if(n->Rtag == 1)return n->rChild;
    if(n->rChild == NULL)return NULL;
    
    node *p = NULL;
    for(node *q = n->rChild;; q = q->lChild)
    {
        p = q;
        if(q->Ltag == 1)break;
    }
    return p;
}

void traverse(node* tree)
{
    node* p = first(tree);
    while(p != NULL)
    {
        visit(p);
        p = next(p);
    }
}

int main()
{
    node* tree;
    char str[N] = {0};
    scanf("%s", str);
    init(&tree, str);
    thread(tree);
    traverse(tree);
    return 0;
}
/*
input:
ABD.G...CE.H..F..

output:
D G B A E H C F
*/