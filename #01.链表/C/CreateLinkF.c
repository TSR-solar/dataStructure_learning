#include <stdio.h>
#include <stdlib.h>
typedef struct tagNODE
{
    int data;
    struct tagNODE *next;
} node,*linklist;

void CreateLinkF(linklist L,int n)
{
    linklist p,s;
    int i;
    p=L;
    p->next=NULL;

    for(i=0;i<n;i++)
    {
        s=(linklist)malloc(sizeof(node));
        scanf("%d",&(s->data));

        s->next=p->next;
        p->next=s;
    }
}

void ListTrarse(linklist L)
{
    linklist p=L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void DestroyLink(linklist L)
{
    linklist p,q;
    p=L;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L=NULL;
}

int main()
{
    linklist L=NULL;
    int n;
    scanf("%d",&n);
    L=(linklist)malloc(sizeof(node));
    CreateLinkF(L,n);
    ListTrarse(L);
    printf("\n");
    DestroyLink(L);
    return 0;
}