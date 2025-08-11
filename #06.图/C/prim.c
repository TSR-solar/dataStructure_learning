#include <stdio.h>
#define N 200
#define INF 10000

int arcs[N][N] = {0};   // 邻接矩阵
int s[N] = {0};         // 结点是否加入
int p[N] = {0};
int min[N] = {0};
int road = 0;

void init(int g[N][N], int n, int cnt)
{
    for(int i = 0; i < cnt; i++)
    {
        int p, q, v;
        scanf("%d%d%d", &p, &q, &v);
        g[p][q] = g[q][p] = v;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(g[i][j] == 0) g[i][j] = INF;
        }
    }
}

void reset()
{
    for(int i = 0; i < N; i++)
    {
        s[i] = 0;
        p[i] = 0;
        min[i] = INF;
        road = 0;
    }
}

void prim(int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        min[i] = arcs[x][i];
    }

    s[x] = 1;
    for(int i = 0; i < n-1; i++)
    {
        int m = INF, t = -1;
        for(int j = 0; j < n; j++)
        {
            if(s[j])continue;
            if(min[j] < m) 
            {
                m = min[j];
                t = j;
            }
        }
        s[t] = 1;
        road += m;
        printf("%d %d\n", p[t], t);
        
        for(int j = 0; j < n; j++)
        {
            if(arcs[t][j] < min[j] && s[j] == 0)
            {
                min[j] = arcs[t][j];
                p[j] = t;
            }
        }  
    }
    printf("%d\n", road);
}

int main()
{
    int n, cnt;
    scanf("%d%d", &n, &cnt);
    init(arcs, n, cnt);

    reset();
    prim(0, n);

    return 0;
}
/*

input: 
6 10
0 1 6
0 2 1
0 3 5
1 2 5
1 4 3
2 3 5
2 4 6
2 5 4
3 5 2
4 5 6

output:
0 2
2 5
5 3
2 1
1 4
15

*/