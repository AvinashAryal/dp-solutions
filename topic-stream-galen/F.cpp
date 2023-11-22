#include<bits/stdc++.h>

using namespace std;

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fk(i,k,n) for(int i = k;i < int(n);i++)
#define fr(i,k,n) for(int i = k;i >= int(n);i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define v2i(name,rows,cols,val) vector<vector<int>> name(rows,vector<int>(cols,val))
#define v2ll(name,rows,cols,val) vector<vector<ll>> name(rows,vector<ll>(cols,val))
#define v3i(name,x,y,z,val) vector<vector<vector<int>>> name(x,vector<vector<int>>(y,vector<int>(z,val)))
#define v3ll(name,x,y,z,val) vector<vector<vector<ll>>> name(x,vector<vector<ll>>(y,vector<ll>(z,val)))
#define get(a) for(auto &i:a) cin>>i;
#define get2d(a) for(auto &i:a) for(auto &j:i) cin>>j;
#define get3d(a) for(auto &i:a) for(auto &j:i) for(auto &k:j) cin>>k;
#define print(a) for(auto i: a){cout << i << " ";} cout << endl;
#define print2d(a) for(auto i: a){for(auto j: i) {cout << j << " ";} cout << endl;}
#define print3d(a) for(auto i: a) {for(auto j: i) {for(auto k: j) {cout << k << " ";} cout << endl;} cout << endl;}

#define pb push_back

const ll inf = 1e17 + 7;

void solve()
{
    ll n, k;
    cin >> n >> k;
    v2ll(C, n + 1, k + 1, 0);
    fk(i, 1, k + 1)
    {
        C[i][i] = 1;
    }
    fo(i, n + 1)
    {
        C[i][0] = 1;
    }
    fk(i, 1, n + 1)
    {
        fk(j, 1, k + 1)
        {
            if (j <= i)
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    vll ans(5);
    ans[1] = 1;
    //derangement D(n) is number of ways to arrange a permutation with exactly k elements out of place
    ans[2] = ans[1] + C[n][2] * 1; //D(n,2) = 1
    ans[3] = ans[2] + C[n][3] * 2; //D(n,3) = 2
    ans[4] = ans[3] + C[n][4] * 9; //D(n,4) = 9
    cout << ans[k] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
