#include<bits/stdc++.h>
#define f(i, s, e) for(int i=s;i<e;i++)
#define nl cout<<endl;
#define n 4
using namespace std;
void dfs( int col[], int diag1[], int diag2[], int i, int cnt, int &ans){
    if(i==n)    return;
    f(j, 0, n){
        if(col[j] || diag1[n-(j-i)-1] || diag2[i+j]) continue;
        col[j] = diag1[n-(j-i)-1] = diag2[i+j] = 1;
        ans = max(ans, cnt + 1);
        dfs(col, diag1, diag2, i+1, cnt+1, ans);
        col[j] = diag1[n-(j-i)-1] = diag2[i+j] = 0;
    }
}
int main(){
    int diag1[2*n-1] = {0};
    int diag2[2*n-1]={0};
    int col[n]={0};
    int ans =0;
    dfs(col, diag1, diag2, 0, 0, ans);
    cout<<"Max no. of flags that can be put in 4x4 grid is "<<ans;
    return 0;
}