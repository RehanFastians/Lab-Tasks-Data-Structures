#include<bits/stdc++.h>
#define f(i, s, e)  for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int main(){
    int arr[]={2, 6, 4, 1, 2, 9, 8, 3, 4, 8};
    bool check =false;
    f(i, 0, 10){
        f(j, i+1, 10){
            if(arr[i]>arr[j])   swap(arr[i], arr[j]);
        }
        if(i &&  arr[i]==arr[i-1]) check =true;
    }
    if(check)   cout<<"Duplicates present";
    else cout<<"Duplicates not present";
    
}