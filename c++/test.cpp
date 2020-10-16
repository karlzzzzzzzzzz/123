#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <bits/stdc++.h>


typedef struct ArcNode//�ڽӱ��еı߱���
{
    int vertex;//�����±�
    struct ArcNode *next;//ָ����һ���ڽӵ�
}ArcNode;

typedef struct//ͼ�ṹ
{
    ArcNode* head[21];//�ڽӱ�߱�ͷָ��
    int vNum;//������
    int eNum;//����
}Graph;

void CreateGraph(Graph& g)
{
    scanf("%d %d", &g.vNum, &g.eNum);
    for(int i=1; i<=g.vNum; i++) {
        g.head[i]=NULL;
    }

    for (int k = 0; k < g.eNum; k++) {
        int a,b;
        scanf("%d %d", &a, &b);
        if(g.head[a]==NULL)
        {
            //printf("1\n");
            ArcNode *ac = (ArcNode *) malloc(sizeof(ArcNode));
            ac->vertex=b;
            ac->next=NULL;
            g.head[a]=ac;
        }
        else
        {
            ArcNode *ac2 = (ArcNode *) malloc(sizeof(ArcNode));
            ac2->vertex=b;

            ArcNode *p1 = g.head[a],*q;
            while(p1)
            {
                if(p1->vertex>b)
                {
                    q=p1->next;
                    ac2->vertex=p1->vertex;
                    p1->vertex=b;
                    p1->next=ac2;
                    ac2->next=q;
                    break;
                }
                else if(p1->next==NULL)
                {
                    //printf("3\n");
                    p1->next=ac2;
                    ac2->next=NULL;
                }
                p1=p1->next;
            }
        }
    }
}

void PrintGraph(Graph& g)
{
    int i;
    for(i=1; i<=g.vNum; i++)
    {
        ArcNode *p = g.head[i];
        printf("%d", i);
        while(p)
        {
            printf("->%d", p->vertex);
            p = p->next;
        }
        printf("\n");
    }
}
int main()
{
    Graph g;
    CreateGraph(g);
    PrintGraph(g);
    return 0;
}
