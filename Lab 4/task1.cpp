#include<bits/stdc++.h>
#define f(i, s, e)  for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int main(){
    int arr[10];
    cout<<"Enter 10 elements : ";
    f(i, 0, 10)  cin>>arr[i];
    nl
    f(i, 0, 10){
        int mini = i;
        f(j, i+1, 10){
            if(arr[j]<arr[i])   mini = j;
        }
        swap(arr[i], arr[mini]);
    }
    cout<<"The four min elements are : ";
    f(i, 0, 4)  cout<<arr[i]<<" ";
    return 0;
}