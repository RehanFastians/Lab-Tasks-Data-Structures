#include<bits/stdc++.h>
#define f(i, s, e) for(int i=0;i<e;i++)
#define nl cout<<endl;
using namespace std;
class JackedArray{
    string **sheet=nullptr;
    int rows=0;
    int* cols=nullptr;

    public:
    JackedArray(int r, int c[]){
        rows = r;
        cols = new int[rows];
        f(i, 0, rows)    cols[i]=c[i];
        sheet = new string*[rows];
        f(i, 0, rows)    sheet[i] = new string[cols[i]];
    }
    void setData(){
        cout<<"Enter names of attendees : ";
        f(i, 0, rows){
            cout<<"For row "<<i+1;
            nl
            f(j, 0, cols[i]){
                cout<<"Seat "<<j+1<<" :";
                cin>>sheet[i][j];
                nl
            }
        }
    }
    void displayData(){
        cout<<"\t --Sheet-- \t ";
        nl
        f(i, 0, rows){
            cout<<"Row "<<i+1<<": ";
            f(j, 0, cols[i]) cout<<sheet[i][j]<<"\t";
            nl
        }
    }
};
int main(){
    int seatsInRow[] = {3, 4, 2, 1};
    JackedArray tab(4, seatsInRow);
    tab.setData();
    tab.displayData();
    return 0;
}