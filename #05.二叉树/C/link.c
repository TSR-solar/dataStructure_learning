#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2000

int cnt = 0;

typedef struct node
{
    char data;
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

void visit(node* n)
{
    printf("%c ", n->data);
}

void preOrder(node* n)
{
    if(n != NULL)
    {
        visit(n);
        preOrder(n->lChild);
        preOrder(n->rChild);
    }
}

void inOrder(node* n)
{
    if(n != NULL)
    {
        inOrder(n->lChild);
        visit(n);
        inOrder(n->rChild);
    }
}

void postOrder(node* n)
{
    if(n != NULL)
    {
        postOrder(n->lChild);
        postOrder(n->rChild);
        visit(n);
    }
}

int leaf(node* n)
{
    if(n == NULL)return 0;
    else if(n->lChild == NULL && n->rChild == NULL) return 1;
    else return leaf(n->lChild)+leaf(n->rChild);
}

int depth(node* n)
{
    if(n == NULL)return 0;
    else if(n->lChild == NULL && n->rChild == NULL)return 1;
    else return (depth(n->lChild)>depth(n->rChild)?depth(n->lChild):depth(n->rChild))+1;
    // the max depth of two children + 1;
}

int main()
{
    node* tree;
    char str[N] = {0};
    scanf("%s", str);
    init(&tree, str);

    printf("preOrder: ");
    preOrder(tree);
    printf("\n");

    printf("inOrder: ");
    inOrder(tree);
    printf("\n");

    printf("postOrder: ");
    postOrder(tree);
    printf("\n");

    printf("The leaf(ves) in the tree: %d\n", leaf(tree));
    printf("The depth of the tree: %d\n", depth(tree));
    return 0;
}
/*
ABD..EH...CF.I..G..
*/