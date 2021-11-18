#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

static int V=0;

bool Cycle(vector<vector<int>>& graph, int i, bool* visited,bool* stack){
    if(visited[i]){
        visited[i]=true;
        stack[i]=true;

        for(int j=0;j<V;j++)
            if(graph[i][j]==1)
                if(!visited[j] && Cycle(graph,j,visited,stack))
                    return true; 
                else if(stack[j])
                    return true;
    }
    stack[i] = false;
    return false;
}

bool IsCyclic(vector<vector<int>>& graph){
    bool visited[V];
    bool stack[V];

    for(int i=0;i<V;i++){
        visited[i] = false;
        stack[i] = false;
    }

    for(int i = 0; i < V;i++)
        if(Cycle(graph,i,visited,stack))
            return true;
    return false;
}

int main()
{
    fastio;
    ifstream file;
    file.open("input_3.txt");
    if(!file){
        cout<<"File not found";
        return 0;
    }
    file>>V;
    vector<vector<int>> graphmat(V,vector<int>(V,-1));
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            file>>graphmat[i][j];
    if(IsCyclic(graphmat))
        cout<<"Yes Cycle Exists"<<endl;
    else    
        cout<<"No Cycle Exists"<<endl;
    return 0;
}