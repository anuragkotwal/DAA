#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void printArray(int* arr, int n){
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

void SelectionSort(int* arr, int n){
    int comparisons=0,swaps=0;
    for(int i = 0; i < n-1; i++){
        swaps++;
        for(int j=i+1;j<n;j++){
            comparisons++;
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(arr,n);
    cout<<endl<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;
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
        SelectionSort(arr,n);
    }
    file.close();
    return 0;
}