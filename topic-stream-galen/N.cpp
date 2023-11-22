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

const ll inf = 1e10 + 7;

void solve()
{
    ll n, m;
    cin >> n >> m;
    v2ll(a, n, m, 0);
    get2d(a);
    v2ll(cost1, n, n, inf); // minimun absolute difference between elements of two rows(same column)
    v2ll(cost2, n, n, inf); // minimun absolute difference between elements of two rows(column k and k+1)
    //cost2 is used when moving from row n to row 0
    fo(i, n)
    {
        fo(j, n)
        {
            fo(k, m) cost1[i][j] = min(cost1[i][j], abs(a[i][k] - a[j][k]));
            fo(k, m - 1) cost2[i][j] = min(cost2[i][j], abs(a[i][k] - a[j][k + 1]));
        }
    }
    v3ll(dp, 1 << n, n, n, 0);
    //max difference when subset of rows used is represented by bitmast i
    //j as first row and last used row is row k
    fo(i, n)// not possible to use same first row and last row
    {
        dp[1 << i][i][i] = inf;
    }
    fk(mask, 1, (1 << n) - 1)
    {
        fo(i, n)
        {
            fo(j, n)
            {
                ll rowcnt = __builtin_popcountll(mask);

                //number of rows used
                if (rowcnt == 1 || i != j)
                {
                    // check to avoid using same row twice
                    if (mask & (1 << i)) // if row i is already used
                    {
                        if (mask & (1 << j)) // if row j is already used
                        {
                            fo(k, n) // new row to be used
                            {
                                if (!(mask & (1 << k))) // if row k is not used
                                {
                                    ll new_mask = mask | (1 << k); // use this row
                                    ll cost = min(dp[mask][i][j], cost1[j][k]);
                                    dp[new_mask][i][k] = max(dp[new_mask][i][k], cost);
                                    //maximize new state using max difference till now and max difference when between last row and new row
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    fo(i, n)
    {
        fo(j, n)
        {
            // now let's use cost2 for last row and first row
            // update using the state in which all except one row is used
            // first row is i and last row is j
            ans = max(ans, min(dp[(1 << n) - 1][i][j], cost2[i][j]));
        }
    }
    cout << ans << endl;
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
