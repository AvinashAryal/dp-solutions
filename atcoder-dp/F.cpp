#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)

using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    vector<vector<int>> dp(s.length()+1,vector<int>(t.length() + 1, 0)); //dp[i][j] is the maximum length of subsequence until ith char of s and jth char of t
    vector<vector<pair<int,int>>> prev(s.length()+1,vector<pair<int,int>>(t.length()+1,make_pair(0,0))); // prev[i][j] is the coordinates (index_s,index_t) of the cell from which we came to (i,j) 
    fo(i,s.length())
    {
        fo(j,t.length())
        {
            if(s[i] == t[j]) 
            {
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                prev[i+1][j+1] = {i,j};
            }
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
            if(prev[i][j+1] != make_pair(i-1,j) && dp[i][j] > dp[prev[i][j+1].first][prev[i][j+1].second]) prev[i][j+1] = {i,j};
            if(prev[i+1][j] != make_pair(i,j-1) && dp[i][j] > dp[prev[i+1][j].first][prev[i+1][j].second]) prev[i+1][j] = {i,j};
        }
    }
    int ans = 0;
    pair<int,int> max = {0,0};
    fo(i,s.length()+1)
    {
        fo(j,t.length()+1)
        {
            if(dp[i][j] > ans)
            {
                ans = dp[i][j];
                max = {i,j};
            }
        }
    }
    string ans_str = "";
    int curr_r = max.first, curr_c = max.second;
    while(curr_r > 0 && curr_c > 0)
    {
        if(prev[curr_r][curr_c] == make_pair(curr_r-1,curr_c-1)) ans_str += t[curr_c-1];
        int tempr = prev[curr_r][curr_c].first;
        int tempc = prev[curr_r][curr_c].second;
        curr_r = tempr;
        curr_c = tempc;
    }
    reverse(ans_str.begin(),ans_str.end());
    cout << ans_str << endl;
    return 0;
}


