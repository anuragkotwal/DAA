#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void Sort(int* arr, int n){
    int key,i,j;
    for(int i=1;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int BinarySearch(int* arr, int l, int h){
    int mid,comparison=0,flag=1;
    while(h>=l){
        comparison++;
        mid=(h+l)/2;
        if(arr[mid]==arr[mid+1]){
            flag=0;break;
        }else if(arr[mid]>arr[mid+1])
            h=mid-1;
        else if(arr[mid]<arr[mid+1])
            l=mid+1;
    }
    return flag;
}

int main()
{
    fastio;
    int t;
    ifstream file;
    file.open("input_3.txt");
    if(!file){
        cout<<"File not found";
        return 0;
    }
    file>>t;
    while(t--){
        int n;
        file>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
            file>>arr[i];
        Sort(arr,n);
        int flag=BinarySearch(arr,0,n-1);
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    file.close();
    return 0;
}