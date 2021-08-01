#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void printArray(int* arr,int n){
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

void InsertionSort(int* arr, int n){
    int key,i,j,comparisons=0,shifts=0;
    for(int i=1;i<n;i++){
        shifts++;
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
            comparisons++;
            shifts++;
        }
        arr[j+1] = key;
    }
    printArray(arr,n);
    cout<<endl<<"Comparisons: "<<comparisons<<endl;
    cout<<"Shifts: "<<shifts<<endl;
}

int main()
{
    fastio;
    int t;
    ifstream file;
    file.open("input_1.txt");
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
        InsertionSort(arr,n);
    }
    file.close();
    return 0;
}