#include<bits/stdc++.h>
#define f(i,s,e) for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int main(){
    int **grid;
    int r;
    cout<<"Enter rows for jacked array : ";
    cin>>r;
    grid = new int*[r];
    int *size = new int[r];
    f(i, 0, r){
        cout<<"Enter size of row "<<i+1<<" : ";
        cin>>size[i];
        grid[i] = new int[size[i]];
        cout<<"Enter elements of row "<<i+1<<": ";
        f(j, 0, size[i]) cin>> grid[i][j];
    }
    cout<<"Entered jacked array ";
    f(i, 0, r){
        nl
        f(j, 0, size[i])  cout<<grid[i][j]<<' ';
    }
    f(i, 0, r)  delete[] grid;
    delete[] grid;
    return 0;
}