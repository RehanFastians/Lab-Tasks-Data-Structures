#include<bits/stdc++.h>
#define f(i,s,e) for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int main(){
    // int *arr;
    // int n;
    // cout<<"Enter size of array: ";
    // cin>>n;
    // arr = new int[n];
    // nl
    // cout<<"Enter elements : ";
    // f(i, 0, n)   cin>>arr[i];
    // nl
    // cout<<"Entered elements : ";
    // f(i, 0, n)  cout<<arr[i]<<' ';
    // delete[] arr;
    int **grid;
    int r, c;
    cout<<"Enter rows and columns of 2D array : ";
    cin>>r>>c;
    grid = new int*[r];
    f(i, 0, r){
        nl
        grid[i] = new int[c];
        cout<<"Enter elements of row "<<i+1<<": ";
        f(j, 0, c) cin>> grid[i][j];
    }
    cout<<"Entered matrix ";
    f(i, 0, r){
        nl
        f(j, 0, c)  cout<<grid[i][j]<<' ';
    }
    return 0;
}