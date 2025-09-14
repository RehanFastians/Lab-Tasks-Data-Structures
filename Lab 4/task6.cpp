#include<bits/stdc++.h>
#define f(i, s, e)  for(int i=s;i<e;i++)
#define fn(i, s, e)  for(int i=s;i>=e;i--)
#define nl cout<<endl;
using namespace std;
void countSort(int arr[], int n, int rem){
    int cnt[10] ={0};
    f(i, 0, n){
        cnt[(arr[i]/rem)%10]++;
    }
    f(i, 1, 10)  cnt[i]+=cnt[i-1];
    int narr[n];
    fn(i, n-1, 0){
        narr[cnt[(arr[i]/rem)%10]-1] = arr[i];
        cnt[(arr[i]/rem)%10]--;
    }
    f(i, 0, n)  arr[i]=narr[i];
}

void radixSort(int arr[], int n){
    int maxv = *max_element(arr, arr+n);
    int rem=1;
    while(maxv/rem){
        countSort(arr, n, rem);
        rem*=10;
    }
}
int main(){
    int arr[]={452913, 100234, 987654, 123456, 987657};
    radixSort(arr, 5);
    f(i, 0, 5)  cout<<arr[i]<<" ";
}