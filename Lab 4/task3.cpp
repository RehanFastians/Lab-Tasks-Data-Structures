#include<bits/stdc++.h>
#define f(i, s, e)  for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int main(){
    string arr[] = {"banana", "apple", "cherry", "date", "grape"};
    f(i, 0, 5){
        f(j, 0, 5-i-1){
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    f(i, 0, 5)  cout<<arr[i]<<"  ";
}