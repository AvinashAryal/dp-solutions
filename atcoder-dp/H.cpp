#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)

const int mod = 1e9 + 7;

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    vector<vector<long long>> dp(h,vector<long long>(w,0)); //dp[i][j] is the number of ways to reach cell (i,j)
    fo(i,h)
        fo(j,w)
            cin >> a[i][j];
    dp[0][0] = 1;
    fo(i,h)
        fo(j,w)
            if(a[i][j] != '#')
                dp[i][j] += (((j-1 < 0)? 0:dp[i][j-1]) + ((i-1 < 0)? 0:dp[i-1][j]))%mod;
    cout << dp[h-1][w-1] << endl;
    return 0;
}
