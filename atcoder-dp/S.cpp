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

void solve()
{
    string k;
    ll d;
    cin >> k;
    cin >> d;
    ll n = k.length();
    v3ll(dp, n + 1, d, 2, 0);
    // no of ways to get sum%d = j using first i digits
    //k = 0 indicates no previous digit is smaller than that in input number K
    //k = 1 indicates there is some previous digit smaller than that in input number K
    dp[0][0][0] = 1;
    fk(i, 0, n + 1)
    {
        fo(j, d)
        {
            fo(l, 2)
            {
                fo(dig, 10)
                {
                    //pull dp
                    if (i - 1 < 0)
                    {
                        continue;
                    }

                    //previous value needed to make current sum j
                    ll val = (j - dig);

                    while (val < 0)
                    {
                        val += d;
                    }

                    if (l == 0)
                    {
                        if (dig == k[i - 1] - '0')
                        {
                            dp[i][j][0] = (dp[i][j][0] + dp[i - 1][val][0]) % mod;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        if (dig < k[i - 1] - '0')
                        {
                            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][val][0]) % mod;
                        }

                        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][val][1]) % mod;
                    }

                    //push dp
                    // if (l == n)
                    // {
                    //     break;
                    // }
                    //  if (l == 0)
                    //  {
                    //      if (dig > k[i] - '0')
                    //      {
                    //          break;
                    //      }
                    //      if (dig < k[i] - '0')
                    //      {
                    //          dp[i + 1][(j + dig) % d][1] = (dp[i + 1][(j + dig) % d][1] + dp[i][j][l]) % mod;
                    //      }
                    //      else
                    //      {
                    //          dp[i + 1][(j + dig) % d][0] = (dp[i + 1][(j + dig) % d][0] + dp[i][j][l]) % mod;
                    //      }
                    //  }
                    //  else
                    //  {
                    //      dp[i + 1][(j + dig) % d][1] = (dp[i + 1][(j + dig) % d][1] + dp[i][j][l]) % mod;
                    //  }
                }
            }
        }
    }
    ll ans = (dp[n][0][0] + dp[n][0][1]) % mod;
    //we were also counting 00000
    ans -= 1;

    if (ans < 0)
    {
        ans += mod;
    }

    cout << ans << endl;
    //    cout << (dp[n - 1][0][0] + dp[n - 1][0][1]) %  mod << endl;
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
