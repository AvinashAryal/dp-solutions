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
const ll mod = 1e9 + 7;

ll n;

class Matrix
{
    public:
        vector<vector<ll>> a;
        Matrix()
        {
            a.resize(n, vector<ll>(n, 0));
        }
        Matrix(vector<vector<ll>> x)
        {
            this->a = x;
        }
        Matrix operator*(Matrix const& b)
        {
            Matrix c;
            fo(i, n)
            {
                fo(j, n)
                {
                    fo(k, n)
                    {
                        // by multiplying adjacency matrix with itself, we can get number of paths
                        // vaguely, it works as:
                        // no of paths from i to j is summed by number of paths from i to k multiplied by number of paths from k to j
                        c.a[i][j] = (c.a[i][j] + (a[i][k] * b.a[k][j]) % mod) % mod;
                    }
                }
            }
            return c;
        }
};

void solve()
{
    ll k;
    cin >> n >> k;
    v2ll(a, n, n, 0);
    get2d(a);
    Matrix adj = Matrix(a);
    Matrix ans;
    fo(i, n)
    {
        ans.a[i][i] = 1;
    }

    while (k) // binary exponentiation of adjacency matrix to achieve complexity of n^3*log(K)
    {
        if (k & 1)
        {
            ans = ans * adj;
        }

        adj = adj * adj;
        k /= 2;
    }

    ll paths = 0;
    fo(i, n)
    {
        fo(j, n)
        {
            paths = (paths + ans.a[i][j]) % mod;
        }
    }
    cout << paths << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
