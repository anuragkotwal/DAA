#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

struct tasks{
    int timeTaken,deadl,index;
};

using namespace std;

bool taskComparator(tasks a, tasks b){
    return a.deadl < b.deadl;
}

void Mintasks(vector<tasks> task){
    sort(task.begin(),task.end(),taskComparator);
    int dedl=0;
    vector<int> t;
    for(auto i:task){
        if(i.timeTaken+dedl <= i.deadl){
            dedl += i.timeTaken;
            t.push_back(i.index);
        }
    }
    cout<<"Max number of tasks: "<<t.size()<<endl;
    cout<<"Selected tasks numbers: ";
    for(auto i: t){
        cout<<i<<" ";
    }
}


int main()
{
    fastio;
    ifstream file;
    file.open("input_2.txt");
    if(!file){
        cout<<"File not found";
        return 0;
    }
    int n;
    file>>n;
    vector<tasks> task(n);
    for(int i=0;i<n;i++){
        file>>task[i].timeTaken;
        task[i].index=i+1;
    }
    for(int i=0;i<n;i++)
        file>>task[i].deadl;
    Mintasks(task);
    return 0;
}