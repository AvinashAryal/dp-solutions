#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long
const ll inf = 1e15;

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), prefix_sum(n+1,0);
    prefix_sum[0] = 0;
    fo(i,n)
    {
        cin >> a[i];
        prefix_sum[i+1] = prefix_sum[i] + a[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(n,inf));
    fo(i,n)
        fo(j,n)
        if(i == j) dp[i][j] = 0;
    for(int L = n-1;L >= 0;L--)
    {
        fok(R,L+1,n)
        {
            ll LR_sum = (prefix_sum[R+1] - prefix_sum[L]);
            fok(i,L,R)
            {
                dp[L][R] = min(dp[L][R],dp[L][i] + dp[i+1][R] + LR_sum);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}

