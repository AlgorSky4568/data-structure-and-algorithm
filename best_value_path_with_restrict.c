#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Point
{
    int num;
    int value;
    int weight;
    struct Point* next;
}Point;

typedef struct graph
{
    int V;
    Point** points;
}graph;

int max(int a,int b)
{
    return a>b?a:b;
}

graph* createGraph(int V,int point_value[])
{
    graph* g = (graph*)malloc(sizeof(graph));
    g->V = V;
    g->points = (Point**)malloc(sizeof(Point*) * (V+1)); //空出第0位
    for (int i = 1 ; i <= V ;i++)
    {
        g->points[i] = (Point*)malloc(sizeof(Point));
        g->points[i]->num = i;
        g->points[i]->value = point_value[i];
        g->points[i]->weight = 0;
        g->points[i]->next = NULL;
    }
    return g;
}

void buildEdge(graph* g,int start,int end,int weight,int point_value[])
{
    Point* new_point = (Point*)malloc(sizeof(Point));
    new_point->num = end;
    new_point->value = point_value[end];
    new_point->weight = weight;
    new_point->next = g->points[start]->next;
    g->points[start]->next = new_point;

}

int* topologicalSort(graph* g) {
    int V = g->V;
    int* indegree = (int*)calloc(V + 1, sizeof(int));  // 下标1..V
    int* result = (int*)malloc(V * sizeof(int));
    int count = 0;
    // 1. 计算入度
    for (int i = 1; i <= V; i++) {
        Point* cur = g->points[i]->next;
        while (cur) {
            indegree[cur->num]++;
            cur = cur->next;
        }
    }
    // 2. 初始化队列
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 1; i <= V; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }
    // 3. 拓扑排序
    while (front < rear) {
        int u = queue[front++];
        result[count++] = u;
        Point* cur = g->points[u]->next;
        while (cur) {
            int v = cur->num;
            if (--indegree[v] == 0) queue[rear++] = v;
            cur = cur->next;
        }
    }
    free(indegree);
    free(queue);
    if (count != V) {  // 有环
        free(result);
        return NULL;
    }
    return result;
}

int main(void)
{
    int point_num,edge_num,cost;
    scanf("%d %d %d",&point_num,&edge_num,&cost);
    int start_point,end_point;
    scanf("%d %d",&start_point,&end_point);
    int point_value[point_num+1];
    point_value[0] = 0;
    for (int i = 1;i<=point_num;i++)
    {
        scanf("%d",&point_value[i]);
    }

    int start,end,weight; //初始化图
    graph* g = createGraph(point_num,point_value);
    while (scanf("%d %d %d",&start,&end,&weight) == 3)
    {
        buildEdge(g,start,end,weight,point_value);
    }

    const int INF = -1e9;
    int** dp = (int**)malloc(sizeof(int*) * (point_num+1));
    for (int i = 0;i<point_num+1;i++)
    {
        dp[i] = (int*)malloc(sizeof(int) * (cost+1));
        for (int j = 0;j<cost+1;j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[start_point][0] = point_value[start_point];

    int* topo = topologicalSort(g);
    for (int i = 0;i<point_num;i++)
    {
        int u = topo[i];
        Point* temp = g->points[u]->next;
        while (temp)
        {
            int v = temp->num;
            int w = temp->weight;
            int val = temp->value;

            for (int j = 0; j <= cost - w;j++)
            {
                dp[v][j + w] = max(dp[v][j+w],dp[u][j]+val);
            }
            temp = temp->next;

        }
    }
    int result = 0;
    for (int i = 0;i<=cost;i++)
    {
        result = max(result,dp[end_point][i]);
    }
    printf("%d",result);
    free(dp);
    free(topo);
    return 0;

}