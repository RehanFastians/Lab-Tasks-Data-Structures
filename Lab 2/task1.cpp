#include<bits/stdc++.h>
#define f(i,s,e) for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

class Matrix{
	int** values=nullptr;
	int rows=0;
	int cols=0;
	public:
	Matrix(int r, int c) : rows(r), cols(c){
		values = new int*[rows];
		f(i, 0, rows){
			cout<<"Enter Elements of Row "<<i+1<<" : ";
			values[i] = new int[cols];
			f(j, 0, cols)	cin>>values[i][j];
		}
	}
	~Matrix(){
		f(i, 0, rows)	delete[] values[i];
		delete[] values;
	}
	void resize(int nr, int nc){
		int **temp = new int*[nr];
		f(i, 0, min(nr, rows)){
			temp[i] = new int[nc];
			f(j, 0, min(nc, cols))	temp[i][j] = values[i][j];		
		}
		f(i, 0, rows)	delete[] values[i];
		delete[] values;
		values = temp;
		if(nr<=rows && nc<=cols){	
			rows = nr;
			cols = nc;
			return;
		}
		int x;
		cout<<"Enter the value to be filled in the extra positions : ";
		cin>>x;
		f(i, rows, nr){
			f(j, 0, nc)		values[i][j]=x;
		}
		f(j, cols, nc){
			f(i, 0, nr)		values[i][j]=x;
		}
	}
	void transpose(){
		int **temp = new int*[cols];
		f(i, 0, cols)	temp[i] = new int[rows];
		f(i, 0, rows){
			f(j, 0, cols)	temp[j][i]=values[i][j];
		}
		f(i, 0, rows)	delete[] values[i];
		delete[] values;
		values = temp;
	}
};
int main(){
	int n=5;
	int arr[n][n];
	f(i, 0, n){
		f(j, 0, n){
			nl
			cout<<"Enter element "<<i+1<<j+1<<": ";
			cin>>arr[i][j];
		}
	}
	cout<<"Entered matrix ";
	f(i, 0, n){
		nl
		f(j, 0, n){
			cout<<arr[i][j]<<' ';			
		}
	}
	return 0;
}