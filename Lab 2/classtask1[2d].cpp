#include<bits/stdc++.h>
#define f(i,s,e) for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int main(){
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
    f(i, 0, r)  delete[] grid;
    delete[] grid;
    return 0;
}