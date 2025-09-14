#include<bits/stdc++.h>
#define f(i, s, e)  for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int main(){
    int arr[]={20, 12, 15, 2, 10, 1, 13, 9, 5};
    f(i, 0, 9){
        f(j, i+1, 9){
            if(i==4){
                if(arr[i]<arr[j])   swap(arr[i], arr[j]);
            }else{
                if(arr[i]>arr[j])   swap(arr[i], arr[j]);
            }
        }
    }
    f(i, 0, 9)  cout<<arr[i]<<" ";
}