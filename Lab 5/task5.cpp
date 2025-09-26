#include<bits/stdc++.h>
#define f(i, s, e) for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;

int recursiveArraySum(int *arr[], int sizes[], int dim)
{
    static int i = 0;
    if(dim == 0)    return 0;
    if(i==sizes[dim-1]){
        i=0;
        return recursiveArraySum(arr, sizes, dim-1);
    }
    return arr[dim-1][i++] + recursiveArraySum(arr, sizes, dim);
}

int main()
{
    int dim = 3;
    int sizes[dim] = {2, 3, 1};
    int **arr = new int *[dim];
    int temp = 1;
    for (int i = 0; i < dim; i++)
    {
        arr[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
            arr[i][j] = temp++;
    }
    nl
    cout << "Array : " << endl;
    f(i, 0, dim)
    {
        f(j, 0, sizes[i])
            cout << arr[i][j] << " ";
        nl
    }
    nl
    cout << "Total Sum: " << recursiveArraySum(arr, sizes, dim) << endl;
    nl
    return 0;
}