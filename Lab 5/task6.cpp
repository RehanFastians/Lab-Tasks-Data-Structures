#include<bits/stdc++.h>
#define f(i, s, e) for(int i=s;i<e;i++)
#define nl cout<<endl;
#define n 5
using namespace std;
int dx[]={0,0, 1, -1};
int dy[]={1, -1, 0, 0};
void solve(int maze[n][n], int i, int j, int sol[2][n*n], int soli, int visited[n][n]){
    f(k, 0, 4)
    {
        int ni = i + dy[k], nj = j + dx[k];
        if(ni >= n || nj>=n || ni<0 || nj<0 || maze[ni][nj]==0 || visited[ni][nj])    continue;
        visited[ni][nj]=1;
        sol[0][soli]=ni;
        sol[1][soli]=nj;
        solve(maze, ni, nj, sol, soli+1, visited);
        if(visited[n-1][n-1]){
            return;
        }
    }
}

int main()
{
    int sol[2][n*n];
    int visited[n][n]={0};
    visited[0][0]=1;
    int maze[n][n] = {{1, 0, 0, 0, 0},
                      {1, 1, 0, 1, 0},
                      {0, 1, 1, 1, 0},
                      {0, 0, 0, 1, 0},
                      {1, 1, 1, 1, 1}};
    sol[0][0]=0;
    sol[1][0]=0;
    solve(maze, 0, 0, sol, 1, visited);
    int i=0;
    if(visited[n-1][n-1]){
        do{
            cout<<"("<<sol[0][i]<<","<<sol[1][i]<<")->";
            i++;
        }while((sol[0][i]!=n-1 || sol[1][i]!=n-1 ) && visited[n-1][n-1]);
        cout<<"("<<n-1<<","<<n-1<<")";
    }else{
        cout<<endl<<"Reaching not possible!!";
    }
    return 0;
}