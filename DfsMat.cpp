#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &Matrix, int n, int i, int j, int newclr){
    if (i < 0 || j < 0 || i >= n || j >= n || Matrix[i][j] != 1)
        return;
    Matrix[i][j] = newclr;
    dfs(Matrix, n, i+1, j, newclr);
    dfs(Matrix, n, i-1, j, newclr);
    dfs(Matrix, n, i, j+1, newclr);
    dfs(Matrix, n, i, j-1, newclr);
}
void printMatrix(vector<vector<int>> &Matrix, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<vector<int>> Matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> Matrix[i][j];
        }
    }
    cout << "Enter the new color: ";
    int newclr;
    cin >> newclr;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(Matrix[i][j]==1){
                dfs(Matrix, n, i, j, newclr);
            }
        }
    }
    printMatrix(Matrix, n);
    return 0;
}