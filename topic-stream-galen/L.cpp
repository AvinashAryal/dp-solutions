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

void solve()
{
    ll n;
    cin >> n;
    vector<array<ll, 3>> p(n);
    fo(i, n)
    {
        cin >> p[i][0];
        cin >> p[i][1];
        p[i][2] = i + 1 ;
    }
    ll k;
    cin >> k;
    vector<pair<ll, ll>> r(k);
    fo(i, k)
    {
        cin >> r[i].first;
        r[i].second = i + 1;
    }
    //it's always best to assign lower size table to lower size group, so let's sort both arrays
    sort(p.begin(), p.end());
    sort(r.begin(), r.end());
    //dp[i][j] is the max total money obtained from first i people using first j tables
    v2ll(dp, n + 1, k + 1, 0);
    //this parent array stores the parent to current state
    vector<vector<pair<ll, ll>>> prev(n + 1, vector<pair<ll, ll>> (k + 1, {-1, -1}));
    ll cnt = 0;
    fk(i, 1, n + 1)
    {
        fk(j, 1, k + 1)
        {
            if (r[j - 1].first >= p[i - 1][0])
            {
                //assign the current group to current table
                ll val = dp[i - 1][j - 1] + p[i - 1][1];

                if (val > dp[i][j])
                {
                    dp[i][j] = val;
                    prev[i][j] = {i - 1, j - 1};
                }
            }

            //don't assign this group to any table
            if (dp[i - 1][j] > dp[i][j])
            {
                prev[i][j] = {i - 1, j};
                dp[i][j] = dp[i - 1][j];
            }

            //don't assign this table to any group
            if (dp[i][j - 1] > dp[i][j])
            {
                prev[i][j] = {i, j - 1};
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    ll curx = n, cury = k;
    vector<pair<ll, ll>> ans;

    //iterating the parent array until we reach [-1][-1]
    while (make_pair(curx, cury) != make_pair(-1ll, -1ll))
    {
        if (prev[curx][cury] == make_pair(curx - 1, cury - 1))
        {
            if (curx != 0 && cury != 0)
            {
                //if we assigned one extra table to one extra group
                //include this value in the answer
                ans.pb({curx, cury});
            }
        }

        ll tx = prev[curx][cury].first;
        ll ty = prev[curx][cury].second;
        curx = tx;
        cury = ty;
    }

    cout << ans.size() << " " << dp[n][k] << endl;

    for (auto i : ans)
    {
        //recovering the actual indices from sorted array
        cout << p[i.first - 1][2] << " " << r[i.second - 1].second << endl;
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
