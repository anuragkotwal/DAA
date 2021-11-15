#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void MajorityElementAndMedian(int* arr, int n){
    sort(arr,arr+n);
    int maxCount=0,i=-1;
    for(int j=0;j<n;j++){
        int count=0;
        for(int k=0;k<n;k++)
            if(arr[j] == arr[k])
                count++;
        if(maxCount<count){
            maxCount=count;
            i=j;
        }
    }
    if(maxCount>n/2)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    if(n%2!=0)
        cout<<arr[n/2]<<endl;
    else{
        int a=n/2;
        int b=a-1;
        int median=(arr[a]+arr[b])/2;
        cout<<median<<endl;
    }
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
    int n;
    file>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        file>>arr[i];
    MajorityElementAndMedian(arr,n);
    return 0;
}