#include <stdio.h>
#include <stdlib.h>

typedef struct maze
{
    struct maze* neighbours[4];//0左，1上，2右，3下
    int visited;//0表示没有访问，1表示访问过了
}maze;

void init_maze(maze* m)
{
    for (int i = 0; i < 4; i++)
    {
        m->neighbours[i] = NULL;
        m->visited = 0;
    }
}

maze** create_maze(int **graph,int m,int n)
{
    struct maze** mazes = (struct maze**)malloc((n*m) * sizeof(struct maze));
    int index = 0; //mazes的下标

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
            {
                if (j > 0 && graph[i][j-1] == 0)
                {
                    mazes[n * i + j]->neighbours[0] == mazes[n*i +j-1];
                }
                if (i > 0 && graph[i-1][j] == 0)
                {
                    mazes[n*i +j]->neighbours[1] == mazes[(n-1)*i + j];
                }
                if (j < n - 1 && graph[i][j+1] == 0)
                {
                    mazes[n*i +j]->neighbours[2] == mazes[n*i+j+1];
                }
                if (i < m - 1 && graph[i+1][j] == 0)
                {
                    mazes[n*i +j]->neighbours[3] == mazes[(n+1)*i + j];
                }
            }
        }
    }
    return mazes;
}

void find_path(maze** mazes, int m, int n,int index,int* result)
{
    for (int i = 0; i < 4; i ++)
    {
        if (mazes[index]->neighbours[i] != NULL || mazes[index]->neighbours[i]->visited == 0 )
        {
            mazes[index]->neighbours[i]->visited=1;
            if (i == 0)
            {
                find_path(mazes, m, n,index-1,result);

            }
            else if (i == 1)
            {
                find_path(mazes, m, n,index - n,result);
            }
            else if (i == 2)
            {
                find_path(mazes, m, n,index+1,result);
            }
            else
            {
                find_path(mazes, m, n,index+n,result);
            }
        }
    }
    if (index == m*n - 1)
    {
        *result ++;
    }
}

int main()
{
    //初始化迷宫
    int m,n;
    scanf("%d", &m);
    scanf("%d", &n);
    int **graph = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        graph[i] = (int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int result = 0;
    if (m == 1 && n == 1)
    {
        result = 1;
    }
    else if (graph[0][0] == 1 || graph[m-1][n-1] == 1)
    {
        result = 0;
    }

    maze** mazes = create_maze(graph,m,n);
    find_path(mazes,m,n,0,&result);
    printf("%d", result);


    return 0;
}
