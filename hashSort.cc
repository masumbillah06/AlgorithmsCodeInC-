#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define fo(i,a,n) for(int i=a;i<n;i++)

const int N = 1e8;
vector<int> neg(N), pos(N);

int main()
{
    int n;
    cin >> n;

    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int zeros = 0;

    fo(i,0,n){
        int x; cin >> x;

        if(x<=minimum) minimum = x;
        if(x>=maximum) maximum = x;

        if(x<0){
            neg[abs(x)]++;
        } 
        else if(x>0){
            pos[x]++;
        }
        else zeros++;
    }

    for(int i=abs(minimum); i>0; i--){
        for(int j=0; j<neg[i]; j++){
            cout << (neg[i]*(-1)) << " ";
        }
    }
    for(int i=0; i<zeros; i++){
        cout << 0 << " ";
    }
    for(int i=1; i<=maximum; i++){
        for(int j=0; j<pos[i]; j++){
            cout << pos[i] << " ";
        }
    }
    cout << endl;

    return 0;
}