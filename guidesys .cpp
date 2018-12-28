#include <bits/stdc++.h>
using namespace std;
#define MaxVertexNum 100
typedef struct
{
    int num;
    string name;
    string features;
} VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType vexs[MaxVertexNum];
    EdgeType edges[MaxVertexNum][MaxVertexNum];
    int n, e;
} Graph;
int dis[MaxVertexNum][MaxVertexNum]; //储存最短路径
int pre[MaxVertexNum][MaxVertexNum]; //储存前驱结点
void create(Graph *G);              //建立图的储存结构
VertexType GetVex(Graph *G, int v);     //获取顶点
void PutVertex(Graph *G, int v);        //修改景点信息
void InsertVertex(Graph *G, VertexType v);  //插入景点
void DeleteVertex(Graph *G, int v);         //删除景点
void InsertArc(Graph *G, int v1, int v2, int w);    //插入道路
void DeleteArc(Graph *G, int v1, int v2);       //删除道路
void ShortestPath(Graph *G, int v);     //输出一个原点到其他所有景点的最短路径
void ToDestination(Graph *G, int v1, int v2); //两个景点之间的最短路径
int findIndex(Graph *G, int v); //有景点代号找到景点在矩阵中的储存位置
void printWay(Graph *G, int v1, int v2);   //打印出两点之间的最短路径
void Floyd(Graph *G);   //弗洛伊德算法
void printls(Graph *G); //打印景点列表
void printInf(Graph *G, int v); //打印景点信息
void printEdges(Graph *G); //打印所有道路
int main()
{
    Graph g;
    int mode, choice;
    while (1)
    {
        printf("1.管理员身份登陆\n"
               "2.游客身份登陆\n"
               "3.退出\n"
               "输入你的选择：");
        while (!scanf("%d", &mode))
            while (getchar() != '\n')
                ;
        system("cls");
        while (1)
        {
            if (mode == 1)
            {
                printf("（1） 创建图的邻接矩阵存储结构\n"
                       "（2） 浏览图中任一景点介绍\n"
                       "（3） 修改景点信息\n"
                       "（4） 增加景点信息\n"
                       "（5） 删除景点信息\n"
                       "（6） 增加道路\n"
                       "（7） 删除道路\n"
                       "（8） 查找某一景点到其他景点的最短路径\n"
                       "（9） 查找任一两个景点之间的最短路径\n"
                       "（10）退出登录\n");
                printf("输入一个整数:");
                cin >> choice;
                system("cls");
            }
            else if (mode == 2)
            {
                printf("（2） 浏览图中任一景点介绍\n"
                       "（8） 查找某一景点到其他景点的最短路径\n"
                       "（9） 查找任一两个景点之间的最短路径\n"
                       "（10）退出登录\n");
                printf("输入一个整数:");
                do
                {
                    cin >> choice;
                    if (!(choice == 2 || choice == 8 || choice == 9 || choice == 10))
                        printf("没有权限\n");
                } while (!(choice == 2 || choice == 8 || choice == 9 || choice == 10));
                system("cls");
            }
            else
                return 0;

            if (choice == 1)
                create(&g);
            else if (choice == 2)
            {
                printls(&g);
                int Ves;
                printf("请输入你想浏览的景点代号：");
                cin >> Ves;
                system("cls");
                printInf(&g, Ves);
                system("pause");
                system("cls");
            }
            else if (choice == 3)
            {
                int v;
                printls(&g);
                printf("输入你想修改的景点代号：");
                cin >> v;
                system("cls");
                PutVertex(&g, v);
            }
            else if (choice == 4)
            {
                VertexType v;
                cout << "新景点的名称：";
                cin >> v.name;
                cout << "新景点的简介:";
                cin >> v.features;
                cout << "输入顶点代号(请勿与其他顶点编号重复)：";
                cin >> v.num;
                system("cls");
                InsertVertex(&g, v);
            }
            else if (choice == 5)
            {
                printls(&g);
                int t;
                cout << "输入你想删除的景点代号:";
                cin >> t;
                DeleteVertex(&g, t);
                system("cls");
            }
            else if (choice == 6)
            {
                printls(&g);
                cout << "输入道路的起点代号 终点代号 长度，例如（1 2 200）：";
                int t1, t2, w;
                cin >> t1 >> t2 >> w;
                InsertArc(&g, t1, t2, w);
                system("cls");
            }
            else if (choice == 7)
            {
                printEdges(&g);
                cout << "要删除输入道路的起点代号 终点代号：";
                int t1, t2;
                cin >> t1 >> t2;
                DeleteArc(&g, t1, t2);
                system("cls");
            }
            else if (choice == 8)
            {
                int v;
                printls(&g);
                cout << "输入源点代号:";
                cin >> v;
                system("cls");
                ShortestPath(&g, v);
                system("pause");
                system("cls");
            }
            else if (choice == 9)
            {
                int v1, v2;
                printls(&g);
                cout << "输入起点与终点代号:";
                cin >> v1 >> v2;
                system("cls");
                ToDestination(&g, v1, v2);
                system("pause");
                system("cls");
            }
            else if (choice == 10)
                break;
        }
    }
    return 0;
}

