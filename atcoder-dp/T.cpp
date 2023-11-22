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
    int n;
    cin >> n;
    string s;
    cin >> s;
    v2ll(dp, n + 1, n + 1, 0);
    // dp[i][j] is the number of ways the number j at last, considering prefix of length i
    dp[1][1] = 1; //there is 1 way to put 1 as last number for prefix of length 1
    fk(pref_len, 2, n + 1) //prefix length
    {
        vll prefix_sum(pref_len, 0);
        fk(i, 1, pref_len)
        {
            prefix_sum[i] = (prefix_sum[i - 1] + dp[pref_len - 1][i]) % mod;
        }
        fk(cur_num, 1, pref_len + 1) //number placed at last
        {
            /*
            O(n^3 approach)
            fk(last_num, 1, pref_len) // number before current number
            {
                int real_last_num = last_num;

                //if we place a number less than last number at last position
                // then the previous number increases by 1
                // e.g [1, 2]
                // if we wish to place 2 at last for prefix length 3, then second number is increased by 1(becomes 3)
                if (last_num >= cur_num)
                {
                    real_last_num++;
                }

                if ((real_last_num < cur_num) == (s[pref_len - 2] == '<'))
                {
                    dp[pref_len][cur_num] = (dp[pref_len][cur_num] + dp[pref_len - 1][last_num]) % mod;
                }
            }
            to optimize this, consider [L, R] be the range of last_num which are added in this step above
            if we identify [L, R], we can optimize this solution by using prefix sums
            turns out, for '<' we add from 1 to cur_num-1
            for '>' we add from cur_num to pref_len-1
            */
            int L, R;

            if (s[pref_len - 2] == '<')
            {
                L = 1, R = cur_num - 1;
            }
            else
            {
                L = cur_num, R = pref_len - 1;
            }

            int to_add = prefix_sum[R] - prefix_sum[L - 1];

            if (to_add < 0)
            {
                to_add += mod;
            }

            dp[pref_len][cur_num] = (dp[pref_len][cur_num] + to_add) % mod;
        }
    }
    int ans = 0;
    fk(i, 1, n + 1)
    {
        ans = (ans + dp[n][i]) % mod;
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
