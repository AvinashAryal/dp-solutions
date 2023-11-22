#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    fo(i,n) cin >> a[i];
    vector<vector<ll>> dp(3001, vector<ll>(3001,0)); //dp[i][j] is the value of X - Y for the interval (i,j) inclusive 
    for(int L = n-1; L >= 0;--L)
    {
        fok(R,L,n)
        {
            if(L == R) dp[L][R] = a[L];
            else dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}


