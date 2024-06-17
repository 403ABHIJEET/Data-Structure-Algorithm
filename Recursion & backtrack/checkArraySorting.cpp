#include<iostream>
using namespace std;

bool checkSorting(int arr[],int n,int s) {
    if(s==n-1)
        return true;
    if(arr[s]<=arr[s+1])
        checkSorting(arr,n,s+1);
    else
        return false;
}

int main() {
    int n = 8;
    int arr[] = {1,3,6,9,18,13,15,16};
    checkSorting(arr,n,0);
    if(checkSorting)
        cout<<"Array is Sorted"<<endl;
    else    
        cout<<"Array is not Sorted"<<endl;
    return 0;
}