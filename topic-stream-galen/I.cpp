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
    ll n, m, q;
    cin >> n >> m >> q;
    v2ll(a, n, m, 0);
    v2ll(conseq, n, m, 0); //consequetive 1's in row i ending at column j
    v2ll(dp, n, m, 0);//max consequetive 1's in row i so far
    get2d(a);
    fo(i, n)
    {
        ll mx = 0;
        fo(j, m)
        {
            if (j == 0)
            {
                conseq[i][j] = a[i][j];
            }
            else
            {
                conseq[i][j] = a[i][j] ? conseq[i][j - 1] + 1 : 0;
            }

            mx = max(mx, conseq[i][j]);
            dp[i][j] = mx;
        }
    }
    fo(i, q)
    {
        ll r, c;
        cin >> r >> c;
        --r;
        --c;
        a[r][c] ^= 1;
        ll ans = 0, mx = 0;
        //update conseq array for current row
        fo(j, m)
        {
            if (j == 0)
            {
                conseq[r][j] = a[r][j];
            }
            else
            {
                conseq[r][j] = a[r][j] ? conseq[r][j - 1] + 1 : 0;
            }

            mx = max(mx, conseq[r][j]);
            dp[r][j] = mx;
        }
        //check last colmn of each row, since that's where the max will be
        fo(k, n)
        {
            ans = max(ans, dp[k][m - 1]);
        }
        cout << ans << endl;
    }
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
