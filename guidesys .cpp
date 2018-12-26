#include <bits/stdc++.h>
#define MaxVertexNum 100
typedef struct
{
    int num;
    char name[100];
    char features[200];
} VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType vexs[MaxVertexNum];
    EdgeType edges[MaxVertexNum][MaxVertexNum];
    int n, e;
} Graph;
int dis[MAX][MAX]; //储存最短路径
int 
void create(Graph *G);
VertexType GetVex(Graph *G, int v);
void PutVertex(Graph *G,int v);
void InsertVertex(Graph *G, VertexType v);
void DeleteVertex(Graph *G, VertexType v);
void InsertArc(Graph *G, int v1,int v2, int w);
void DeleteArc(Graph *G, int v1, int v2);
void ShortestPath(Graph *G, int v);
void ToDestination(Graph *G, int v1, int v2);

int main()
{
    Graph g;
    create(&g);
    system("pause");
    return 0;
}

void create(Graph *G)
{
    VertexType temp;
    int i, x, y, w;
    char f = '\0';
    printf("输入景点个数：");
    while (!scanf("%d", &G->n))while (getchar() != '\n');
    for(int i=0;i<n;i++)    //初始化路径
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                G->edges[i][j] = 0;
            else
                G->edges[i][j] = INT_MAX;
        }
    }
    system("cls");
    for (i = 0; i < G->n; i++)
    {
        printf("代号:");
        while (!scanf("%d", &temp.num))
            while (getchar() != '\n')
                ;
        getchar();
        printf("名称:");
        fgets(temp.name, sizeof(temp.name), stdin);
        printf("简介:\n");
        fgets(temp.features, sizeof(temp.features), stdin);
        G->vexs[i] = temp;
        system("cls");
    }
    printf("输入路的条数:");
    while (!scanf("%d", &G->e))while (getchar() != '\n');
    for (i = 0; i < G->e; i++)
    {
        printf("输入起点代号,终点代号,路长（例如：1 5 3）：");
        while (scanf("%d %d %d", &x, &y, &w) != 3)
            printf("Re-Input:");
        for(int i = 0;i<G->n;i++)  //在顶点集合中找到景点代号储存的位置
        {
            if(G->vexs[i].num==y)
               {y = i;
               break;}
        }
        for(int i = 0;i<G->n;i++)  //在顶点集合中找到景点代号储存的位置
        {
            if(G->vexs[i].num==x)
               {x = i;
               break;}
        }

        G->edges[x][y] = w;
        G->edges[y][x] = w;
    }
    printf("成功！")
    system("cls");
    fflush(stdin);
}
VertexType GetVex(Graph *G, int v) //打印景点信息,v为景点代号
{
     for(int i = 0;i<G->n;i++)  //在顶点集合中找到景点代号储存的位置
        {
            if(G->vexs[i].num==v)
               {
                    return G->vexs[i];
               }
        }
}
void PutVertex(Graph *G,int v)
{
      for(int i = 0;i<G->n;i++)  //在顶点集合中找到景点代号储存的位置
        {
            if(G->vexs[i].num==v)
               {
                    char j,t[255];
                    printf("是否修改名称？（Y/N）")
                    j = getchar();
                    fflush(stdin);
                    system("cls");
                    if(j=='Y'||j=='y')
                    {
                        scanf("%s",t);
                        G->vexs[i].name = t;
                    }
                    printf("是否修改简介？（Y/N）")
                    j = getchar();
                    fflush(stdin);
                    system("cls");
                    if(j=='Y'||j=='y')
                    {
                        scanf("%s",t);
                        G->vexs[i].features = t;
                    }
                    printf("success");
                    return;
               }
        }
}
void InsertVertex(Graph *G, VertexType v)
{
    G->vex[n] = v;      //顶点
    G->n++;             //景点数加1
}
void InsertArc(Graph *G, int v1,int v2,int w)
{
    int x,y;
     for(int i = 0;i<G->n;i++)  //在顶点集合中找到景点代号储存的位置
        {
            if(G->vexs[i].num==v1)
               {
                    x = i;
                    break;
               }
        }
    for(int i = 0;i<G->n;i++)  //在顶点集合中找到景点代号储存的位置
        {
            if(G->vexs[i].num==v2)
               {
                    y = i;
                    break;
               }
        }
    G->edges[x][y] = w;
    G->edges[y][x] = w; //增加路径
}
void DeleteArc(Graph *G, int v1, int v2)
{
    G->edges[v1][v2] = INT_MAX; //路长设为无穷大即为删除路径
    G->edges[v2][v1] = INT_MAX;
}
void Floyd(Graph *G)
{

}