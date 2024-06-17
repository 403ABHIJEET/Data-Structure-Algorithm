#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r) {
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a1[n1];
    int a2[n2];
    for(int i=0; i<n1; i++) 
        a1[i] = arr[l+i];
    for(int i=0; i<n2; i++)
        a2[i] = arr[mid+1+i];
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2) {
        if(a1[i]<a2[j]) {
            arr[k] = a1[i];
            i++; 
        }
        else {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        arr[k] = a1[i];
        i++; k++;
    }
    while(j<n2) {
        arr[k] = a2[j];
        j++; k++;
    }
}

void mergeSort(int arr[],int l,int r) {
    if(l<r) {
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main() {
    int n = 9;
    int arr[] = {1,4,8,3,2,7,6,5,9};
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    mergeSort(arr,0,n-1);
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}