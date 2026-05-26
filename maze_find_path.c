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

maze* create_maze(int **graph,int m,int n)
{
    maze* mazes = malloc((n*m) * sizeof(maze));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            init_maze(&mazes[n*i+j]);
            if (graph[i][j] == 0)
            {
                if (j > 0 && graph[i][j-1] == 0)
                {
                    mazes[n * i + j].neighbours[0] = &mazes[n*i +j-1];
                }
                if (i > 0 && graph[i-1][j] == 0)
                {
                    mazes[n*i +j].neighbours[1] = &mazes[(i-1)*n + j];
                }
                if (j < n - 1 && graph[i][j+1] == 0)
                {
                    mazes[n*i +j].neighbours[2] = &mazes[n*i+j+1];
                }
                if (i < m - 1 && graph[i+1][j] == 0)
                {
                    mazes[n*i +j].neighbours[3] = &mazes[(i+1)*n + j];
                }
            }
        }
    }
    return mazes;
}

void find_path(maze* mazes, int target,int index,int* result)
{
    if (index == target)
    {
        (*result) ++;
        return;
    }
    for (int i = 0; i < 4; i ++)
    {
        maze* neighbour = mazes[index].neighbours[i];
        if (neighbour && !neighbour->visited)
        {
            int neighbour_index = (int)(neighbour - mazes);
            find_path(mazes,target,neighbour_index,result);

        }
    }
    mazes[index].visited = 0;
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
    if (graph[0][0] == 1 || graph[m-1][n-1] == 1)
    {
        result = 0;
    }
    else if (m == 1 && n == 1)
    {
        result = 1;
    }
    else
    {
        maze* mazes = create_maze(graph,m,n);
        find_path(mazes,m*n -1,0,&result);
        free(mazes);
    }

    printf("%d", result);
    for (int i = 0; i < m; i++) free(graph[i]);
    free(graph);

    return 0;
}
