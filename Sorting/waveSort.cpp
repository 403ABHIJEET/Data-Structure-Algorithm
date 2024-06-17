#include<iostream>
using namespace std;

void swap(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void waveSort(int arr[],int n) {
    for(int i=1; i<n; i+=2) {
        if(arr[i]>arr[i-1])
            swap(arr,i,i-1);
        if(arr[i]>arr[i+1]  && i<n-1) 
            swap(arr,i,i+1);
    }
}

int main() {
    int arr[] = {1,3,4,7,5,6,2};
    int n = 7;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    waveSort(arr,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}