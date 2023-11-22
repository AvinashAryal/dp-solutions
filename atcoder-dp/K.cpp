#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<bool> dp(k+1,false);// dp[i] is true if first player(Taro) wins in ith move
    vector<int> a(n);
    fo(i,n)
        cin >> a[i];
    fo(i,k+1)
    {
        for(auto f: a)
        {
            if(i >= f && !dp[i-f])
                dp[i] = true;
        }
    }
    cout << (dp[k]? "First" : "Second" ) << endl;
    return 0;
}


