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

const ll inf = 1e9 + 7;

ll find_mask(string s)
{
    // find the mask of a string
    // 001 -> A .... 111 -> ABC
    ll msk = 0, n = s.length();

    if (s.find("A") < n)
    {
        msk += 1;
    }

    if (s.find("B") < n)
    {
        msk += 2;
    }

    if (s.find("C") < n)
    {
        msk += 4;
    }

    return msk;
}

void solve()
{
    ll n;
    cin >> n;
    v2ll(dp, n, 8, inf);
    fo(i, n)
    {
        ll cost;
        cin >> cost;
        string s;
        cin >> s;
        ll mask = find_mask(s);

        if (i == 0)
        {
            dp[i][mask] = cost;
            continue;
        }

        dp[i] = dp[i - 1];
        dp[i][mask] = min(dp[i - 1][mask], cost); // update minimum cost for current mask
        fk(j, 1, 8)
        {
            //update the costs of all the strings that current mask affects
            // e.g. A updates A, AB, AC, ABC (all the strings obtained by ORing the mask)
            dp[i][j | mask] = min(dp[i][j | mask], dp[i - 1][j] + cost);
        }
    }
    cout << (dp[n - 1][7] >= inf ? -1 : dp[n - 1][7]) << endl;
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
