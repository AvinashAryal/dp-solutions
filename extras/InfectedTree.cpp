#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long

using namespace std;

vector<vector<int>> adj(300005);
vector<int> child(300001,0);
vector<int> dp(300001,0); //dp[i] is the number of vertex that can be protected in the subtree with vertex "i" as root

void dfs(int x, int parent)
{
    vector<int> temp;
    for(auto i: adj[x])
    {
        if(i != parent) temp.push_back(i);
    }
    while(temp.size() < 2) temp.push_back(0);
    if(temp[0] != 0)dfs(temp[0],x);
    if(temp[1] != 0)dfs(temp[1],x);
    if(temp[0] != 0)child[x] += (child[temp[0]] + 1);
    if(temp[1] != 0)child[x] += (child[temp[1]] + 1);
    dp[x] = max(max(0,dp[temp[0]] + child[temp[1]]), dp[temp[1]] + child[temp[0]]); //for dp[x], temp[0] and temp[1] are child
    //we can either remove temp[0] and protect child[temp[0]] + dp[temp[1]]
    //or remvoe temp[1] and protect child[temp[1]] and dp[temp[0]] vertices
}

void solve() 
{
    memset(&child[0],0,sizeof(child[0])*child.size());
    memset(&dp[0],0,sizeof(dp[0])*dp.size());
    int n;
    cin >> n;
    fo(i,n+1)adj[i].clear();
    fo(i,n-1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    cout << dp[1] << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

