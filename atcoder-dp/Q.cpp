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
const ll mod = 1e9 + 7;

vll segtree;

ll query(ll index, ll l, ll r, ll cur_l, ll cur_r)
{
    if (l > cur_r || r < cur_l || l > r)
    {
        return 0;
    }

    if (l <= cur_l && r >= cur_r)
    {
        return segtree[index];
    }

    ll mid = (cur_l + cur_r) / 2;
    return max(query(index * 2, l, r, cur_l, mid), query(index * 2 + 1, l, r, mid + 1, cur_r));
}

void update(ll index, ll val, ll upd_index, ll cur_l, ll cur_r)
{
    if (upd_index == cur_l && upd_index == cur_r)
    {
        segtree[index] = val;
        return;
    }

    if (upd_index > cur_r || upd_index < cur_l)
    {
        return;
    }

    ll mid = (cur_l + cur_r) / 2;
    update(index * 2, val, upd_index, cur_l, mid);
    update(index * 2 + 1, val,  upd_index, mid + 1, cur_r);
    segtree[index] = max(segtree[index * 2], segtree[index * 2 + 1]);
}

void solve()
{
    ll n;
    cin >> n;
    ll sz = 1;

    while (sz < n + 1)
    {
        sz *= 2;
    }

    segtree.resize(2 * sz);
    fill(segtree.begin(), segtree.end(), 0);
    vll h(n), a(n), dp(n, 0);
    //dp[i] is the max beauty ending at index i
    get(h);
    get(a);
    fo(i, n)
    {
        // we need the maximum beauty among all previous flowers
        // with height less than h[i] i.e. [1, h[i] - 1]
        // let's use segment tree to find this in log(n)
        ll max_val = query(1, 0, h[i] - 1, 0, sz - 1);
        // max beauty ending at i is
        // max beauty ending at any previous index with lesser height
        dp[i] = max_val + a[i];
        // update dp[i] by adding current beauty
        update(1, dp[i], h[i], 0, sz - 1);
        // update the segment tree with dp[i]
    }
    ll ans = 0;
    fo(i, n)
    {
        //ans is max beauty among all possible ending indices
        ans = max(ans, dp[i]);
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
