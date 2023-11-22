#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> h(n+1);
    vector<long> dp(n+1,LONG_MAX); // dp[i] is the minimum cost to reach the position i
    dp[1] = 0;
    fok(i,1,n+1) cin >> h[i];
    fok(i,1,n+1) 
        fok(j,1,k+1)
           if(i-j > 0) dp[i] = min(dp[i],dp[i-j]+abs(h[i] - h[i-j]));
    cout << dp[n] << endl;
    return 0;
}
