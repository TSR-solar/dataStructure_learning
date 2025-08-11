#include <stdio.h>
#define N 200
#define INF 10000

int arcs[N][N] = {0};   // 邻接矩阵
int s[N] = {0};         // 结点集合
int n = 0;              // 结点个数
int road = 0;           // 最短路径长度

void init(int g[N][N], int cnt)
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
    for(int i = 0; i < n; i++)
    {
        s[i] = i;
    }
    road = 0;
}

int find(int x)
{
    if(s[x] == x) return x;
    else return find(s[x]);
}

int isRing(int p, int q)
{
    return find(p) == find(q);
}

void kruscal()
{
    for(int _ = 0; _ < n-1; _++)
    {
        int min = INF, p = -1, q = -1;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(arcs[i][j] < min)
                {
                    if(!isRing(i, j))
                    {
                        min = arcs[i][j]; p = i; q = j;
                    }
                } 
            }
        }

        s[find(q)] = p;

        road += min;
        printf("%d %d\n", p, q);
    }
    printf("%d\n", road);
}

int main()
{
    int cnt;
    scanf("%d%d", &n, &cnt);
    init(arcs, cnt);

    reset();
    kruscal();

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
3 5
1 4
2 5
1 2
15

*/