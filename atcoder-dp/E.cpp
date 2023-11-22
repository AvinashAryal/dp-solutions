#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long

const int inf = 1e9 + 5;

using namespace std;
int main()
{
    int N,W;
    cin >> N >> W;
    vector<int> w(N),v(N);
    ll sum = 0;
    fo(i,N)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    vector<ll> dp(sum+1,inf); //dp[i] is the minimum weight possible for the sum of values i 
    dp[0] = 0;
    fo(i,N)
        for(ll j = sum;j >= 0;j--)
            if(j-v[i] >= 0) dp[j] = min(dp[j],dp[j-v[i]] + w[i]);
    ll ans = 0;
    for(ll i = 0;i <= sum;i++)
        if(dp[i] <= W) ans = max(ans,i);
    cout << ans << endl;
    return 0;
}
