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
    ll n, k, p;
    cin >> n >> k >> p;
    vll a(n), b(k);
    get(a);
    get(b);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    //the best possible assignment is without crossing paths between
    //reaching the key and reaching the destination
    //so, after we sort the arrays, the assignments will be in increasing order
    v2ll(dp, k + 1, n + 1, inf);
    //dp[i][j] is the minimum cost after assigning keys from first i keys
    //to the first j people
    fo(i, k + 1)
    {
        dp[i][0] = 0;
    }
    fk(i, 1, k + 1)
    {
        //since we can't take the same key twice, we should place keys first in the order
        fk(j, 1, n + 1)
        {
            //if we don't take the jth person for the ith key, the cost is same as assigning i-1 persons
            dp[i][j] = dp[i - 1][j];
            //if we take the jth person, the cost is
            dp[i][j] = min(dp[i][j], max(dp[i - 1][j - 1], abs(a[j - 1] - b[i - 1]) + abs(b[i - 1] - p)));
        }
    }
    cout << dp[k][n] << endl;
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
