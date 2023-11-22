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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    get(a);
    vll dp(n, 0); //dp[i] = total no of zeros until i
    dp[0] = (a[0] == 0);
    fk(i, 1, n)
    {
        dp[i] = (dp[i - 1] + (a[i] == 0));
    }
    pair<ll, ll> best = {0, -1};
    fo(i, n)
    {
        ll leftsum = (i == 0 ? 0 : dp[i - 1]);
        ll l = i, r = n - 1, m, mx = l - 1;

        while (l <= r)
        {
            m = (l + r) / 2;

            if (dp[m] - leftsum <= k)
            {
                mx = max(m, mx);
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        if (mx - i  > best.second - best.first)
        {
            best = {i, mx};
        }
    }
    cout << best.second - best.first + 1 << endl;
    fo(i, n)
    {
        if (i >= best.first && i <= best.second)
        {
            a[i] = 1;
        }
    }
    print(a);
    //NON DP SOLUTION USING TWO-POINTERS
    // ll l = 0, r = 0, zerocnt = (a[0] == 0);
    // ll ans = 0, ansl, ansr;
    // fo(l, n)
    // {
    //     if (l > r)
    //     {
    //         r = l;
    //         zerocnt = (a[l] == 0);
    //     }
    //     while (r < n)
    //     {
    //         if (r + 1 < n && (zerocnt + (a[r + 1] == 0) <= k))
    //         {
    //             zerocnt += (a[r + 1] == 0);
    //             r++;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     //        cout << l << " " << r << " " << zerocnt << endl;
    //     if (r - l + 1 > ans && zerocnt <= k)
    //     {
    //         ans = (r - l + 1);
    //         ansl = l;
    //         ansr = r;
    //     }
    //     zerocnt -= (a[l] == 0);
    // }
    // cout << ans << endl;
    // fo(i, n)
    // {
    //     if (ans > 0 && i >= ansl && i <= ansr)
    //     {
    //         cout << 1 << " ";
    //     }
    //     else
    //     {
    //         cout << a[i] << " ";
    //     }
    // }
    // cout << endl;
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
