#include <stdio.h>
#include <stdlib.h>
typedef struct tagNODE
{
    int data;
    struct tagNODE *next;
} node,*linklist;

void CreateLink(linklist L,int n)
{
    linklist p,s;
    int i;
    p=L;
    p->next=NULL;

    for(i=0;i<n;i++)
    {
        s=(linklist)malloc(sizeof(node));
        scanf("%d",&(s->data));

        p->next=s;
        p=s;
    }
    p->next=NULL;
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

int ListInsert(linklist s,linklist L,int i)
{
    linklist p=L;
    int t=0;
    while(p!=NULL&&t<i-1)
    {
        p=p->next;
        t++;
    }

    if(p==NULL||i<0)return 0;

    s->next=p->next;
    p->next=s;
    return 1;
}

int ListDelete(linklist L,int i)
{
    linklist p,q;
    int t=0;
    p=L;
    while(p!=NULL&&t<i-1)
    {
        p=p->next;
        t++;
    }

    if(p==NULL||i<0)return 0;

    q=p->next;
    p->next=q->next;
    q->next=NULL;
    printf("Deleted: %d\n",q->data);
    free(q);
    return 1;
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
    int n,i;
    L=(linklist)malloc(sizeof(node));
    scanf("%d",&n);
    CreateLink(L,n);
    ListTrarse(L);

    linklist s=NULL;
    s=(linklist)malloc(sizeof(node));
    s->next=NULL;
    printf("Enter a node's data:");
    scanf("%d",&(s->data));
    printf("Enter a number to insert:");
    scanf("%d",&i);

    if(ListInsert(s,L,i)!=1)
    {
        printf("Error in insert.\n");
        return 0;
    }
    ListTrarse(L);

    printf("Enter a number to delete:");
    scanf("%d",&i);

    if(ListDelete(L,i)!=1)
    {
        printf("Error in delete.\n");
    }
    ListTrarse(L);

    return 0;
}