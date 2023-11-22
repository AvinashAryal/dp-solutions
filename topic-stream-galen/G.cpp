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
    ll v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    v2ll(dp, t + 1, 1001, 0);
    //dp[i][j] is the max distance traveled in first i seconds if
    //the velocity at ith second is j
    dp[1][v1] = v1;
    fk(i, 2, t + 1)
    {
        fk(j, 1, 1001)
        {
            ll mx = 0;

            for (ll k = -d; k <= d; k++)
            {
                if (j + k > 0 && j + k <= 1000)
                {
                    mx = max(mx, dp[i - 1][j + k]);
                }
            }

            if (mx == 0)
            {
                //if it's not possible to get speed j at ith second
                continue;
            }

            dp[i][j] = mx + j;
        }
    }
    cout << dp[t][v2] << endl;
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
