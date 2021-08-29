#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

bool isPathDFS(vector<vector<int>>& graphmat, int source, int des, int size){
    bool visited[size];
    stack<int> st;
    visited[source-1] = true;
    st.push(source-1);
    while(!st.empty()){
        int cr = st.top();
        st.pop();
        if(cr+1 == des)
                return true;
        for(int i=0;i<size;i++){
            if(graphmat[source][i] == 1 && !visited[i]){
               visited[i] = true;
               st.push(i);
            }
        }
    }
    return false;
}

int main()
{
    fastio;
    ifstream file;
    file.open("input_1.txt");
    if(!file){
        cout<<"File not found";
        return 0;
    }
    int v;
    file>>v;
    vector<vector<int>> graphmat(v,vector<int>(v));
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            file>>graphmat[i][j];
    int source,des;
    file>>source;
    file>>des;
    // cout<<(bool)dfs(graphmat,source,des,v)<<endl;
    if(isPathDFS(graphmat,source,des,v))
        cout<<"Yes path exixts"<<endl;
    else
        cout<<"No such path exixts"<<endl;
    // return 0;
}