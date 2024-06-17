#include<iostream>
#include<algorithm>
using namespace std;

bool sum3(int a[],int n,int target) {
    sort(a,a+n);
    for(int i=0; i<n; i++) {
        int low = i+1;
        int high = n-1;
        while(low<high) {
            int curr = a[low]+a[i]+a[high];
            if(curr==target) 
                return true;
            else if(curr<target)
                low++;
            else    
                high--;
        }
    }
    return false;
}

int main() {
    int arr[] = {12,3,7,1,6,9};
    bool flag = sum3(arr,6,24);
    if(flag)
        cout<<"Availble"<<endl;
    else    
        cout<<"Not Availble"<<endl;
    return 0;
}