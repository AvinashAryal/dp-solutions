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
const ll mod = 1e9 + 7;

int dp[5005][5005];
int par[5005][5005];
vector<pair<ll, ll>> adj[5005];
ll n, m, T;

ll fnd(ll v, ll l) // returns the min time to get to vertex v with path length l
{
    if (l < 0)
    {
        return inf;
    }

    if (l == 0)
    {
        if (v == 0)
        {
            return 0;
        }

        return inf;
    }

    if (dp[v][l]  != -1)
    {
        return dp[v][l];
    }

    ll mn = inf;

    for (auto i : adj[v])
    {
        ll cost = i.second + fnd(i.first, l - 1);

        if (cost < mn)
        {
            mn = cost;
            par[v][l] = i.first;
        }
    }

    return dp[v][l] = min(T + 1, mn);
}

void solve()
{
    cin >> n >> m >> T;

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        adj[v].pb(make_pair(u, w));
    }

    fo(i, n)
    {
        fo(j, n)
        {
            dp[i][j] = -1;
        }
    }
    ll cur = 1;
    fo(i, n)
    {
        if (fnd(n - 1, i) <= T)
        {
            cur = i;
        }
    }
    cout << cur + 1 << endl;
    ll curpos = n - 1;
    vll ans;

    while (curpos != 0)
    {
        ans.pb(curpos + 1);
        curpos = par[curpos][cur];
        cur--;
    }

    ans.pb(1);
    reverse(ans.begin(), ans.end());
    print(ans);
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
