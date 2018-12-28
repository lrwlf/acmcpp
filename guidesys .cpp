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
int dis[MaxVertexNum][MaxVertexNum]; //�������·��
int pre[MaxVertexNum][MaxVertexNum]; //����ǰ�����
void create(Graph *G);              //����ͼ�Ĵ���ṹ
VertexType GetVex(Graph *G, int v);     //��ȡ����
void PutVertex(Graph *G, int v);        //�޸ľ�����Ϣ
void InsertVertex(Graph *G, VertexType v);  //���뾰��
void DeleteVertex(Graph *G, int v);         //ɾ������
void InsertArc(Graph *G, int v1, int v2, int w);    //�����·
void DeleteArc(Graph *G, int v1, int v2);       //ɾ����·
void ShortestPath(Graph *G, int v);     //���һ��ԭ�㵽�������о�������·��
void ToDestination(Graph *G, int v1, int v2); //��������֮������·��
int findIndex(Graph *G, int v); //�о�������ҵ������ھ����еĴ���λ��
void printWay(Graph *G, int v1, int v2);   //��ӡ������֮������·��
void Floyd(Graph *G);   //���������㷨
void printls(Graph *G); //��ӡ�����б�
void printInf(Graph *G, int v); //��ӡ������Ϣ
void printEdges(Graph *G); //��ӡ���е�·
int main()
{
    Graph g;
    int mode, choice;
    while (1)
    {
        printf("1.����Ա��ݵ�½\n"
               "2.�ο���ݵ�½\n"
               "3.�˳�\n"
               "�������ѡ��");
        while (!scanf("%d", &mode))
            while (getchar() != '\n')
                ;
        system("cls");
        while (1)
        {
            if (mode == 1)
            {
                printf("��1�� ����ͼ���ڽӾ���洢�ṹ\n"
                       "��2�� ���ͼ����һ�������\n"
                       "��3�� �޸ľ�����Ϣ\n"
                       "��4�� ���Ӿ�����Ϣ\n"
                       "��5�� ɾ��������Ϣ\n"
                       "��6�� ���ӵ�·\n"
                       "��7�� ɾ����·\n"
                       "��8�� ����ĳһ���㵽������������·��\n"
                       "��9�� ������һ��������֮������·��\n"
                       "��10���˳���¼\n");
                printf("����һ������:");
                cin >> choice;
                system("cls");
            }
            else if (mode == 2)
            {
                printf("��2�� ���ͼ����һ�������\n"
                       "��8�� ����ĳһ���㵽������������·��\n"
                       "��9�� ������һ��������֮������·��\n"
                       "��10���˳���¼\n");
                printf("����һ������:");
                do
                {
                    cin >> choice;
                    if (!(choice == 2 || choice == 8 || choice == 9 || choice == 10))
                        printf("û��Ȩ��\n");
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
                printf("��������������ľ�����ţ�");
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
                printf("���������޸ĵľ�����ţ�");
                cin >> v;
                system("cls");
                PutVertex(&g, v);
            }
            else if (choice == 4)
            {
                VertexType v;
                cout << "�¾�������ƣ�";
                cin >> v.name;
                cout << "�¾���ļ��:";
                cin >> v.features;
                cout << "���붥�����(�����������������ظ�)��";
                cin >> v.num;
                system("cls");
                InsertVertex(&g, v);
            }
            else if (choice == 5)
            {
                printls(&g);
                int t;
                cout << "��������ɾ���ľ������:";
                cin >> t;
                DeleteVertex(&g, t);
                system("cls");
            }
            else if (choice == 6)
            {
                printls(&g);
                cout << "�����·�������� �յ���� ���ȣ����磨1 2 200����";
                int t1, t2, w;
                cin >> t1 >> t2 >> w;
                InsertArc(&g, t1, t2, w);
                system("cls");
            }
            else if (choice == 7)
            {
                printEdges(&g);
                cout << "Ҫɾ�������·�������� �յ���ţ�";
                int t1, t2;
                cin >> t1 >> t2;
                DeleteArc(&g, t1, t2);
                system("cls");
            }
            else if (choice == 8)
            {
                int v;
                printls(&g);
                cout << "����Դ�����:";
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
                cout << "����������յ����:";
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
    printf("���뾰�������");
    cin >> G->n;
    for (int i = 0; i < G->n; i++) //��ʼ��·��
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
        printf("����:");
        cin >> temp.num;
        getchar();
        printf("����:");
        cin >> temp.name;
        printf("���:\n");
        cin >> temp.features;
        G->vexs[i] = temp;
        system("cls");
    }
    printf("����·������:");
    cin >> G->e;
    for (i = 0; i < G->e; i++)
    {
        printls(G); //��ӡ�����б�
        printf("����������,�յ����,·�������磺1 5 3����");
        while (scanf("%d %d %d", &x, &y, &w) != 3)
            printf("Re-Input:");
        y = findIndex(G, y); //�ڶ��㼯�����ҵ�������Ŵ����λ��
        x = findIndex(G, x);
        G->edges[x][y] = w;
        G->edges[y][x] = w;
        system("cls");
    }
    Floyd(G); //��������·��
    printf("�ɹ���");
    system("pause");
    system("cls");
    fflush(stdin);
}
VertexType GetVex(Graph *G, int v) //��ӡ������Ϣ,vΪ�������
{
    return G->vexs[findIndex(G, v)];
}
void PutVertex(Graph *G, int v)
{
    int i = findIndex(G, v); //�ڶ��㼯�����ҵ�������Ŵ����λ��
    if (G->vexs[i].num == v)
    {
        char j;
        string t;
        printf("�Ƿ��޸����ƣ���Y/N��");
        fflush(stdin);
        j = getchar();
        if (j == 'Y' || j == 'y')
        {
            cout << "�����������ƣ�";
            cin >> t;
            G->vexs[i].name = t;
        }
        printf("�Ƿ��޸ļ�飿��Y/N��");
        fflush(stdin);
        j = getchar();
        if (j == 'Y' || j == 'y')
        {
            cout << "�������µļ��:" << endl;
            cin >> t;
            G->vexs[i].features = t;
        }
        system("cls");
        return;
    }
}
void InsertVertex(Graph *G, VertexType v)
{
    G->vexs[G->n] = v; //����
    G->n++;            //��������1
}
void InsertArc(Graph *G, int v1, int v2, int w)
{
    int x, y;
    y = findIndex(G, v1);
    x = findIndex(G, v2);
    G->edges[x][y] = w;
    G->edges[y][x] = w; //����·��
    G->e++;
    Floyd(G);           //���¼���·��
}
void DeleteArc(Graph *G, int v1, int v2)
{
    v1 = findIndex(G, v1);
    v2 = findIndex(G, v2);
    G->edges[v1][v2] = INT_MAX; //·����Ϊ�����Ϊɾ��·��
    G->edges[v2][v1] = INT_MAX;
    G->e--;
    Floyd(G); //���¼���·��
}
void Floyd(Graph *G)
{
    for (int i = 0; i < G->n; i++)
        for (int j = 0; j < G->n; j++)
        {
            dis[i][j] = G->edges[i][j]; //��ʼ�����·��
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
int findIndex(Graph *G, int v) //���Ҵ��ŵ�λ��
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
        cout << "��ͨ·" << endl;
        system("pause");
        system("cls");
        return;
    }
    printf("���·������Ϊ��%d\n", dis[v1][v2]);
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
            cout << G->vexs[v].name << "��" << G->vexs[i].name << "��ͨ·" << endl;
        else
        {
            cout << G->vexs[v].name << "��" << G->vexs[i].name << "����̾���Ϊ" << dis[v][i] << endl;
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
        G->vexs[v] = G->vexs[v + 1]; //ɾ����������
        G->edges[v][i] = G->edges[v + 1][i];
        G->edges[i][v] = G->edges[v + 1][i];
    }
    G->n--;
    Floyd(G); //���¼������·��
}
void printEdges(Graph *G) //��ӡ����·��
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