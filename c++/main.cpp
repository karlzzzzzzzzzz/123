#include <bits/stdc++.h>
using namespace std;

int Map[31][31],v[31]={0};
int n,m,a,b;

void DFS(int x)
{
    if(v[x])
        return;
    printf("%d ",x);
    v[x]=1;
    for(int i=1;i<=n;i++)
        if(v[i]==0&&Map[x][i])
            DFS(i);
}

 int main()
 {

     while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(Map,0,sizeof(Map));
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            Map[a][b]=1;
            Map[b][a]=1;
        }
        for(int i=1;i<=n;i++)
            if(!v[i])
                DFS(i);
        printf("\n");
        memset(v,0,sizeof(v));

     }
     return 0;
 }
