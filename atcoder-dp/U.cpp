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
const ll inf = 1e16 + 7;
int n;
vll dp; // dp[mask] is the max score that can be obtained by considering the items in this subset
vll score; // storing the score of every possible subset


void calc(ll l, vll& remaining, ll cur_score, ll mask, ll cur_group)
{
    /*
       l -> size of current subset among the remaining items
       remaining -> vector of indices of remaining rabbits
       cur_score -> score so far
       mask -> original mask
       cur_group -> subset mask for the remaining rabbits only
    */
    if (l ==  remaining.size()) // all items considered
    {
        //update the current mask and just return
        dp[mask] = max(dp[mask], cur_score + score[cur_group]);
        return;
    }

    // don't take the current item (lth item)
    calc(l + 1, remaining, cur_score, mask, cur_group);
    // take the lth item
    calc(l + 1, remaining, cur_score, mask ^ (1 << remaining[l]), cur_group ^ (1 << remaining[l]));
}

void solve()
{
    cin >> n;
    v2ll(adj, n, n, 0);
    get2d(adj);
    dp.resize((1 << n), -inf);
    score.resize((1 << n), 0);
    dp[0] = 0;
    // precalculating the score of groups of every subset
    fo(mask, (1 << n))
    {
        fo(i, n)
        {
            if (mask & (1 << i))
            {
                fk(j, i + 1, n)
                {
                    if (mask & (1 << j))
                    {
                        score[mask] += adj[i][j];
                    }
                }
            }
        }
    }
    // iterate through each subset
    fo(mask, (1 << n))
    {
        vll remaining;
        fo(i, n) // store the indices of rabbits not included in subset 'mask'
        {
            if (!(mask & (1 << i)))
            {
                remaining.pb(i);
            }
        }
        calc(0, remaining, dp[mask], mask, 0);
    }
    // answer is dp of mask containing all rabbits
    cout << dp[(1 << n) - 1] << endl;
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
