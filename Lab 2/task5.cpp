#include<bits/stdc++.h>
#define f(i, s, e) for(int i=0;i<e;i++)
#define nl cout<<endl;
using namespace std;
class JackedArray{
    float **table=nullptr;
    int rows=0;
    int* cols=nullptr;

    string* rowidx=nullptr;
    public:
    JackedArray(int r, int c[], string ridx[]){
        rows = r;
        cols = new int[rows];
        f(i, 0, rows)    cols[i]=c[i];
        table = new float*[rows];
        f(i, 0, rows)    table[i] = new float[cols[i]];
        rowidx = new string[rows];
        f(i, 0, rows)   rowidx=ridx;
    }
    void setData(){
        f(i, 0, rows){
            cout<<"Enter grade points for Dept "<<rowidx[i];
            nl
            f(j, 0, cols[i]){
                cout<<"Course "<<j+1<<" :";
                cin>>table[i][j];
                nl
            }
        }
    }
    void displayData(){
        cout<<"Dept \t GradePoints ";
        nl
        f(i, 0, rows){
            cout<<rowidx[i]<<" ";
            float sum =0;
            f(j, 0, cols[i]){    cout<<table[i][j]<<" "; sum+=table[i][j];}
            cout<<"GPA = "<<sum/cols[i];
            nl
        }
    }
};
int main(){
    string rows[] = {"SE", "AI", "CS", "DS"};
    int course[] = {3, 4, 2, 1};
    JackedArray tab(4, course, rows);
    tab.setData();
    tab.displayData();
    return 0;
}