#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long

const int m = 1e5 + 5;

using namespace std;

vector<int> adj[m],indegree(m,0),dp(m,0),vis(m,0); //dp[i] is the maximum length of path ending at vertex i

void dfs(int s)
{
    vis[s] = 1;
    for(int i: adj[s])
    {
        dp[i] = max(dp[i],dp[s]+1);
        indegree[i]--;
        if(indegree[i] == 0) dfs(i); //if all the incoming paths to vertex i are considered, only then we move forward
    }
}

int main()
{
    int ans = 0;
    int N,M;
    cin >> N >> M;
    int x,y;
    fo(i,M)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    fok(i,1,N+1)
    {
       if(!vis[i] && indegree[i] == 0) dfs(i); //longest path always starts from a vertex of indegree 0
    }
    fo(i,m) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
