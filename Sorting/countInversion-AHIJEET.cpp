#include<iostream>
using namespace std;

int merge(int arr[],int l,int mid,int r) {
    int inv = 0;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int arr1[n1];
    int arr2[n2];
    for(int i=0; i<n1; i++) 
        arr1[i] = arr[l+i];
    for(int i=0; i<n2; i++)
        arr2[i] = arr[mid+i+1];
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2) {
        if(arr1[i]<=arr2[j]) {
            arr[k] = arr1[i];
            i++; k++;
        }
        else {
            arr[k] = arr2[j];
            j++; k++;
            inv += n1-i;
        }
    }
    while(i<n1) {
        arr[k] = arr1[i];
        i++; k++;
    }
    while(j<n2) {
        arr[k] = arr2[j];
        j++; k++;
    }
    return inv;
}

int mergeSort(int arr[],int l,int r) {
    int inv = 0;
    if(l<r) {
        int mid = (l+r)/2;
        inv += mergeSort(arr,l,mid);
        inv += mergeSort(arr,mid+1,r);
        inv += merge(arr,l,mid,r);
    }
    return inv;
}

int main() {
    int n; cin>>n;
    int arr[n];
    for(auto &i : arr)
        cin>>i;
    cout<<mergeSort(arr,0,n-1);
    return 0;
}