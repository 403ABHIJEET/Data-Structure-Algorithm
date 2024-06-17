#include<iostream>
using namespace std;

void swap(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void DNF(int arr[],int n) {
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<high) {
        if(arr[mid]==0) {
            swap(arr,mid,low);
            low++; mid++;
        }
        else if(arr[mid]==1)
            mid++;
        else {
            swap(arr,mid,high);
            high--;
        }
    }
}

int main() {
    int arr[] = {1,0,1,2,0,2,2,0,2,1,0,1,2,0,1,1,2,1};
    int n = 18;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    DNF(arr,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}