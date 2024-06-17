#include<iostream>
#include<limits.h>
using namespace std;

int ones(int a[],int n,int k) {
    int ans = INT_MIN;
    int i = 0;
    int cntZero = 0;
    for(int j=0; j<n; j++) {
        if(a[i]==0)
            cntZero++;
        while(cntZero>k) {
            if(a[i]==0)
                cntZero--;
            i++;
        }
        ans = max(ans,j-i+1);
    }
}

int main() {
    int arr[] = {1,1,0,0,1};
    int n = 5;
    int k = 2;
    int ans = ones(arr,n,k);
    cout<<n<<endl;
    return 0;
}