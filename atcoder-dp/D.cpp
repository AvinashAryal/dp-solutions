#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long

using namespace std;

int main()
{
    int N,W;
    cin >> N >> W;
    vector<int> w(N),v(N);
    fo(i,N)
        cin >> w[i] >> v[i];
    vector<ll> dp(W+1,0); // dp[i] is the maximum sum of values for sum of weight exactly i
    fo(j,N)
    {
        for(int i = 0;i <= W;i++)
            if(i-w[j] >= 0) dp[i] = max(dp[i - w[j]] + v[j],dp[i]);
    }
    ll ans = 0;
    fo(i,W+1)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}


