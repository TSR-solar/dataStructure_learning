#include <stdio.h>
#define N 100           // 最大顶点数
#define INF 10000       // 无穷

int arcs[N][N] = {0};       // 邻接矩阵
int dist[N][N] = {0};       // 最短路径长度
int path[N][N][N] = {0};    // 最短路径所含顶点
int n = 0;                  // 图的顶点数

// 输入n和邻接矩阵
void init()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arcs[i][j]);
        }
    }

    // 把path的值设置成-1（空）
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                path[i][j][k] = -1;
}

void floyd()
{
    // 通过n次循环设置arcs和path的初始值
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist[i][j] = arcs[i][j];    // 将最短长度初始值设置成两顶点之间的弧长

            // 如果不是INF的话，就可以设置path的值
            if(dist[i][j] != INF)
            {
                path[i][j][0] = i;      // 起始点是它自己

                // 如果最短路径不是自己和自己连的话，那么第二个点就是终结点了。
                if(i != j) path[i][j][1] = j;   
            }
        }
    }

    // 进行k*i*j次循环，更新dist和path
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int tmp = dist[i][k] + dist[k][j];  // 可能的更短路径长度

                // 如果更短，就更新dist和path
                if(tmp < dist[i][j]) 
                {
                    dist[i][j] = tmp;

                    int cnt = 0;
                    for(int l = 0; path[i][k][l] != -1; l++)
                    {
                        path[i][j][cnt] = path[i][k][l];
                        cnt++;
                    }
                    for(int l = 1; path[k][j][l] != -1; l++)
                    {
                        path[i][j][cnt] = path[k][j][l];
                        cnt++;
                    }
                }
            }
        }
    }

    // 将找不到最短路径的顶点path设置为只有它自己
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] == INF)
            {
                path[i][j][0] = i;
            }
        }
    }
}

void output()
{
    int t = 0;
    scanf("%d", &t);

    for(int _ = 0; _ < t; _++)
    {
        int p = -1, q = -1, dist = 0;
        scanf("%d%d", &p, &q);

        // 逐个输出path里面的顶点，输出到它自己时停止
        for(int i = 0;; i++)
        {
            printf("%d ", path[p][q][i]);
            if(path[p][q][i] == q)break;
            dist += arcs[ path[p][q][i] ] [ path[p][q][i+1] ];
        }
        printf("\n");
        printf("%d\n", dist);
    }
}

int main()
{
    init();
    floyd();
    output();
    return 0;
}
/*
input:
4
0 2 10 10000
2 0 7 3
10 7 0 6
10000 3 6 0
2
0 2
3 0

output:
0 1 2
9
3 1 0
5

*/