void create(Graph *G)
{
    VertexType temp;
    int i, x, y, w;
    printf("输入景点个数：");
    cin >> G->n;
    for (int i = 0; i < G->n; i++) //初始化路径
    {
        for (int j = 0; j < G->n; j++)
        {
            if (i == j)
                G->edges[i][j] = 0;
            else
                G->edges[i][j] = INT_MAX;
        }
    }
    system("cls");
    for (i = 0; i < G->n; i++)
    {
        printf("代号:");
        cin >> temp.num;
        getchar();
        printf("名称:");
        cin >> temp.name;
        printf("简介:\n");
        cin >> temp.features;
        G->vexs[i] = temp;
        system("cls");
    }
    printf("输入路的条数:");
    cin >> G->e;
    for (i = 0; i < G->e; i++)
    {
        printls(G); //打印景点列表
        printf("输入起点代号,终点代号,路长（例如：1 5 3）：");
        while (scanf("%d %d %d", &x, &y, &w) != 3)
            printf("Re-Input:");
        y = findIndex(G, y); //在顶点集合中找到景点代号储存的位置
        x = findIndex(G, x);
        G->edges[x][y] = w;
        G->edges[y][x] = w;
        system("cls");
    }
    Floyd(G); //计算最优路径
    printf("成功！");
    system("pause");
    system("cls");
    fflush(stdin);
}
VertexType GetVex(Graph *G, int v) //打印景点信息,v为景点代号
{
    return G->vexs[findIndex(G, v)];
}
void PutVertex(Graph *G, int v)
{
    int i = findIndex(G, v); //在顶点集合中找到景点代号储存的位置
    if (G->vexs[i].num == v)
    {
        char j;
        string t;
        printf("是否修改名称？（Y/N）");
        fflush(stdin);
        j = getchar();
        if (j == 'Y' || j == 'y')
        {
            cout << "请输入新名称：";
            cin >> t;
            G->vexs[i].name = t;
        }
        printf("是否修改简介？（Y/N）");
        fflush(stdin);
        j = getchar();
        if (j == 'Y' || j == 'y')
        {
            cout << "请输入新的简介:" << endl;
            cin >> t;
            G->vexs[i].features = t;
        }
        system("cls");
        return;
    }
}
void InsertVertex(Graph *G, VertexType v)
{
    G->vexs[G->n] = v; //顶点
    G->n++;            //景点数加1
}
void InsertArc(Graph *G, int v1, int v2, int w)
{
    int x, y;
    y = findIndex(G, v1);
    x = findIndex(G, v2);
    G->edges[x][y] = w;
    G->edges[y][x] = w; //增加路径
    G->e++;
    Floyd(G);           //重新计算路径
}
void DeleteArc(Graph *G, int v1, int v2)
{
    v1 = findIndex(G, v1);
    v2 = findIndex(G, v2);
    G->edges[v1][v2] = INT_MAX; //路长设为无穷大即为删除路径
    G->edges[v2][v1] = INT_MAX;
    G->e--;
    Floyd(G); //重新计算路径
}
void Floyd(Graph *G)
{
    for (int i = 0; i < G->n; i++)
        for (int j = 0; j < G->n; j++)
        {
            dis[i][j] = G->edges[i][j]; //初始化最短路径
            pre[i][j] = j;
        }
    for (int k = 0; k < G->n; k++)
        for (int i = 0; i < G->n; i++)
            for (int j = 0; j < G->n; j++)
                if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pre[i][j] = pre[i][k];
                }
    return;
}
int findIndex(Graph *G, int v) //查找代号的位置
{
    for (int i = 0; i < G->n; i++)
    {
        if (G->vexs[i].num == v)
            return i;
    }
}
void printWay(Graph *G, VertexType v1, VertexType v2)
{

    int x = findIndex(G, v1.num);
    int y = findIndex(G, v2.num);
    while (x != y)
    {
        cout << G->vexs[x].name<<"--->";
        x = pre[x][y];
    }
    cout << v2.name << endl;
}
void ToDestination(Graph *G, int v1, int v2)
{
    v1 = findIndex(G, v1);
    v2 = findIndex(G, v2);
    if (dis[v1][v2] == INT_MAX)
    {
        cout << "无通路" << endl;
        system("pause");
        system("cls");
        return;
    }
    printf("最短路径长度为：%d\n", dis[v1][v2]);
    printWay(G, G->vexs[v1], G->vexs[v2]);
}
void ShortestPath(Graph *G, int v)
{
    v = findIndex(G, v);
    for (int i = 0; i < G->n; i++)
    {
        if (i == v)
            continue;
        else if (dis[v][i] == INT_MAX)
            cout << G->vexs[v].name << "到" << G->vexs[i].name << "无通路" << endl;
        else
        {
            cout << G->vexs[v].name << "到" << G->vexs[i].name << "的最短距离为" << dis[v][i] << endl;
            printWay(G, G->vexs[v], G->vexs[i]);
        }
    }
}
void printls(Graph *G)
{
    for (int i = 0; i < G->n; i++)
    {
        cout << G->vexs[i].num << " " << G->vexs[i].name << endl;
    }
}
void printInf(Graph *G, int v)
{
    VertexType t = GetVex(G, v);
    cout << "num:" << t.num << endl;
    cout << "name:" << t.name << endl;
    cout << "features:" << t.features << endl;
}
void DeleteVertex(Graph *G, int v)
{
    v = findIndex(G, v);
    for (int i = v; i < G->n; i++)
    {
        G->vexs[v] = G->vexs[v + 1]; //删除后调整结点
        G->edges[v][i] = G->edges[v + 1][i];
        G->edges[i][v] = G->edges[v + 1][i];
    }
    G->n--;
    Floyd(G); //重新计算最短路径
}
void printEdges(Graph *G) //打印所有路径
{
    for (int i = 0; i < G->n; i++)
    {
        for (int j = i + 1; j < G->n; j++)
        {
            if (G->edges[i][j] != INT_MAX)
            {
                cout << G->vexs[i].num << " " << G->vexs[i].name << "<--->" << G->vexs[j].num << " " << G->vexs[j].name << " " << G->edges[i][j] << endl;
            }
        }
    }
}