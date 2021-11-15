#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

struct activity{
    int start,finish,index;
};

using namespace std;

bool activityComapator(activity act1, activity act2){
    return act1.finish < act2.finish;
}

void ActivitySelection(vector<activity> act){
    sort(act.begin(), act.end(), activityComapator);
    int preFin=-1;
    vector<int> ActSelected;
    for(auto i: act){
        if(i.start >= preFin){
            preFin=i.finish;
            ActSelected.push_back(i.index);
        }
    }
    cout<<"No. of non conflicting activities: "<<ActSelected.size()<<endl;
    cout<<"list of selected activities: ";
    for(auto i: ActSelected)
        cout<<i<<" ";
}

int main()
{
    fastio;
    ifstream file;
    file.open("input_1.txt");
    if(!file){
        cout<<"File not found!"<<endl;
        return 0;
    }
    int n;
    file>>n;
    vector<activity> act(n);
    for(int i=0;i<n;i++){
        file>>act[i].start;
        act[i].index = i+1;    
    } 
    for(int i=0;i<n;i++)
        file>>act[i].finish; 
    ActivitySelection(act);
    return 0;
}