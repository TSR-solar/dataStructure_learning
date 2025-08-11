#include <stdio.h>
#define N 100               // 最大顶点数
#define INF 10000           // 无穷

int arcs[N][N] = {0};       // 邻接矩阵
int path[N][N][N] = {0};    // 最短路径所含顶点
int n = 0;

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

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                path[i][j][k] = -1;
            }
        }
    }          
}

// 使用dijkstra算法计算start到其它顶点的最短路径
void dijkstra(int start)
{
    int dist[N] = {0};  // 最短路径长度
    int s[N] = {0};     // 顶点是否找到最短路径，是1否0
    s[start] = 1;       // 初始只有顶点start有最短路径

    // 通过n次循环设置arcs和path的初始值
    for(int i = 0; i < n; i++)
    {
        dist[i] = arcs[start][i];   // 将最短长度初始值设置成两顶点之间的弧长

        // 如果不是INF的话，就可以设置path的值
        if(dist[i] != INF)
        {
            // 起始点是它自己
            path[start][i][0] = start;

            // 如果最短路径不是自己和自己连的话，那么第二个点就是终结点了。
            if(i != start)
            {
                path[start][i][1] = i;
                path[start][i][2] = -1;
            }
            else
            {
                path[start][i][1] = -1;
            }
        }
    }

    // 进行n-1次循环，每次检索一个最短路径
    for(int i = 0; i < n-1; i++)
    {
        // k为可能要加入s的顶点下标，min为它的目前最短值
        int k = -1, min = INF;

        // 进行n次循环，找到k和min，然后加入s
        for(int j = 0; j < n; j++)
        {
            if(s[j] == 1)continue;    // 如果已经在s里面了就跳过
            if(dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        if(min < INF)s[k] = 1;  // 把INF放进去就说不过去了，那不等于没找吗！

        // 进行n次循环，利用顶点k更新当前最短路径
        for(int j = 0; j < n; j++)
        {
            if(s[j] == 1)continue;    // 如果已经在s里面了就跳过

            int tmp = dist[k] + arcs[k][j]; // 可能的新长度：k的最短路径 + k到j的弧

            // 如果比现在的短，就更新dist和path
            if(tmp < dist[j])
            {
                dist[j] = tmp;
                int l;
                for(l = 0; path[start][k][l] != -1; l++)
                {
                    path[start][j][l] = path[start][k][l];
                }
                path[start][j][l] = j;  
                path[start][j][l+1] = -1;  
            }
        }
    }

    // 将找不到最短路径的顶点path设置为只有它自己
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 0)
        {
            path[start][i][0] = i;
            path[start][i][1] = -1;
        }
    }
}

// 输出p到q的最短路径长度和所含顶点（p和q在里面输入）
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

    // 对每个顶点执行一次dijkstra算法
    for(int i = 0; i < n; i++)
    {
        dijkstra(i);
    }
    
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
0 3

output:
0 1 2
9
0 1 3
5

*/