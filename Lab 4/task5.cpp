#include<bits/stdc++.h>
#define f(i, s, e)  for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int main(){
    int arr[]={2022, 2023, 2024, 2022, 2023, 2024};
    f(i, 0, 6){
        int pin = arr[i], j=i-1;
        while(j>=0 && arr[j]>pin){
            arr[j+1]=arr[j];
            j--;
        }   
        arr[j+1]=pin;
    }
    f(i, 0, 6){
        if(i)   cout<<", ";
        cout<<arr[i];
    }
}