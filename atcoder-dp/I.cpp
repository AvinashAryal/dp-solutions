#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long double> dp(N + 1,0.0); // dp[i] is the prob of getting i heads after tossing current coin
    dp[0] = 1.0;
    for(int i = 1;i <= N;i++)
    {
        long double p;
        cin >> p;
        long double q = (1.0 - p);
        for(int j = i;j >= 0;j--)
        {
            long double temp = dp[j];
            if(j-1 >= 0) dp[j] = dp[j-1] * p;
            if(j == 0) dp[j] = temp * q;
            else dp[j] += temp * q;
        }
    }
    long double ans = 0.0;
    fok(i,N/2 + 1,N + 1)
        ans += dp[i];
    cout << setprecision(10) << ans << endl;
    return 0;
}


