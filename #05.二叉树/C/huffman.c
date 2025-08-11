// the type of huffman: static tree
//
// The small weight will be put in the left child while the big one in the right.
// When encoding, the left is 0 and the right is 1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2000

char str[N] = {0};
char code[N] = {0};
char restr[N] = {0};

typedef struct 
{
    char data;
    int weight;
    int parent, lChild, rChild;
} node;

void input(char *a, int *w, int n)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    scanf("%s", str);
}

void init(node* tree, int n, char *a, int *w)
{
    for(int i = 0; i < 2*n-1; i++)
    {
        tree[i].data = 0;
        tree[i].lChild = -1;
        tree[i].rChild = -1;
        tree[i].parent = -1;
        tree[i].weight = 0;
    }

    for(int i = 0; i < n; i++)
    {
        tree[i].data = a[i];
        tree[i].weight = w[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        int l = N+1, r = N+1, pl = -1, pr = -1;
        for(int j = 0; j < n+i; j++)
        {   
            int tmp = tree[j].weight;
            if(tmp < l && tree[j].parent == -1)
            {
                r = l; pr = pl;
                l = tmp; pl = j;
            }
            else if(tmp < r && tree[j].parent == -1)
            {
                r = tmp; pr = j;
            }
        }

        tree[n+i].weight = tree[pl].weight + tree[pr].weight;
        tree[n+i].lChild = pl; tree[n+i].rChild = pr;
        tree[pl].parent = n+i; tree[pr].parent = n+i;
    }
}

void encode(node* tree, int n)
{     
    int slen = strlen(str);
    int clen = 0;
    for(int i = 0; i < slen; i++)
    {
        char tmp = str[i];
        int p=0, q=0;
        char part[N] = {0};
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(tree[j].data == tmp)
            { 
                p = j; break;
            }
        }

        while(q != 2*n-2)
        {
            q = tree[p].parent;
            if(tree[q].lChild == p)
            {
                part[cnt] = '0';
            }
            else if(tree[q].rChild == p)
            {
                part[cnt] = '1';
            }
            cnt++;
            p = q;
        }

        for(int j = cnt-1; j >= 0; j--)
        {
            code[clen] = part[j];
            clen++;
        }
    }
    // printf("%s\n", code);

    // printf("%s\n", str);
}

void decode(node* tree, int n)
{
    int clen = 0;
    int slen = 0;
    while(clen < strlen(code))
    {
        int p = 2*n-2; 
        while(p >= n)
        {
            char tmp = code[clen];
            if(tmp == '0')
            {
                p = tree[p].lChild;
            }
            else if(tmp == '1')
            {
                p = tree[p].rChild;
            }
            clen++;
        }
        restr[slen] = tree[p].data;
        slen++;
    }
    // printf("%s", restr);
}

void output()
{
    printf("%s\n%s", code, restr);

}

int main()
{
    node *tree = NULL;
    char a[N] = {0};
    int w[N] = {0};
    char c[N][N] = {0};
    int n;

    scanf("%d", &n);
    tree = (node*)malloc(sizeof(node) * (2*n-1));
    input(a, w, n);
    init(tree, n, a, w);
    encode(tree, n);
    decode(tree, n);
    output();
    return 0;
}
/*
input: 
5 a b c d e 12 40 15 8 25
bbbaddeccbbb

output:
00011111110111010110110000
bbbaddeccbbb
*/