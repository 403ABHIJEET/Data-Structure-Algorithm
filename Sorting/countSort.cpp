#include<iostream>
using namespace std;

void countSort(int arr[],int n) {
    int k = 0;
    for(int i=0; i<n; i++)
        k = max(k,arr[i]);
    int cnt[k+1]  = {0};
    for(int i=0; i<n; i++)
        cnt[arr[i]]++;
    for(int i=1; i<k+1; i++)
        cnt[i] += cnt[i-1];
    int output[n];
    for(int i=n-1; i>=0; i--)
        output[--cnt[arr[i]]] = arr[i];
    for(int i=0; i<n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {1,3,2,3,4,1,6,4,3};
    int n = 9;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    countSort(arr,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" "; 
    return 0;
}