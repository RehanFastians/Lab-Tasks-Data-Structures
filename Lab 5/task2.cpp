#include<bits/stdc++.h>
#define f(i, s, e) for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

void guess(){
    static int num = rand()%100 + 1;
    int x;
    cout<<endl<<"Make ur guess : ";
    cin>>x;
    nl
    if(num==x){
        cout<<"Guessed it mubarak!";
        return;
    }else{
        if(num<x){
            cout<<"U guessed it high";
            guess();
        }else{
            cout<<"U guessed it low";
            guess();
        }
    }
}
int main(){
    srand(time(NULL));
    guess();
    return 0;
}