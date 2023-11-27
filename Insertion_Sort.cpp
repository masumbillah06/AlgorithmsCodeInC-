#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define fo(i,a,n) for(int i=a;i<n;i++)

void insertionSort(vector<int> &arr) {
    int size = arr.size();
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(const vector<int> &arr) {
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(auto &it: arr) cin >> it;
    insertionSort(arr);
    printArray(arr);
    return 0;
}
