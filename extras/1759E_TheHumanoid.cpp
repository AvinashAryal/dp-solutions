#include<bits/stdc++.h>

using namespace std;

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fk(i,k,n) for(int i = k;i < int(n);i++)
#define fr(i,k,n) for(int i = k;i >= int(n);i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int> 
#define vll vector<long long> 
#define v2i(name,rows,cols,val) vector<vector<int>> name(rows,vector<int>(cols,val))
#define v2ll(name,rows,cols,val) vector<vector<ll>> name(rows,vector<ll>(cols,val))
#define v3i(name,x,y,z,val) vector<vector<vector<int>>> name(x,vector<vector<int>>(y,vector<int>(z,val)))
#define v3ll(name,x,y,z,val) vector<vector<vector<ll>>> name(x,vector<vector<ll>>(y,vector<ll>(z,val)))
#define get(a) for(auto &i:a) cin>>i;
#define get2d(a) for(auto &i:a) for(auto &j:i) cin>>j;
#define get3d(a) for(auto &i:a) for(auto &j:i) for(auto &k:j) cin>>k;
#define print(a) for(auto i: a){cout << i << " ";} cout << endl;
#define print2d(a) for(auto i: a){for(auto j: i) {cout << j << " ";} cout << endl;} 
#define print3d(a) for(auto i: a) {for(auto j: i) {for(auto k: j) {cout << k << " ";} cout << endl;} cout << endl;}

#define pb push_back

const int inf = 1e9 + 5;
const double err = 1e-6;

void solve()
{
    int n,h;
    cin >> n >> h;
    vi a(n);
    get(a);
    sort(a.begin(),a.end()); //sort the array
    v3ll(dp,n+1,3,2,0); //dp[i][j][k] denotes the maximum health until index i, using j green serums and k blue serums
    v2i(ans,3,2,0);
    fo(i,3)
        fo(j,2)
            dp[0][i][j] = h*pow(2,i)*pow(3,j); //calculate initial values
    fk(i,1,n+1)
    {
        fo(j,3)
        {
            fo(k,2)
            {
                fo(l,3)
                {
                    fo(m,2)
                    {
                        int mul = pow(2,j-l)*pow(3,k-m);
                        if(l <= j && m <= k) dp[i][j][k] = max(dp[i][j][k],dp[i-1][l][m]*mul); //transition from previous state consists of this
                        //e.g. dp[1][1][0] = max(dp[1][1][0],dp[0][1][0]*2^0*3^0, dp[0][0][0]*2^1*3^0)
                        //for dp[1][2][1] maximum of 6 values has to be written separately, so using this loops makes easier
                    }
                }
                if(dp[i][j][k] > a[i-1]) //if current value of maximum health for (j,k) is greater than a[i+1], increase it by a[i-1]/2 and update the answer for state (j,k)
                {
                    ans[j][k] = i;
                    dp[i][j][k] += (a[i-1]/2);
                }
                else //if not, the (j,k) state cannot proceed, so set its value to zero
                {
                    dp[i][j][k] = 0;
                }
            }
        }
    }
    int mx = 0; //answer is the maximum answers of all states
    fo(j,3)
        fo(k,2)
            mx = max(mx,ans[j][k]);
    cout << mx << endl;
    //printing ans[2][1] will also always work because its ans value is always maximum
    //cout << ans[2][1] << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
