#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)

using namespace std;

int main()
{
    int n,k;
    cin >> n;
    vector<vector<long>> abc(n,vector<long>(3));
    vector<vector<long>> dp(n+1,vector<long>(3,0)); //dp[i][j] is the minimum cost to reach position i if we choose jth activity now
    fo(i,n) 
        fo(j,3)
            cin >> abc[i][j];
    fo(i,3)
        dp[0][i] = abc[0][i];
    fok(i,1,n) 
    {
        dp[i][0] = max(dp[i-1][1] + abc[i][0],dp[i-1][2] + abc[i][0]);
        dp[i][1] = max(dp[i-1][0] + abc[i][1],dp[i-1][2] + abc[i][1]);
        dp[i][2] = max(dp[i-1][0] + abc[i][2],dp[i-1][1] + abc[i][2]);
    }
    long ans = 0;
    fo(i,3)
        ans = max(ans,dp[n-1][i]);
    cout << ans << endl;
    return 0;
}

