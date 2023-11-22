#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long

using namespace std;

const int mod = 1e9 + 7;

vector<int> adj[100002];
vector<vector<long>> dp(100002,vector<long>(2,1)); 

void dfs(int x, int parent)
{
    for(int i: adj[x])
    {
        if(i != parent) {
            dfs(i,x);
            dp[x][0] = (dp[x][0] * dp[i][1]) % mod;
            dp[x][1] = (dp[x][1] * (dp[i][0] + dp[i][1])) % mod;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    fo(i,n-1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
    return 0;
}

