/*
 Question-1:
 Given an array of nonnegative integers, design a linear algorithm and implement it using a program
 to find whether a given key element is present in the array or not.
 Also, find the total number of comparisons for each input case.
 (Time Complexity = O(n), where n is the size of input).
 Input Format:
 n - no. of test cases
 next n lines:
 x - size of array
 a1 a2 a3 .... asize - x spaced non-negative integers
 key - key element to find
 Output Format:
 YES or NO - if key is present or absent
 comparisions - no. of comparisons made
 */

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    ifstream file;
    file.open("input.txt");
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
        int num;
        file>>num;
        int comparison=0,flag=0;
        for(int i=0;i<n;i++){
            comparison++;
            if(num == arr[i]){
                flag=1;
                break;
            }
        }     
        if(flag==1){
            cout<<"YES"<<endl;
            cout<<"Total comparison: "<<comparison<<endl;
        }
        else{
            cout<<"No"<<endl;
            cout<<"Total comparison: "<<comparison<<endl;
        }
    }   
    file.close(); 
    return 0;
}