#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define V 5
#define INF INT_MAX 

using namespace std;

void FloydWarshall(int dist[][V]){
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][j]>dist[i][k]+dist[k][j] 
                && (dist[k][j] !=INF && dist[i][k] != INF))
                    dist[i][j]=dist[i][k]+dist[k][j];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            if(dist[i][j] == INF)
                cout<<"INF"<<" ";
            else
                cout<<dist[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    fastio;
    int graph[V][V] = { {0,10,5,5,INF},
                        {INF,0,5,5,5},
                        {INF,INF,0,INF,10},
                        {INF,INF,INF,0,20},
                        {INF,INF,INF,5,0}};
    FloydWarshall(graph);
    return 0;

}